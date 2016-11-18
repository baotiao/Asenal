#include "./sty.h"
#include "./xdebug.h"

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

struct node {
  int cs, ci, cr;
  int cv, is, iv;
  int tv;
  
  node():
    cs(0),
    ci(0),
    cv(0),
    is(0),
    iv(0),
    tv(0) {};
} statistics[N];

/*
 * 是否接种
 */
int vcn[N];

/*
 * 接种是否成功
 */
int vs[N];

/*
 * 邻居节点感染人数
 */
int nbi[N];

/*
 * 邻居节点人数
 */
int nb[N];


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
 * 度
 */
int init_degree = 6;


/*
 * 定义这个迭代的次数
 */

int cnt = 0;

/*
 * utility functions
 */
inline int getp(int fenmu = 100) {
  return rand() % fenmu;
}

inline bool cp(double p, int fenmu = 100) {
  if ((int)(p * fenmu) > getp(fenmu)) {
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

inline bool IsIn(const vector<int> &arr, const int num) {
  for (int i = 0; i < arr.size(); i++) {
    if (num == arr[i]) {
      return true;
    }
  }
  return false;
}

static void InitMap()
{
  /*
   * 初始化邻居个数
   */
  clr(nb, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[i][j] == 1) {
        nb[i]++;
      }
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


void BuildRegular()
{
  clr(mp, 0);
  int tmp;

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
  InitMap();
}

static void BuildRandom() {
  clr(mp, 0);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (cp(0.003, 100000)) {
        mp[i][j] = 1;
        mp[j][i] = 1;
      }
    }
  }

  InitMap();
}

void UpdateDsum() {
  dsum[0] = degree[0];
  for (int i = 0; i < n; i++) {
    dsum[i] = degree[i] + dsum[i - 1];
  }
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
  InitMap();
}

/*
 * 小世界网络断开的概率
 */
int smallp = 10;

/*
 * 小世界网络的平均度
 */
int smalldu = 6;

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
        mp[i][j] = 0;
        mp[j][i] = 0;
        v.push_back(i);
        v.push_back(j);
      }
    }
  }


  int l, r;
  int vl, vr;
  
  while (1) {
    if (v.size() == 2) {
      mp[v[0]][v[1]] = 1;
      mp[v[1]][v[0]] = 1;
      break;
    }
      

    l = rand() % v.size();
    vl = v[l];
    v.erase(v.begin() + l, v.begin() + l + 1);


    r = rand() % v.size();
    while (vl == v[r] || mp[vl][v[r]] == 1) {
      r = rand() % v.size();
    }
    vr = v[r];
    v.erase(v.begin() + r, v.begin() + r + 1);

    if (vl == vr) {
      here;
    }
    mp[vl][vr] = 1;
    mp[vr][vl] = 1;
  }
  InitMap();
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
 * tv 总的接种人数
 *
 */
int cv = 0, is = 0, iv = 0;
int tv = 0;

int ptv;

void statics()
{
  ptv = tv;
  cs = 0, ci = 0, cr = 0;
  cv = 0; is = 0, iv = 0;
  tv = 0;
  
  for (int i = 0; i < n; i++) {
    if (vcn[i] == kYes) {
      tv++;
    }
    if (status[i] == kS && vcn[i] == kYes && vs[i] == kSucc) {
      cv++;
    } else if (status[i] == kI) {
      ci++;
    } else if (status[i] == kR) {
      cr++;
    }
  }
  statistics[cnt].cr = cr;
  statistics[cnt].ci = ci;
  statistics[cnt].tv = tv;
  statistics[cnt].tv = cv;
  
  // if (cnt == 0) {
  //   printf("Tick\tR\tI\tV\tVs\n");
  // }
  // printf("%d\t%d\t%d\t%d\t%d\n", cnt++, cr, ci, tv, cv);
  cnt++;
}

static void getRes()
{
  for (int i = 0; i < cnt; i++) {
    if (i == 0) {
      printf("Tick\tR\tincrI\tincrV\n");
      printf("%d\t%d\t%d\t%d\n", i, statistics[i].cr, statistics[i].ci, statistics[i].tv);
    } else {
      printf("%d\t%d\t%d\t%d\n", i, statistics[i].cr, statistics[i].ci, statistics[i].tv - statistics[i - 1].tv);
    }
  }
}

void Process()
{
  statics();

  int tot_nbi = 0;
  int tot_v = 0;
  int tot_iv = 0;
  int tot_pre_is = 0;
  int tot_pre_iv = 0;
  while (1) {
    clr(nbi, 0);
    tot_nbi = 0;
    /*
     * 接种过的人
     */
    tot_v = 0;
    /*
     * 接种过, 并且被感染过的人
     */
    tot_iv = 0;

    /*
     * 没有接种过疫苗, 并且被感染过的人
     */
    tot_pre_is = 0;
    /*
     * 接种过疫苗, 又感染的人
     */
    tot_pre_iv = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mp[i][j] == 1 && status[j] == kI) {
          nbi[i]++;
        }
      }
      if (vcn[i] == kYes) {
        tot_v++;
      }
      if (vcn[i] == kYes && (status[i] == kI || status[i] == kR)) {
        tot_iv++;
      }
      if (vcn[i] == kNo && status[i] == kI) {
        tot_pre_is++;
      }
      if (vcn[i] == kYes && status[i] == kI) {
        tot_pre_iv++;
      }
    }

    for (int i = 0; i < n; i++) {
      if (status[i] == kS && vcn[i] == kNo) {
        /*
         * v * e ^ (a * is - b * iv)
         * v = ivw
         * iir = a
         * vir = b
         */

        // double p = (iir * is / (1 + iir * is)) * (1.0 - ((vir * iv) / (1.0 + vir * iv)));
        // double p = 1 - exp(-1.0 * 0.05 * a * static_cast<double>(tot_is));
        // p = p * exp(-1.0 * 0.05 * b * static_cast<double>(tot_iv));
        
        double pv;
        if (tot_v != 0) {
          pv = -1.00 * c - b * (static_cast<double>(tot_iv) / static_cast<double>(tot_v));
        } else {
          pv = -1.00 * c;
        }

        double pn = -1.00 * (1.00 - pow((1 - beita), static_cast<double>(nb[i]) * 
              ((a * static_cast<double>(tot_pre_is) + b * static_cast<double>(tot_pre_iv)) / 2000.00)));
        double p = 1.00 / (1.00 + exp(-1.0 * 5.0 * (pv - pn)));
        
        // debug(nb[i]);
        // debug(tot_pre_is);
        // debug(tot_pre_iv);
        // debug(a * static_cast<double>(tot_pre_is) + b * static_cast<double>(tot_pre_iv));
        // debug(pn);
        // debug(pv);
        // debug(p);
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
      if (status[i] == kS && (vcn[i] == kNo || (vcn[i] == kYes && vs[i] == kFail))) {
        // double bt = beita * exp(-1 * a * ((double)tot_nbi / (double)n));
        double bt = beita;
        double pt = 1.00 - pow((1.00 - bt), (double)nbi[i]);
        // debug(pt);
        // usleep(100000);
        if (cp(pt)) {
          sbak[i] = kI; 
        }
      } else if (status[i] == kI) {
        if (cp(kfl)) {
          sbak[i] = kR;
        }
      } else {
        continue;
      }
    }
    storeArr(sbak, status, n);

    statics();

    clr(nbi, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mp[i][j] == 1) {
          nbi[i]++;
        }
      }
    }

    if (ci == 0) {
      break;
    }
  }
}

int main(int argc, char **argv)
{
  int map_type = 0;
  if (argc == 6) {
    int iir = atoi(argv[1]);
    ir = (double)iir / 100.00;
    int ia = atoi(argv[2]);
    a = (double)ia / 100.00;
    int ib = atoi(argv[3]);
    b = (double)ib / 100.00;
    int ic = atoi(argv[4]);
    c = (double)ic / 100.00;
    map_type = atoi(argv[5]);
  }
  srand(time(0));
  
  /*
   * 0 for Regular, 1 for ScaleFree, 2 for Small, 3 for Random
   */
  if (map_type == 0) {
    BuildRegular();
  } else if (map_type == 1) {
    BuildScaleFree();
  } else if (map_type == 2) {
    BuildSmall();
  } else if (map_type == 3) {
    BuildRandom();
  }
  /*
   * 检查每个节点的度数
   */
  // if (CheckDegree() == 0) {
  //   return false;
  // }


  // Print();

  Process();
  getRes();

  return 0;
}
