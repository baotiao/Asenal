#include<stdio.h>

int binary(int a[], int left, int right, int num)
{
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (a[mid] == num) {
            left = mid;
            break;
        }
        if (a[mid] > num) {
            right = mid;
        } else {
            left = mid;
        }
    }
    if (a[left] == num) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int a[7] = {1, 3, 5, 7, 9, 11, 15};
    int num = 11;
    printf("%d\n", binary(a, 0, 6, num)); 

    return 0;
}


