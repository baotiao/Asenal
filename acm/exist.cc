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

typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN 0x80000000
#define N 16000010
#define PRIME 999983
class Solution
{

public:
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    bool flag[1000][1000];
    bool dfs(vector<vector<char> > &board, int i, int j, string &word, int c)
    {
        if (c == word.length()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) {
            return false;
        }
        if (board[i][j] != word[c]) {
            return false;
        }
        for (int k = 0; k < 4; k++) {
            if (flag[i + dir[k][0]][j + dir[k][1]] == 0) {
                flag[i + dir[k][0]][j + dir[k][1]] = 1;
                if (dfs(board, i + dir[k][0], j + dir[k][1], word, c + 1)) {
                    return true;
                }
                flag[i + dir[k][0]][j + dir[k][1]] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        if (word.length() == 0) {
            return true;
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    memset(flag, 0, sizeof(flag));
                    flag[i][j] = 1;
                    if (dfs(board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    vector<vector<char> > v;
    // char vv[] = "ABCE";
    // vector<char> v1(begin(vv), end(vv));
    // v.push_back(v1);
    // char vv1[] = "SFCS";
    // vector<char> v2(begin(vv1), end(vv1));
    // v.push_back(v2);

    // char vv2[] = "ADEE";
    // vector<char> v3(begin(vv2), end(vv2));
    // v.push_back(v3);

    char vv[] = "a";
    vector<char> v1(begin(vv), end(vv));
    v.push_back(v1);
    Solution s;
    bool ans = s.exist(v, "aaa");
    debug(ans);
    debug("here");
    return 0;
}

