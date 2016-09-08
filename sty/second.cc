#include "sty.h"
#include "xdebug.h"

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



int mp[N][N];
int status[N];
int sbak[N];
int degree[N];

int vcn[N];

int vs[N];

/*
 * 邻居节点感染人数
 */
int nbi[N];


// ====================无标度网络==================
/*
 * degree sum, used in BuildScaleFree
 */
int dsum[N];

/*
 *
 * 已经存在的节点数
 */
int m = 5;

// ====================无标度网络==================

/*
 * 初始网络构建
 */
int origin = 5;
int ave_du = 4;
int n = N;

/*
 * 康复的概率
 */
double kfl = 0.3;

/*
 * 感染概率
 */
double beita = 0.1;

/*
 * 度
 */
int init_degree = 4;

/*
 * 疫苗有效率
 */
double ir = 0.5;


/*
 * utility functions
 */
inline int getp(int fenmu = 100) {
  return rand() % fenmu;
}

inline bool cp(double p, int fenmu = 100) {
  if ((int)(p * 100) > getp(fenmu)) {
    return true;
  }
  return false;
}

inline bool cp(int p, int fenmu = 100) {
  if (p > getp(fenmu)) {
    return true;
  }
  return false;
}

void swapArr(int from[], int to[], int len) {
  for (int i = 0; i < len; i++) {
    swap(from[i], to[i]);
  }
}

void storeArr(int from[], int to[], int len) {
  for (int i = 0; i < len; i++) {
    to[i] = from[i];
  }
}


void BuildRegular()
{
  clr(mp, 0);
  int tmp;

  init_degree = 4;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= (init_degree / 2); j++) {
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
   * 初始化感染节点
   */
  clr(status, 0);
  clr(vcn, 0);
  clr(vs, 0);
  for (int i = 0; i < 10; i++) {
    status[i] = kI;
  }
  /*
   * vcn[0] = kYes;
   * if (cp(ir)) {
   *   vs[0] = kSucc;
   * } else {
   *   vs[0] = kFail;
   * }
   */
  
  storeArr(status, sbak, n);

}

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
int smallp = 10;

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

inline bool IsIn(const vector<int> &arr, const int num) {
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
      if (i == j) {
        continue;
      }
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
    while (rep.size() < (init_degree / 2)) {
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

  int sum = 0;
  for (int i = 0; i < n; i++) {
    debug(degree[i]);
    sum += degree[i];
  }
  debug(sum);

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
    if (status[i] == kI) {
      return false;
    }
  }
  return true;
}

int cs = 0, ci = 0, cr = 0;

/*
 * is 是没有接种&感染
 * iv 接种&感染
 * cv 接种并且未被感染
 *
 */
int cv = 0, is = 0, iv = 0;
int tv = 0;
void statics()
{
  cs = 0, ci = 0, cr = 0;
  cv = 0; is = 0, iv = 0;
  tv = 0;
  for (int i = 0; i < n; i++) {
    if (vcn[i] == kYes) {
      tv++;
    }
    if (status[i] == kS && vcn[i] == kNo) {
      cs++;
    } else if (status[i] == kS && vcn[i] == kYes) {
      cv++;
    } else if (status[i] == kI && vcn[i] == kNo) {
      ci++;
      is++;
    } else if (status[i] == kI && vcn[i] == kYes) {
      ci++;
      iv++;
    } else if (status[i] == kR) {
      cr++;
    }
  }
}

void Process()
{
  /*
   * 定义这个迭代的次数
   */

  int cnt = 1;

  /*
   * infection information rate
   */
  double iir = 0.02;

  /*
   * vacination informationrate
   */
  double vir = 0.02;

  /*
   * initial vacination wish
   */
  double ivw = 0.1;


  printf("Tick, S, V, I, R\n");
  statics();

  printf("%d, %d, %d, %d, %d\n", 0, cs, tv, ci, cr);
  while (1) {
    for (int i = 0; i < n; i++) {
      if (status[i] == kS && vcn[i] == kNo) {
        /*
         * v * e ^ (a * is - b * iv)
         * v = ivw
         * iir = a
         * vir = b
         */

        double p = (iir * is / (1 + iir * is)) * (1.0 - ((vir * iv) / (1.0 + vir * iv)));
        // log_info("%lf", (iir * is - vir * iv) / n);
        // log_info("p %lf", p);
        if (cp(p)) {
          vcn[i] = kYes;
          if (cp(ir)) {
            vs[i] = kSucc;
          } else {
            vs[i] = kFail;
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (status[i] == kS && vcn[i] == kNo) {

        double p = beita * (1.0 - ((iir * is) / (1.0 + iir * is))) * (1.0 - ((vir * iv) / (1.0 + vir * iv)));
        // log_info("first p %lf %d", p, nbi[i]);
        p = 1 - p;
        p = pow(p, nbi[i]);
        p = 1 - p;
        // log_info("p %lf", p);
        if (cp(p)) {
          sbak[i] = kI;
        }
      } else if (status[i] == kS && vcn[i] == kYes && vs[i] == kFail) {
        double p = 1 - beita;
        p = pow(p, nbi[i]);
        p = 1 - p;
        if (cp(p)) {
          sbak[i] = kI;
        }
      } else if (status[i] == kI) {
        if (cp(kfl)) {
          sbak[i] = kR;
        }
      } else {
      }
    }
    storeArr(sbak, status, n);

    statics();
    printf("%d, %d, %d, %d, %d\n", cnt++, cs, tv, ci, cr);

    clr(nbi, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mp[i][j] == 1) {
          nbi[i]++;
        }
      }
    }

    if (ci == 0) {
      // log_info("judje success");
      break;
    }
  }
}

int main()
{

  srand(time(0));
  BuildRegular();
  // Build();
  // BuildSmall();
  // BuildScaleFree();

  /*
   * 检查每个节点的度数
   */
  // if (CheckDegree() == 0) {
  //   return false;
  // }


  // Print();

  Process();

  return 0;
}
