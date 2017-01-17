#ifndef __STY_H
#define __STY_H

#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring> 
#include <string>
#include <cmath> 
#include <vector> 
#include <queue> 
#include <map>
#include <ctime>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include "xdebug.h"

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
enum IsVaccinate {
  kNo = 0,
  kYes = 1,
};

enum IsSelfProtect {
  kSelfProtectNo = 0,
  kSelfProtectYes = 1,
};

/*
 * 注射疫苗是否成功
 */
enum VaccinateStatus {
  kVaccinateFail = 0,
  kVaccinateSucc = 1,
};

enum Behaviour {
  kLaissez = 0,
  kSelf = 1,
  kVaccinate = 2,
};

// global variable


/*
 * 一堆统计信息
 *
 * cs s 态人的个数
 * cinfect i 态人的个数
 * cr r 态人的个数
 * is 是没有接种&感染
 * iv 接种&感染
 * cv 接种并且未被感染
 * tv 总的接种人数
 * vr 是接种过并进入r态的人, 说明这个人接种失败又被感染了
 * sr 是没有接种过并进入r态的人
 * claissez 是放任自流的人数
 * cself 是自我保护的人数
 * cvaccinated 是被感染的人数
 *
 */
int cs = 0, cinfect = 0, cr = 0;
int cv = 0, is = 0, iv = 0;
int tv = 0;

int vr = 0, sr = 0;
int claissez = 0, cself = 0, cvaccinate = 0;

// sd 是最后的整个社会的成本
double sd = 0.0;


// ============================================================================
/*
 * 疫苗有效率
 */
double ir = 1.0;

/*
 * 疾病信息的播报率
 */
double a = 1.0;

/*
 * 疫苗信息的播报率
 */
double b = 1.0;

/*
 * 疫苗成本
 */
double c = 0.7;

/*
 * 自我保护需要的钱
 */
// double d = 0.1;

/*
 * 康复的概率
 */
double kfl = 0.312;

/*
 * 感染概率
 * 疾病传播率
 */
double beita = 0.4992;

/*
 * 自我保护强度
 */
// double sita = 0.6;

/*
 * global variable end here
 */
// ============================================================================


int mp[N][N];
int status[N];
int sbak[N];
int degree[N];

struct node {
  int cs, cinfect, cr;
  int cv, is, iv;
  int tv;
  
  node():
    cs(0),
    cinfect(0),
    cv(0),
    is(0),
    iv(0),
    tv(0) {};
} statistics[N];

// 当前进行的轮数
int t = 0;

// 信息滞后时间
int delay = 0;

/*
 * 是否接种
 */
IsVaccinate is_vaccinate[N];

/*
 * 是否自我保护过
 */
IsSelfProtect is_self_protect[N];

/*
 * 接种是否成功
 */
VaccinateStatus vaccinate_status[N];

/*
 * 邻居节点感染人数
 */
int nbi[N];

/*
 * 邻居节点人数
 */
int nb[N];

/*
 * 节点的行为 1. 放任自流 2. 自我保护 3. 接种
 */
int behaviour[N];


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
int n = N;

/*
 * 度
 */
int init_degree = 6;


/*
 * 定义这个迭代的次数
 */

int cnt = 0;


#endif
