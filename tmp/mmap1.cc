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

static size_t Roundup(size_t x, size_t y) {
    return ((x + y - 1) / y) * y;
}

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

    if ((fdout = open(fout_file, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO)) < 0) {
        log_err("fout open file error");
    }

    if (fstat(fdin, &statbuf) < 0) {
        log_err("fstat error");
    }
    pint(statbuf.st_size);

    if (lseek(fdout, 100, SEEK_SET) == -1) {
        log_err("lseek error");
    }
    if (write(fdout, "", 1) != 1) {
        log_err("write error");
    }

    if ((dst = mmap(0, 65536, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0)) == MAP_FAILED) {
        log_err("mmap error for input");
    }
    
    node *n = (node *)dst;
    printf("%d %d %d\n", n->a, n->b, sizeof(node));
    // node *n = new node(1000000, 200000);
    // memcpy(dst, n, sizeof(node));


    // if ((src = mmap(0, 65536, PROT_READ, MAP_SHARED, fdin, 0)) == MAP_FAILED) {
    //     log_err("mmap error for input");
    // }

    // node *rn = new node(2, 2);
    // memcpy(rn, src, sizeof(node));
    
    printf("hello mmap\n");

    return 0;
}
