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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "xdebug.h"


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
  kYes = 1,
};

/*
 * 注射疫苗是否成功
 */
enum Vs {
  kFail = 0,
  kSucc = 1,
};

#endif
