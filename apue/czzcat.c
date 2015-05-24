#include <stdio.h>
#include <errno.h>
#include <string.h>

void filecpy(FILE *, FILE *);

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc == 1) {
        errno = 1;
        char *str = "chenzongzhi";
        perror(str);

        fprintf(stderr, "There is only one input %s\n", argv[0]);
        filecpy(stdin, stdout);
    } else {
        fp = fopen(argv[1], "r");
        filecpy(fp, stdout);
    }
    return 0;
}

void filecpy(FILE *from, FILE *to)
{
    int c;
    while ((c = getc(from)) != EOF) {
        putc(c, to);
    }
}
