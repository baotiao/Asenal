#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a = 10;
    assert(a > 11);
    fprintf(stderr, "a is too small\n");
    return 0;
}
