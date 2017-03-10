#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <string>
#include <sys/stat.h>
#include <dirent.h>
#include <vector>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int GetChildren(const std::string& dir, std::vector<std::string>& result) {
  int res = 0;
  result.clear();
  DIR* d = opendir(dir.c_str());
  if (d == NULL) {
    return errno;
  }
  struct dirent* entry;
  while ((entry = readdir(d)) != NULL) {
    if (strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".") == 0) {
      continue;
    }
    result.push_back(entry->d_name);
  }
  closedir(d);
  return res;
}


int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("Usage: ./rock_page rocksdb_dir\n");
    return -1;
  }
  std::string dir(argv[1]);

  std::vector<std::string> files;
  GetChildren(dir, files);

  std::string sst("sst");
  int tot_cache = 0;
  for (int i = 0; i < files.size(); i++) {
    if (files[i].compare(files[i].length() - sst.length(), sst.length(), sst) != 0) {
      continue;
    }
    
    // printf("%s\n", (dir + "/" + files[i]).c_str());
    int fd = open((dir + files[i]).c_str(), O_RDWR);
    if (fd == -1) {
      printf("open file error\n");
      return 0;
    }
    // printf("open success\n");
    struct stat sst_stat;
    fstat(fd, &sst_stat);
    void *addr;
    addr = mmap((void *)0, sst_stat.st_size, PROT_NONE, MAP_SHARED, fd, 0);
    size_t page_size = getpagesize();
    unsigned char *vec = (unsigned char *)malloc((sst_stat.st_size + page_size - 1) / page_size);
    mincore(addr, sst_stat.st_size, vec);

    for (int page_index = 0; page_index <= sst_stat.st_size/page_size; page_index++) {
      if (vec[page_index] & 1) {
        tot_cache++;
      }
    }
  }
  printf("total rocksdb cache size %d MB\n", tot_cache * 4 / 1024);
  return 0;
}
