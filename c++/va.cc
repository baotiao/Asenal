#include <iostream>
#include <cstdarg>

void log(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    char buf[1024];
    char *p = buf;

    vsnprintf(p, sizeof(buf), fmt, args);
    printf("%s\n", p);

    va_end(args);
}
 
int main()
{
    const char *name = "zongzhi";
    int a = 1, b = 3;
    log("result %d%s%d", a, name, b); 
    // simple_printf("dcff", 3, 'a', 1.999, 42.5); 
    return 0;
}
