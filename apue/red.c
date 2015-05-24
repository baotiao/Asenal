/**
 * 这个是模拟搜索引擎匹配的c程序
 * 输出中位于<red>...</red>中间的就是要标红的关键字
 */
#include<stdio.h>
#include<string.h>
#define N 10000
#define M 100
struct node {
    int type;
    int pos;
    int p;
}q[N], tmp; // node 用来记录关键字匹配到的文本,type 是第几个关键子,pos是这个关键字位于第几行,p是这个关键字位于哪一个位置
int num = 0; // num 得到全文总共有多少此关键字匹配.

char *sstr[M] = {"ORM","programming", "most"}; // 假设输入的关键字
int len[M];
int cnt = 3;

// mstr 用来记录所要匹配的文本
char *mstr[N] = {
"this is a long long word, i will find the word is", 
"I like Jobs very much",
"Vim is open source and freely distributable", 
"It is possible to go directly to whatever you want help",
"Overview of the most common commands you will use",
"USER MANUAL: These files explain how to accomplish an editing task.",
"reading at the first sentence that makes them angry and then leave ao",
"I was pleased to discover that Wikipedia has a comprehensive list of",
"anti-patterns, both from within the world of programming and outside",
"two criteria the author of AntiPatterns used to distinguish anti-patterns from mere bad habits, specifically:",
"of it. The reason I call ORM an anti-pattern programming is because it matches the",
"The most obvious problem with ORM as an abstraction is that it does",
"not adequately abstract away the implementation details. The documentation",
"of all the major ORM libraries is rife with references to SQL concepts.",
"Some introduce them without indicating their equivalents in SQL, hile",
"others treat the library as merely a set of procedural functions for generating SQL."};
int cntm = 16;


int row = 2; // 搜索引擎首页能显示的行数
int rowcnt[N]; // 每一行被关键字匹配了多少次

int maxn = 0, now = 0;
void match(int i, int j)
{
    int i1,j1;
    int lm = strlen(mstr[j]);
    int ln = strlen(sstr[i]);
    //printf ("%d %d\n", lm, ln);
    //printf ("%s %s\n", mstr[j], sstr[i]);
    for (i1=0; i1<lm; i1++) {
        j1 = 0;
        while (i1<lm && j1<ln) {
            if (mstr[j][i1] != sstr[i][j1]) {
                break;
            }
            i1++;
            j1++;
        }
        //printf ("j1 %d\n", j1);
        if (j1==ln) {
            q[num].type = i;
            q[num].p = i1-ln;
            q[num++]. pos = j;
        }
    }
}
void setnode(int i)
{
    int j;
    for (j=0; j<cntm; j++) {
        match(i, j);
    }
}
void init()
{
    int i,j;
    for (i=0; i<cnt; i++) {
        setnode(i);
    }
}
void input()
{
    int i;
    for (i=0; i<cnt; i++) {
        len[i] = strlen(sstr[i]);
    }
}
void sort()
{
    int i,j;
    for (i=0; i<num; i++) {
        for (j=0; j<num; j++) {
            if (q[i].pos < q[j].pos) {
                tmp = q[i];
                q[i] = q[j];
                q[j] = tmp;
            } else if (q[i].pos == q[j].pos) {
                if (q[i].p < q[j].p) {
                    tmp = q[i];
                    q[i] = q[j];
                    q[j] = tmp;
                }
            }
        }
    }
}

void initrowcnt()
{
    int i;
    memset(rowcnt, 0 ,sizeof(rowcnt));
    for (i=0; i<num; i++) {
        rowcnt[q[i].pos]++;
    }
    for (i=1; i<cntm; i++) {
        rowcnt[i] += rowcnt[i-1];
    }
    //for (i=0; i<cntm; i++) {
    //    printf("%d ", rowcnt[i]);
    //}
    //printf("\n");
}
void docnt()
{
    maxn = rowcnt[row-1];
    int i;
    for (i=1; i+row-1<cntm; i++) {
        if (rowcnt[i+row-1] - rowcnt[i-1] > maxn) {
            maxn = rowcnt[i+row-1] - rowcnt[i-1];
            now = i;
        }
    }
}

void print()
{
    if (num == 0) {
        printf("找不到匹配的关键字\n");
        return ;
    }
    int i = 0;
    int l,j,k;
    int flagnum = 0;
    for (; flagnum < num; flagnum++) {
        if (q[flagnum].pos == now) {
            break;
        }
    }
    while (i<row) {
        l = strlen(mstr[now + i]);
        for (j=0; j<l; j++) {
            if (j == q[flagnum].p && q[flagnum].pos == now + i) {
                printf("<red>");
                for (k=0; k<len[q[flagnum].type]; k++){
                    printf("%c", mstr[now+i][j+k]);
                }
                j+=k-1;
                printf("</red>");
                flagnum++;
            } else {
                printf("%c", mstr[now+i][j]);
            }
        }
        printf("\n");
        i++;
    }
}
int main()
{
    int i,j;
    input(); //初始关键字数组,标记长度
    init(); //对每一个关键字对文本进行匹配,获得初始化的q数组.记录所有匹配的关键字的位置.
    sort(); //对q数组进行排序.
    //for (i=0; i<num; i++) {
    //    printf("%s %d %d %d\n", sstr[q[i].type], q[i].type, q[i].pos, q[i].p);
    //}
    initrowcnt(); //对rowcnt计算,计算每行有多少个关键子匹配了.
    docnt(); //在搜索引擎首页只能显示row行的情况下,找出匹配次数最多的连续的row行.
    print(); //输出结果,在<red>...</red>之间的即是标红的关键字
    //printf("%d\n", now);
    return 0;
}
