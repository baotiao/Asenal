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
#define N 2000
#define PRIME 999983


enum Status {
  kS = 0, // 未感染
  kI = 1, // 感染
  kR = 2, // 康复
};

/*
 * 是否被接种过
 */
enum Vcn {
  kNo = 0,
  kSelf = 1,
  kGov = 2
};

int mp[N][N];

int status[N];
int sbak[N];

int degree[N];

/*
 * 每个点连接的边有哪些
 */
vector<int> nodes[N];

/*
 * 最近期的感染时间
 */
int last_time[N];

/*
 * 疫苗感知有效率
 */
double feel[N];

/*
 * used to bak feel
 */
double feel2[N];

/*
 * 表示每一个节点是否被接种过, 自己接种, 还是政府接种
 */
int vcns[N];

/*
 * 本期采取的行为
 */
int vcns2[N];

/*
 * 表示这个节点被感染过
 */
int is[N];

/*
 * 当前这个节点的收益状态
 */
double payoff[N];

/*
 * c is the cost for injection
 * c 是接种成本
 */
double c = 0.45;

/*
 * 患病成本
 */
double ic = 1.00;

/*
 * 政府补贴的接种人群比例
 */
int butie = 30;
/*
 * 自己接种的人群百分比
 */
int vcn = (100 - butie) / 2;
/*
 * 不接种的人群百分比
 */
int unvcn = 100 - butie - vcn;

/*
 * 接种的真实有效率
 */
int vcn_ok = 100;

/*
 * 成本敏感程度
 */
int beita = 5;


/*
 * 初始感知疫苗有效率
 */
double init_feel = 0.6;

/*
 * 最小的疫苗感知有效率
 */
double min_feel = 0.5;

/*
 * 最大的疫苗感知有效率
 */
double max_feel = 0.9;

/*
 * 记忆衰减系数
 */
double memory = 0.25;

/*
 * 疫苗有效率的衰减系数
 */
double v_memory = 4;

/*
 * 自信系数
 */

int confident = 0;


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

/*
 * 感染概率, 百分比
 */
int grl = 40;
double dgrl = 0.4;

/*
 * 康复的概率
 */
int kfl = 20;


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

/*
 * 初始感染的过程
 * 随机免疫
 */
void InitialInfect() {

  int InitialInfection = 5;

  int j = InitialInfection;
  for (int i = 200; i < n; i++) {
    if (j <= 0) {
      break;
    }
    if (status[i] == kS) {
      is[i] = 1;
      status[i] = kI;
      j--;
    }
  }
}

struct node {
  int i;
  int cnt;
}dnode[N];


bool cmp(node a, node b) {
  return a.cnt > b.cnt;
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

  /*
   * 初始化每一个点相连的点有哪些
   */
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[i][j] == 1) {
        nodes[i].push_back(j);
      }
    }
  }
  /*
   * 初始化按照degree 排序好节点
   */
  for (int i = 0; i < n; i++) {
    dnode[i].i = i;
    dnode[i].cnt = degree[i];
  }
  sort(dnode, dnode + n, cmp);
  
}

void InitMap()
{
  clr(is, 0);
  clr(vcns, 0);
  clr(status, 0);

  /*
   * 初始化最近期的感染时间
   */
  for (int i = 0; i < n; i++) {
    last_time[i] = MAX;
  }


  /*
   * 初始化疫苗有效
   */
  for (int i = 0; i < n; i++) {
    feel[i] = init_feel; 
  }



  // for (int i = 0; i < n; i++) {
  //   printf("%d %d\n", dnode[i].i, dnode[i].cnt);
  // }

  // ============ 目标人群免疫过程 ==============
  for (int i = 0; i < n * butie / 100; i++) {
    vcns[dnode[i].i] = kGov;
  }

  int tmp;
  for (int i = 0; i < n; i++) {
    if (vcns[i] == kGov) {
      continue;
    }
    tmp = rand() % (100 - butie);
    if (vcn >= tmp) {
      vcns[i] = kSelf;
    } else {
      vcns[i] = kNo;
    }
  }

  // ============== 随机人群免疫过程 ============
  // int tmp;
  // for (int i = 0; i < n; i++) {
  //   tmp = rand() % 100;
  //   if (butie > tmp) {
  //     vcns[i] = kGov;
  //   } else if (tmp >= butie && tmp < butie + vcn) {
  //     vcns[i] = kSelf;
  //   } else {
  //     vcns[i] = kNo;
  //     status[i] = kS;
  //   }
  // }

  for (int i = 0; i < n; i++) {
    if (vcns[i] == kGov || vcns[i] == kSelf) {
      if (rand() % 100 < vcn_ok) {
        status[i] = kR;
      } else {
        status[i] = kS;
      }
    }
  }

  InitialInfect();
}


/*
 * util function, change vcns => vcns2
 */
void InitToInit2()
{
  for (int i = 0; i < n; i++) {
    swap(vcns[i], vcns2[i]);
    swap(feel[i], feel2[i]);
  }
}

void InitMap2()
{
  /*
   * 计算感知疫苗有效率
   */
  for (int i = 0; i < n; i++) {
    if ((vcns[i] == kSelf || vcns[i] == kGov) && is[i] == 1) {
      feel2[i] = min_feel;
    } else if ((vcns[i] == kSelf || vcns[i] == kGov) && is[i] == 0) {
      feel2[i] = feel[i] * exp(-memory) + (1 - exp(-memory)) * max_feel;
    } else if (vcns[i] == kNo) {
      feel2[i] = feel[i] * exp(-memory / v_memory) + (1 - exp(-memory / v_memory)) * max_feel;
    }
  }

  clr(is, 0);
  clr(status, 0);
  clr(vcns2, 0);
  int tmp;

  // ================= 目标人群免疫过程 ================
  for (int i = 0; i < n * butie / 100; i++) {
    vcns2[dnode[i].i] = kGov;
  }

  for (int i = 0; i < n; i++) {

    if (vcns2[i] == kGov) {
      continue;
    }

    if (0) {
  // ================= 目标人群免疫过程 ================


  // ================ 随机人群免疫过程 ===============
  //
  // for (int i = 0; i < n; i++) {
  //   if (butie >= tmp) {
  //     vcns2[i] = kGov;
  //
  // ================ 随机人群免疫过程 ===============
    } else {
      if (confident > rand() % 100) {
        /*
         * 进入自信自我选择逻辑
         */
        double pn = -ic * exp(-memory * last_time[i]);
        double pv = -c - (1 - feel[i]) * ic;

        double fz = 1.00;
        double fm = 1.00 + exp(-1.00 * beita * (pv - pn));
        double p = fz / fm;

        if (p * 100 >= rand() % 100) {
          vcns2[i] = kSelf;
        }
      } else {
        /*
         * 进入模仿逻辑
         */
        /*
         * 随机选取与i 节点相邻的一个节点
         */
        int j = nodes[i][rand() % nodes[i].size()];
        double fz = 1.00;
        double fm = 1.00 + exp(-1.00 * beita * (payoff[j] - payoff[i]));
        /*
         * 这里p 是多大的概率进行模仿
         */
        double p = fz / fm;
        if (p * 100 > rand() % 100) {
          vcns2[i] = vcns[j];
        } else {
          vcns2[i] = vcns[i];
        }
      }
    }
  }


  for (int i = 0; i < n; i++) {
    if (vcns2[i] == kGov || vcns2[i] == kSelf) {
      if (rand() % 100 < vcn_ok) {
        status[i] = kR;
      } else {
        status[i] = kS;
      }
    }
  }

  int self = 0;
  for (int i = 0; i < n; i++) {
    if (vcns2[i] == kSelf) {
      self++;
    }
  }
  printf("自愿接种的人数 %d\n", self);
  InitialInfect();
  InitToInit2();
}

bool CheckDegree()
{
  clr(degree, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      degree[i] += mp[i][j];
    }
  }

  return true;
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
    if (status[i] == kS) {
      cs++;
    } else if (status[i] == kI) {
      ci++;
    } else if (status[i] == kR) {
      cr++;
    }
  }

  printf("%d, %d, %d, %d\n", 0, cs, ci, cr);
  while (1) {

    for (int i = 0; i < n; i++) {
      sbak[i] = status[i];
    }

    for (int i = 0; i < n; i++) {
      if (status[i] == kS) {
        rn = 0;
        for (int j = 0; j < n; j++) {
          if (mp[i][j] == 1 && status[j] == kI) {
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
          sbak[i] = kI;
        }
      } else if (status[i] == kI) {
        is[i] = 1;
        if (rand() % 100 <= kfl) {
          sbak[i] = kR;
        }
      } else {
      }
    }
    for (int i = 0; i < n; i++) {
      status[i] = sbak[i];
    }

    cs = 0, ci = 0, cr = 0;
    for (int i = 0; i < n; i++) {
      if (status[i] == kS) {
        cs++;
      } else if (status[i] == kI) {
        ci++;
      } else if (status[i] == kR) {
        cr++;
      }
    }

    // printf("%d, %d, %d, %d\n", cnt++, cs, ci, cr);
    if (Judge()) {
      break;
    }
  }
}

/*
 * 打印r, vr 的概率
 */
void Sprint()
{
  int r = 0, nr = 0, vr = 0;
  for (int i = 0; i < n; i++) {
    if (status[i] == kR && is[i] == 0) {
      vr++;
    } else if (status[i] == kR && is[i] == 1) {
      if (vcns[i] == kSelf || vcns[i] == kGov) {
        r++;
      } else {
        nr++;
      }
    }
  }

  int is_num = 0;
  for (int i = 0; i < n; i++) {
    if (is[i] == 1) {
      is_num++;
    }
  }

  printf("通过感染过程进入R态 %d 接种成功进入R态 %d\n", r + nr, vr);

  printf("接种失败感染进入R态 %d 没接种感染进入R态 %d\n", r, nr);

  printf("总共感染人群 %d\n", is_num);
}

void CalPayOff()
{
  for (int i = 0; i < n; i++) {
    if (is[i] == 1 && (vcns[i] == kSelf || vcns[i] == kGov)) {
      payoff[i] = -c - ic;
    } else if (is[i] == 1 && vcns[i] == kNo) {
      payoff[i] = -ic;
    } else if (is[i] == 0 && (vcns[i] == kSelf || vcns[i] == kGov)) {
      payoff[i] = -c;
    } else if (is[i] == 0 && vcns[i] == kNo) {
      payoff[i] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    if (is[i] == 1) {
      last_time[i] = -1;
    }
    if (last_time[i] != MAX) {
      last_time[i]++;
    }
  }
}

int main()
{
  srand(time(0));
  BuildScaleFree();

  InitMap();

  // Print();

  Process();
  Sprint();
  CalPayOff();

  int cnt = 3000;
  while (cnt--) {
    InitMap2();
    Process();
    Sprint();
    CalPayOff();
  }
  return 0;
}
