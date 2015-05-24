#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
typedef long long lld;
using namespace std;
#define CLR(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME))
#define N 610
#define MAX 0x7f7f7f7f
int mp[N][N];
int sp[N];
queue<int>q;
int s[N];
int len[N];
int len1[N];
int n,m;
void init()
{
    for(int i=1;i<=n;i++) {
        len[i]=MAX;
        s[i]=0;
    }
}
void init1()
{
    for(int i=1;i<=n;i++) {
        len1[i]=MAX;
        s[i]=0;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("a.txt","r",stdin);
    #endif
    while(scanf("%d",&n)!=EOF&&n) {
        scanf("%d",&m);
        int x,y,z;
        memset(mp,-1,sizeof(mp));
        for(int i=0;i<m;i++) {
            scanf("%d%d%d",&x,&y,&z);
            mp[x][y]=z;
            mp[y][x]=z;
        }
        for(int i=1;i<=n;i++) {
            scanf("%d",&sp[i]);
        }
        while(!q.empty()) {
            q.pop();
        }
        q.push(1);
        init();
        s[1]=1;
        len[1]=0;
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            s[u]=0;
            for(int i=1;i<=n;i++) {
                if(sp[i]==2)
                    continue;
                if(mp[u][i]!=-1&&len[i]>len[u]+mp[u][i]) {
                    len[i]=len[u]+mp[u][i];
                    if(!s[i]) {
                        q.push(i);
                        s[i]=1;
                    }
                }
            }
        }
        s[2]=1;
        len1[2]=0;
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            s[u]=0;
            for(int i=1;i<=n;i++) {
                if(sp[i]==1)
                    continue;
                if(mp[u][i]!=-1&&len1[i]>len1[u]+mp[u][i]) {
                    len1[i]=len1[u]+mp[u][i];
                    if(!s[i])
                    {
                        q.push(i);
                        s[i]=1;
                    }
                }
            }
        }
        int ans=MAX;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(len[i]!=MAX&&len1[j]!=MAX&&sp[i]==1&&sp[j]==2&&mp[i][j]!=-1)  //这里 //如果len[i] 和len[j]不判断的话容易越界~超int 所以得判断先
                {
                    ans=min(ans,len[i]+len1[j]+mp[i][j]);
                }
            }
        }
        if(ans==MAX) {
            printf("-1\n");
        } else {
            printf("%d\n",ans);
        }
    }
    #ifndef ONLINE_JUDGE
    while(1);
    #endif
    return 0;
}
