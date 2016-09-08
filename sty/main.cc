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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 10
#define PRIME 999983


int mp[N][N];
int status[N];
int sbak[N];
int degree[N];


// ====================无标度网络==================
/*
 * degree sum, used in BuildScaleFree
 */
int dsum[N];

/*
 *
 * 已经存在的节点数
 */
int m = 4;

// ====================无标度网络==================

/*
 * 初始网络构建
 */
int origin = 5;
int ave_du = 4;
int n = N;

enum Status {
  kS = 0, // 未感染
  kI = 1, // 感染
  kR = 2 // 康复
};

/*
 * 感染概率, 百分比
 */
int grl = 20;
double dgrl = 0.2;

/*
 * 康复的概率
 */
int kfl = 20;

void Build()
{
/*
 * 初始化这个图
 */
  clr(mp, 0);
  int tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= ave_du / 2; j++) {
      tmp = rand() % N;
      if (i == tmp) {
        continue;
      }
      mp[i][tmp] = 1;
      mp[tmp][i] = 1;
    }
  }

  /*
   * 初始化每一个节点的状态
   */
  clr(status, 0);

  for (int i = 0; i < origin; i++) {
    status[i] = 1;
  }

}


/*
 * 小世界网络断开的概率
 */
int smallp = 100;

/*
 * 小世界网络的平均度
 */
int smalldu = 4;


void BuildSmall()
{

  clr(mp, 0);
  int tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= smalldu / 2; j++) {
      tmp = i + j;
      tmp = (tmp + n) % n;
      mp[i][tmp] = 1;
      mp[tmp][i] = 1;
      tmp = i - j;
      tmp = (tmp + n) % n;
      mp[i][tmp] = 1;
      mp[tmp][i] = 1;
    }
  }

  /*
   * 以一定的概率将边断开
   */

  vector<int> v;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (mp[i][j] == 1 && rand() % 100 <= smallp) {
        debug(i);
        debug(j);
        mp[i][j] = 0;
        mp[j][i] = 0;
        v.push_back(i);
        v.push_back(j);
      }
    }
  }

  debug(v.size());

  int l, r;
  int vl, vr;
  
  while (1) {
    debug(v.size());
    if (v.size() == 2) {
      debug(v[0]);
      debug(v[1]);
      mp[v[0]][v[1]] = 1;
      mp[v[1]][v[0]] = 1;
      break;
    }
      

    l = rand() % v.size();
    vl = v[l];
    v.erase(v.begin() + l, v.begin() + l + 1);


    debug(v.size());
    r = rand() % v.size();
    while (vl == v[r] || mp[vl][v[r]] == 1) {
      r = rand() % v.size();
    }
    vr = v[r];
    v.erase(v.begin() + r, v.begin() + r + 1);

    debug(vl);
    debug(vr);
    if (vl == vr) {
      here;
    }
    mp[vl][vr] = 1;
    mp[vr][vl] = 1;
  }

  /*
   * 初始化每一个节点的状态
   */
  clr(status, 0);

  for (int i = 0; i < origin; i++) {
    status[i] = 1;
  }
}

bool IsIn(vector<int> arr, int num) {
  for (int i = 0; i < arr.size(); i++) {
    if (num == arr[i]) {
      return true;
    }
  }
  return false;
}

void UpdateDsum() {
  dsum[0] = degree[0];
  for (int i = 0; i < n; i++) {
    dsum[i] = degree[i] + dsum[i - 1];
  }

  // for (int i = 0; i < n; i++) {
  //   printf("%d ", dsum[i]);
  // }
  // printf("\n");
}


void BuildScaleFree()
{

  clr(mp, 0);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      mp[i][j] = 1;
    }
    degree[i] = m - 1;
  }


  UpdateDsum();

  int tmp = m;
  int du = m;
  int tt;
  
  vector<int> rep;
  while (tmp < n) {
    rep.clear();
    while (rep.size() < m) {
      tt = rand() % dsum[tmp - 1] + 1;
      int i = 0;
      for (i = 0; i < tmp; i++) {
        if (tt <= dsum[i]) {
          break;
        }
      }
      if (IsIn(rep, i)) {
        continue;
      }
      rep.push_back(i);
    }

    for (int i = 0; i < rep.size(); i++) {
      mp[tmp][rep[i]] = 1;
      mp[rep[i]][tmp] = 1;
      degree[tmp]++;
      degree[rep[i]]++;
    }
    UpdateDsum();

    tmp++;
  }
  
}

bool CheckDegree()
{
  clr(degree, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      degree[i] += mp[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    if (degree[i] != smalldu) {
      return false;
    }
  }
  return true;
}


int seed = 36;

void BuildScheld()
{
  clr(mp, 0);

  n = seed;

  BuildSmall();

  n = N;

  int arr[10];
  /*
   * 无标度网络里面的度
   */
  int cntm = 4;
  int cnt = 0;
  int tmp;

  for (int i = seed + 1; i < n; i++) {

    for (int j = 0; j < cntm; j++) {
      // do {
      //   tmp = rand() % i;
      //   for (int k = 0; k < cnt; k++) {
      //   }
      // } while ();

      arr[cnt++] = tmp;

    }

  }

}

void Print()
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", mp[i][j]);
    }
    printf("\n");

  }
}

bool Judge()
{
  for (int i = 0; i < n; i++) {
    if (status[i] == 1) {
      return false;
    }
  }
  return true;
}

void Process()
{

  /*
   * 定义这个迭代的次数
   */
  int tmp = 10;

  int rn = 0;

  int cnt = 1;
  int cs = 0, ci = 0, cr = 0;

  printf("Tick, S, I, R\n");
  for (int i = 0; i < n; i++) {
    if (status[i] == 0) {
      cs++;
    } else if (status[i] == 1) {
      ci++;
    } else if (status[i] == 2) {
      cr++;
    }
  }

  printf("%d, %d, %d, %d\n", 0, cs, ci, cr);
  while (1) {

    for (int i = 0; i < n; i++) {
      sbak[i] = status[i];
    }

    for (int i = 0; i < n; i++) {
      if (status[i] == 0) {
        rn = 0;
        for (int j = 0; j < n; j++) {
          if (mp[i][j] == 1 && status[j] == 1) {
            rn++;
          }
        }
        if (rn == 0) {
          continue;
        }
        int l = rand() % 100;
        double rt = (1 - pow((1 - dgrl), rn));
        int r = (1 - pow((1 - dgrl), rn)) * 100;
        if (l <= r) {
          sbak[i] = 1;
        }
      } else if (status[i] == 1) {
        if (rand() % 100 <= kfl) {
          sbak[i] = 2;
        }
      } else {
      }
    }
    for (int i = 0; i < n; i++) {
      status[i] = sbak[i];
    }

    cs = 0, ci = 0, cr = 0;
    for (int i = 0; i < n; i++) {
      if (status[i] == 0) {
        cs++;
      } else if (status[i] == 1) {
        ci++;
      } else if (status[i] == 2) {
        cr++;
      }
    }

    printf("%d, %d, %d, %d\n", cnt++, cs, ci, cr);
    if (Judge()) {
      break;
    }
  }
}

int main()
{

  srand(time(0));
  // Build();
  // BuildSmall();
  BuildScaleFree();

  /*
   * 检查每个节点的度数
   * if (CheckDegree() == 0) {
   *   return false;
   * }
   */


  // Print();

  Process();

  return 0;
}
