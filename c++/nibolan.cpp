#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
queue<int> q;
stack<int> s;
int a[100];
int main()
{
    char* str = "2*3-5*4";
    printf("%s\n", str);
    int len = strlen(str);
    int i, j;
    int num;
    for (i=0; i<len; i++) {
        num = 0;
        for(j=i; j<len; j++) {
            if (str[j] >= '0' && str[j] <= '9') {
                num = num*10 + str[j] - '0';
            } else {
                break;
            }
        }
        i = j;
        q.push(num);
        if (j == len) 
            continue;
        if (str[j] == '+') {
            q.push(-11);
        } else if (str[j] == '-') {
            q.push(-12);
        } else if (str[j] == '*') {
            q.push(-21);
        } else {
            q.push(-22);
        }
    }
    int cnt = 0;
    int tmp;

    while(!q.empty()) {
        tmp = q.front();
        q.pop();
        if (tmp >= 0) {
            a[cnt++] = tmp;
        } else {
            if (s.empty()) {
                s.push(tmp);
            } else if((tmp == -21 || tmp == -22) && s.top() > -21) {
                s.push(tmp);
            } else {
                while(!s.empty()) {
                    a[cnt++] = s.top();
                    s.pop();
                }
                s.push(tmp);
            }
        }
    }
    printf("hhhhhhhhhhhhhhh\n");
    while(!s.empty()) {
        a[cnt++] = s.top();
        s.pop();
    }
    int tmp1, tmp2;
    for (i = 0; i< cnt; i++) {
        if (a[i] >= 0) {
            s.push(a[i]);
        } else if (a[i] == -11) {
            tmp1 = s.top();
            s.pop();
            tmp2 = s.top();
            s.pop();
            s.push(tmp2 + tmp1);
        } else if (a[i] == -12) {
            tmp1 = s.top();
            s.pop();
            tmp2 = s.top();
            s.pop();
            s.push(tmp2 - tmp1);
        } else if (a[i] == -21) {
            tmp1 = s.top();
            s.pop();
            tmp2 = s.top();
            s.pop();
            s.push(tmp2 * tmp1);
        }
    }
    printf("hhhhhhhhhhhhhhh\n");
    int ans = s.top();
    printf("%d\n", ans);

    return 0;
}

