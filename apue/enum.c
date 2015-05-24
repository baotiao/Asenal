#include <stdio.h>
#include <stdlib.h>

enum boolean {NO, YES};
enum protocol {                                                 
    ascii_prot = 0x37, /* arbitrary value. */                      
    binary_prot,                                                
    negotiating_prot /* Discovering the protocol */             
};
int main()
{
    printf("%d\n", NO);
    printf("%d\n", ascii_prot);
    printf("%d\n", binary_prot);
    int a = binary_prot;
    printf("%d\n", a);
    a = YES;
    printf("%d\n", a);
    return 0;
}
