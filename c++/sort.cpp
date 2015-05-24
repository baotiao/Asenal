#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;

int partition(int a[], int left, int right)
{
    int m = left;
    int mark = a[left];
    swap(a[left], a[right - 1]);
    for (int i = left; i < right - 1; i++) {
        if (a[i] < mark) {
            swap(a[m], a[i]);
            m++;
        }
    }
    swap(a[m], a[right - 1]);
    return m;
}

int partition1(int a[], int left, int right)
{
    int *b = (int *)malloc(sizeof(int) * 100);
    int *c = (int *)malloc(sizeof(int) * 100);
    int mid = (left + right) / 2;
    int num = a[mid];
    int bn = 0, cn = 0;
    for (int i = left; i < right; i++) {
        if (i == mid) {
            continue;
        }
        if (a[i] <= num) {
            b[bn++] = a[i];
        } else {
            c[cn++] = a[i];
        }
    }
    int an = left;
    for (int i = 0; i < bn; i++) {
        a[an++] = b[i];
    }
    int ans = an;
    a[an++] = num;
    for (int i = 0; i < cn; i++) {
        a[an++] = c[i];
    }
    return ans;
}

void quick_sort(int a[], int left, int right)
{
    if (left >= right) {
        return;
    }
    int mark = partition(a, left, right);
    quick_sort(a, left, mark);
    quick_sort(a, mark + 1, right);
}

int main()
{
    int a[11] = {18, 6, 9, 1, 4, 15, 12, 5, 6, 7, 11};
    quick_sort(a, 0, 11);

    for (int i = 0; i < 11; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
