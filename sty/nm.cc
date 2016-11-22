#include "./sty.h"
#include "./xdebug.h"

typedef long long lld; 
using namespace std; 

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
  clr(is_vaccinate, 0);
  clr(vaccinate_status, 0);
  clr(behaviour, 0);
  for (int i = 0; i < 10; i++) {
    status[i] = kI;
  }
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
  int vl, tvr;
  
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
    tvr = v[r];
    v.erase(v.begin() + r, v.begin() + r + 1);

    if (vl == tvr) {
      here;
    }
    mp[vl][tvr] = 1;
    mp[tvr][vl] = 1;
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

void statics()
{
  cs = 0, cinfect = 0, cr = 0;
  cv = 0; is = 0, iv = 0;
  tv = 0;
  vr = 0;
  sr = 0;
  claissez = 0;
  cself = 0;
  cvaccinate = 0;
  
  for (int i = 0; i < n; i++) {
    if (is_vaccinate[i] == kYes) {
      tv++;
    }
    if (behaviour[i] == kLaissez && status[i] == kS) {
      claissez++;
    } else if (behaviour[i] == kSelf && status[i] == kS) {
      cself++;
    } else if (behaviour[i] == kVaccinate) {
      cvaccinate++;
    }

    if (status[i] == kS && is_vaccinate[i] == kYes) {
      cv++;
    } else if (status[i] == kI) {
      cinfect++;
    } else if (status[i] == kR) {
      if (is_vaccinate[i] == kYes) {
        vr++;
      } else {
        sr++;
      }
      cr++;
    }
  }
  statistics[cnt].cr = cr;
  statistics[cnt].cinfect = cinfect;
  statistics[cnt].tv = tv;
  statistics[cnt].tv = cv;
  
  if (cnt == 0) {
    // printf("Tick\tR\tI\tV\tvaccinate_status\n");
    printf("Tick\tLaissez\tSelf\tVaccinate\tInfected\tRecovered\n");
  }
  printf("%d\t%d\t%d\t%d\t%d\t%d\n", cnt, claissez, cself, cvaccinate, cinfect, cr);
  cnt++;
}

static void getRes()
{
  for (int i = 0; i < cnt; i++) {
    if (i == 0) {
      printf("Tick\tR\tincrI\tincrV\n");
      printf("%d\t%d\t%d\t%d\n", i, statistics[i].cr, statistics[i].cinfect, statistics[i].tv);
    } else {
      printf("%d\t%d\t%d\t%d\n", i, statistics[i].cr, statistics[i].cinfect, statistics[i].tv - statistics[i - 1].tv);
    }
  }

  sd = cv * c + vr * (c + 1) + sr;

  printf("sd\t%lf\n", sd);
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
      if (is_vaccinate[i] == kYes) {
        tot_v++;
      }
      if (is_vaccinate[i] == kYes && (status[i] == kI || status[i] == kR)) {
        tot_iv++;
      }
      if (is_vaccinate[i] == kNo && status[i] == kI) {
        tot_pre_is++;
      }
      if (is_vaccinate[i] == kYes && status[i] == kI) {
        tot_pre_iv++;
      }
    }

    for (int i = 0; i < n; i++) {
      if (status[i] == kS && is_vaccinate[i] == kNo) {
        if (behaviour[i] == kLaissez || behaviour[i] == kSelf) {
          double p1, p2, p3;

          // 放任自流
          p1 = 1.00 - pow((1 - beita), static_cast<double>(nb[i]) * 
              ((a * static_cast<double>(tot_pre_is) + b * static_cast<double>(tot_pre_iv)) / 2000.00));
          // 自我保护
          p2 = d + (1.00 - pow((1 - sita * beita), static_cast<double>(nb[i]) * 
              ((a * static_cast<double>(tot_pre_is) + b * static_cast<double>(tot_pre_iv)) / 2000.00)));
          // 疫苗接种
          if (tot_v != 0) {
            p3 = c + b * (static_cast<double>(tot_iv) / static_cast<double>(tot_v));
          } else {
            p3 = c;
          }

          // debug(p1);
          // debug(p2);
          // debug(p3);

          if (p1 < min(p2, p3)) {
            behaviour[i] = kLaissez;
          } else if (p2 < min(p1, p3)) {
            behaviour[i] = kSelf;
          } else if (p3 < min(p1, p2)) {
            behaviour[i] = kVaccinate;
            is_vaccinate[i] = kYes;
            if (cp(ir)) {
              vaccinate_status[i] = kVaccinateSucc;
            } else {
              vaccinate_status[i] = kVaccinateFail;
            }
          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (status[i] == kS) {
        double bt;
        double pt;
        if ((is_vaccinate[i] == kNo && behaviour[i] == kLaissez) || (is_vaccinate[i] == kYes && vaccinate_status[i] == kVaccinateFail)) {
          bt = beita;
          pt = 1.00 - pow((1.00 - bt), (double)nbi[i]);
        } else if (is_vaccinate[i] == kNo && behaviour[i] == kSelf) {
          bt = beita;
          pt = 1.00 - pow((1.00 - bt * sita), (double)nbi[i]);
        } else {
          continue;
        }
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

    if (cinfect == 0) {
      break;
    }
  }
}

int main(int argc, char **argv)
{
  int map_type = 1;
  /*
   * 1. 疫苗有效率
   * 2. 疾病信息的播报率
   * 3. 疫苗信息的播报率
   * 4. 疫苗成本
   * 5. 网络类型
   */
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
  // getRes();

  return 0;
}
