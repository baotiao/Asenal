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
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        double res = 1;
        for (int i = 0; i < n; i++) {
            res = res * res;
        }
        return res;
        
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    return 0;
}

