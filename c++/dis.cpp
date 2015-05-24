#include <iostream>
#include <string>
using namespace std;
#define N 1000

class Solution {
    public:
        int a[N][N];
        int minDistance(string word1, string word2) {
            int len1, len2;
            len1 = word1.length();
            len2 = word2.length();
            int ans = 0;
            for (int i = 0; i < len1; i++) {
                for (int j = 0; j < len2; j++) {
                }
            }
            return ans;

        }
};

int main()
{
    Solution s;
    printf("%d\n", s.minDistance());
    return 0;
}
