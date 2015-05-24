/**
 * @file slice.h
 * @brief pratice for c++
 * @author chenzongzhi
 * @version 1.0.0
 * @date 2013-06-03
 */
#ifndef LD_INCLUDE_SLICE_H_
#define LD_INCLUDE_SLICE_H_

#include <assert.h>
#include <string>
#include <string.h>

namespace ld {
    class Slice {
        public:
            Slice() : data_(""), size_(0) {}

            Slice(const char* d, size_t n) : data_(d), size_(n) {}
            
            Slice(const std::string& s) { data_ = s.data(); size_ = s.size(); } 

            Slice(const char* s) { data_ = s; size_ = strlen(s); }

            ~Slice() {}

            Slice(const Slice& rhs) { printf("call the copy operator\n"); data_ = rhs.data_; size_ = rhs.size_;}

            Slice& operator=(const Slice& rhs) { printf("call the copy assign operator\n"); data_ = rhs.data_; }

            std::string ToString() const { return std::string(data_, size_); }

            size_t size() const { return size_; }

            const char* data() const { return data_; }

            bool empty() const { return size_ == 0; }

            char operator[](size_t n) const { assert(n < size()); return data_[n]; }

            void clear() { data_ = ""; size_ = 0; }

            int compare(const Slice& rhs) const;

            bool starts_with(const Slice& rhs) const;


        private:
            const char* data_;
            size_t size_;

    };

    inline bool operator==(const Slice& x, const Slice& y) {
        return x.size() == y.size() && (memcmp(x.data(), y.data(), x.size()) == 0);
    }

    inline bool operator!=(const Slice& x, const Slice& y) {
        return !(x == y);
}

#endif

