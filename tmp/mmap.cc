#include <stdio.h>
#include <fcntl.h>
#include "xdebug.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

class node {
public:
    node(int a1, int b1) {
        a = a1;
        b = b1;
    }
    int a;
    int b;
};

int main()
{
    int fdin, fdout;
    const char *fdin_file = "./h10";
    const char *fout_file = "./h10_out";
    void *src, *dst;
    struct stat statbuf;

    if ((fdin = open(fdin_file, O_RDONLY)) < 0) {
        log_err("fdin open file error");
    }

    if ((fdout = open(fout_file, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO)) < 0) {
        log_err("fout open file error");
    }

    if (fstat(fdin, &statbuf) < 0) {
        log_err("fstat error");
    }
    pint(statbuf.st_size);

    if (lseek(fdout, statbuf.st_size - 1, SEEK_SET) == -1) {
        log_err("lseek error");
    }
    if (write(fdout, "", 1) != 1) {
        log_err("write error");
    }

    if ((src = mmap(0, statbuf.st_size, PROT_READ, MAP_SHARED, fdin, 3)) == MAP_FAILED) {
        log_err("mmap error for input");
    }

    if ((dst = mmap(0, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0)) == MAP_FAILED) {
        log_err("mmap error for input");
    }
    
    node *n;
    n = new (dst) node(1, 2);
    // memcpy(dst, src, statbuf.st_size);

    
    printf("hello mmap\n");

    return 0;
}
