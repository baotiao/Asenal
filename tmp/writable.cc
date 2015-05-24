#include "xdebug.h"
#include <string>
#include <stdint.h>
#include <assert.h>
#include <sys/time.h>

class PosixMmapFile {
    private:
        std::string filename_;
        int fd_;
        size_t page_size_;
        size_t map_size_;       // How much extra memory to map at a time
        char* base_;            // The mapped region
        char* limit_;           // Limit of the mapped region
        char* dst_;             // Where to write next  (in range [base_,limit_])
        char* last_sync_;       // Where have we synced up to
        uint64_t file_offset_;  // Offset of base_ in file

        // Have we done an munmap of unsynced data?
        bool pending_sync_;

        // Roundup x to a multiple of y
        static size_t Roundup(size_t x, size_t y) {
            return ((x + y - 1) / y) * y;
        }

        size_t TruncateToPageBoundary(size_t s) {
            s -= (s & (page_size_ - 1));
            assert((s % page_size_) == 0);
            return s;
        }

        bool UnmapCurrentRegion() {
            bool result = true;
            if (base_ != NULL) {
                if (last_sync_ < limit_) {
                    // Defer syncing this data until next Sync() call, if any
                    pending_sync_ = true;
                }
                if (munmap(base_, limit_ - base_) != 0) {
                    result = false;
                }
                file_offset_ += limit_ - base_;
                base_ = NULL;
                limit_ = NULL;
                last_sync_ = NULL;
                dst_ = NULL;

                // Increase the amount we map the next time, but capped at 1MB
                if (map_size_ < (1<<20)) {
                    map_size_ *= 2;
                }
            }
            return result;
        }

        bool MapNewRegion() {
            assert(base_ == NULL);
            if (ftruncate(fd_, file_offset_ + map_size_) < 0) {
                return false;
            }
            void* ptr = mmap(NULL, map_size_, PROT_READ | PROT_WRITE, MAP_SHARED,
                    fd_, file_offset_);
            if (ptr == MAP_FAILED) {
                return false;
            }
            base_ = reinterpret_cast<char*>(ptr);
            limit_ = base_ + map_size_;
            dst_ = base_;
            last_sync_ = base_;
            return true;
        }

    public:
        PosixMmapFile(const std::string& fname, int fd, size_t page_size)
            : filename_(fname),
            fd_(fd),
            page_size_(page_size),
            map_size_(Roundup(65536, page_size)),
            base_(NULL),
            limit_(NULL),
            dst_(NULL),
            last_sync_(NULL),
            file_offset_(0),
            pending_sync_(false) {
                assert((page_size & (page_size - 1)) == 0);
            }


        ~PosixMmapFile() {
            if (fd_ >= 0) {
                PosixMmapFile::Close();
            }
        }

        virtual bool Append(const char *data) {
            const char* src = data;
            size_t left = strlen(data);
            while (left > 0) {
                assert(base_ <= dst_);
                assert(dst_ <= limit_);
                size_t avail = limit_ - dst_;
                if (avail == 0) {
                    if (!UnmapCurrentRegion() || !MapNewRegion()) {
                        log_err("unmap current region fail or map new region fail");
                        return false;
                        //return IOError(filename_, errno);
                    }
                }

                size_t n = (left <= avail) ? left : avail;
                memcpy(dst_, src, n);
                dst_ += n;
                src += n;
                left -= n;
            }
            return true;
        }

        virtual bool Close() {
            bool s = false;
            size_t unused = limit_ - dst_;
            if (!UnmapCurrentRegion()) {
                log_err("unmap current region fail");
                s = false;
                // s = IOError(filename_, errno);
            } else if (unused > 0) {
                // Trim the extra space at the end of the file
                if (ftruncate(fd_, file_offset_ - unused) < 0) {
                    log_err("ftruncate file error");
                    s = false;
                    // s = IOError(filename_, errno);
                }
            }

            if (close(fd_) < 0) {
                log_err("close file error");
                s = false;
                // if (s.ok()) {
                //     s = IOError(filename_, errno);
                // }
            }

            fd_ = -1;
            base_ = NULL;
            limit_ = NULL;
            return s;
        }

        virtual bool Flush() {
            return true;
        }

        virtual bool Sync() {
            bool s = true;

            if (pending_sync_) {
                // Some unmapped data was not synced
                pending_sync_ = false;
                if (fdatasync(fd_) < 0) {
                    log_err("fsync error");
                    s = false;
                    // s = IOError(filename_, errno);
                }
            }

            if (dst_ > last_sync_) {
                // Find the beginnings of the pages that contain the first and last
                // bytes to be synced.
                size_t p1 = TruncateToPageBoundary(last_sync_ - base_);
                size_t p2 = TruncateToPageBoundary(dst_ - base_ - 1);
                last_sync_ = dst_;
                if (msync(base_ + p1, p2 - p1 + page_size_, MS_SYNC) < 0) {
                    log_err("msync file error");
                    s = false;
                    // s = IOError(filename_, errno);
                }
            }

            return s;
        }
};

bool NewWritableFile(const std::string& fname,
        PosixMmapFile** result) {
    bool s = true;
    const int fd = open(fname.c_str(), O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd < 0) {
        *result = NULL;
        log_err("open file error");
        s = false;
        // s = IOError(fname, errno);
    } else {
        *result = new PosixMmapFile(fname, fd, getpagesize());
        qf_debug("open success");
    }
    return s;
}

int64_t NowMicros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<uint64_t>(tv.tv_sec) * 1000000 + tv.tv_usec;
}

#define TIME_NUM 100000
int main()
{

    _debug_time_def;
    const char *filename = "/home/chenzongzhi/c/test_file";
    PosixMmapFile *result;
    bool ret = NewWritableFile(filename, &result);
    int64_t st = NowMicros();
    char input[10000] = {'a'};
    memset(input, '1', sizeof(input));
    
    for (int i = 0; i < TIME_NUM; i++) {
        result->Append(input);
    }
    int64_t ed = NowMicros();
    qf_debug("start time %lld", st);
    qf_debug("mmap cost time %lld", ed - st);
    qf_debug("ed time %lld", ed);
    result->Close();

    const char *filename1 = "/home/chenzongzhi/c/test_file1";

    FILE *fout;
    fout = fopen(filename1, "a+");
    st = NowMicros();
    for (int i = 0; i < TIME_NUM; i++) {
        fwrite(input, 1, 10000, fout);
    }
    ed = NowMicros();
    qf_debug("fwrite cost time %lld", ed - st);

    const char *filename2 = "/home/chenzongzhi/c/test_file2";
    int fdout;
    if ((fdout = open(filename2, O_RDWR | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU | S_IRWXG | S_IRWXO)) < 0) {
        log_err("fout open file error");
    }
    st = NowMicros();
    for (int i = 0; i < TIME_NUM; i++) {
        write(fdout, input, 10000);
    }
    ed = NowMicros();
    qf_debug("write cost time %lld", ed - st);

    sentinel("here");
    return 0;

error:
    return 1;
}
