#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a, b;
    while (cin>>a>>b) {
        int c = a + b;
        cout << c << endl;
    }
    //while(scanf("%d%d", &a, &b) != EOF) {
    //    int c;
    //    c = a + b;
    //    printf("%d\n", c);
    //}

    return 0;
}
