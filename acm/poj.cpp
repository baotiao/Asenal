#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include<cstring> 
#include<string>
#include<cmath> 
#include<vector> 
#include<queue> 
#include<map>
#include<ctime>
#include<set>
typedef long long lld; 
using namespace std; 
#define debug(x) cout<<#x<<"="<<x<<endl;
#define here cout<<"_______________here "<<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 362890
#define N 9
#define PRIME 999983

int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
int fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int color[400000];

struct node{
    string str;
    int f;
    int g;
    int h;
    string ans;
}st, ed;
set<string> set_s;
node heap[MAX];
int lh;

int calhash(string tmp){  
    int i,j;  
    int temp=0,sum=0;  
    for(i=0;i<9;i++){  
        temp=0;  
        for(j=i+1;j<9;j++){  
            if(tmp[i]>tmp[j])  
                temp++;  
        }  
        sum+=temp*fac[9-i-1];  
    }  
    return sum;  
}  

void init()
{
    for (int i = 0; i < MAX; i++) {
        heap[i].ans = "";
    }
}
    

int calh(string str1)
{
    int ans = 0;
    int sx,sy,ex,ey;
    for (int i = 0; i < N; i++) {
        if (str1[i] == 'x') {
            continue;
            ex = 2;
            ey = 2;
        } else {
            ex = (str1[i] - '1') / 3;
            ey = (str1[i] - '1') % 3;
        }
        sx = i / 3;
        sy = i % 3;
        ans += abs(sx - ex) + abs(sy - ey);
    }
    return ans;
}

bool hcmp(node a, node b)
{
    return a.f > b.f;
}

bool check(int x, int y)
{
    if (x >= 0 && x < 3 && y >= 0 && y < 3) {
        return true;
    }
    return false;
}

string bfs()
{
    node tmp, now;
    char c;
    int sx,sy,ex,ey;
    string str1;
    while (lh) {
        //cout << tmp.str << endl;
        tmp = heap[0];
        pop_heap(heap, heap + lh, hcmp);
        lh--;
        for (int i = 0; i < N; i++) {
            if (tmp.str[i] == 'x') {
                sx = i / 3;
                sy = i % 3;
                break;
            }
        }
        for (int i = 0; i < 4; i++) {
            ex = sx + dir[i][0];
            ey = sy + dir[i][1];
            if (check(ex, ey)) {
                str1 = tmp.str;
                c = str1[ex * 3 + ey];
                str1[ex * 3 + ey] = 'x';
                str1[sx * 3 + sy] = c;
                if (color[calhash(str1)] == 1) {
                    continue;
                }
                now.str = str1;
                color[calhash(str1)] = 1;
                now.g = tmp.g + 1;
                now.h = calh(str1);
                now.f = now.g + now.h;
                if (i == 0) {
                    now.ans = tmp.ans + "u";
                } else if (i == 1) {
                    now.ans = tmp.ans + "r";
                } else if (i == 2) {
                    now.ans = tmp.ans + "d";
                } else {
                    now.ans = tmp.ans + "l";
                }
                if (now.str == "12345678x") {
                    return now.ans;
                }
                heap[lh++] = now;
                push_heap(heap, heap + lh, hcmp);
            }
        }
    }
    return "unsolvable";
}

int main()
{
    #ifdef ADD_FREOPEN
    freopen("a", "r", stdin);
    #endif
    char c;
    string str;
    //init();

    while (scanf("%c", &c) != EOF) {
        memset(color, 0, sizeof(color));
        str = "";
        str += char(c);

        for (int i = 1; i < N; i++) {
            c = getchar();
            if (c == ' ') {
                i--;
                continue;
            }
            str += c;
        }
        getchar();
        if (str == "12345678x") {
            cout << endl;
            continue;
        }
        st.str = str;
        st.g = 0;
        st.h = calh(str);
        st.f = st.g + st.h;
        st.ans = "";
        lh = 0;
        heap[lh++] = st;
        push_heap(heap, heap + lh, hcmp);
        color[calhash(str)] = 1;
        //set_s.insert(str);
        string ans = bfs();
        cout << ans << endl;
    }
    return 0;
}
