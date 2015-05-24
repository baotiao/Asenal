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
#include<unordered_set>
typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<<"_______________here "<<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 3010
#define PRIME 999983

class Solution {
public:
    struct node {
        string str;
        int step;
        node (string str_, int step_) {
            str = str_;
            step = step_;
        }
        node () {}
    };
    bool check_ladder(string from, string to) {
        if (from.length() != to.length()) {
            return false;
        }
        int len = from.length();
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (from[i] != to[i]) {
                cnt++;
            }
        }
        if (cnt <= 1) {
            return true;
        } else {
            return false;
        }
    }

    bool init(bool road[][N], unordered_set<string> &dict) {
        int i, j;
        unordered_set<string>::iterator iter;
        unordered_set<string>::iterator iter1;
        i = 0;
        for (iter = dict.begin(); iter != dict.end(); iter++) {
            j = 0;
            for (iter1 = dict.begin(); iter1 != dict.end(); iter1++) {
                if (check_ladder(*iter, *iter1)) {
                    road[i][j] = true;
                }
                j++;
            }
            i++;
        }
        return false;
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        debug(start);
        here;
        if (start == end) {
            return 2;
        }
        if (dict.empty()) {
            return 0;
        }
        unordered_set<string>::iterator iter;
        iter = dict.find(start);

        if (iter == dict.end()) {
            return 0;
        }
        iter = dict.find(end);
        if (iter == dict.end()) {
            return 0;
        }

        queue<node> q;
        set<string> st;
        set<string>::iterator st_iter;
        node tmp = node(start, 1);
        q.push(tmp);
        bool road[N][N];
        memset(road, 0, sizeof(road));
        init(road, dict);
        bool find_word = false;
        int dict_size = dict.size();
        int tmp_pos, target_pos;
        debug(dict_size);
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            tmp_pos = 0;
            for (iter = dict.begin(); iter != dict.end(); iter++) {
                if (*iter == tmp.str) {
                    break;
                }
                tmp_pos++;
            }
            int j = 0;
            for (iter = dict.begin(); iter != dict.end(); iter++) {
                
                st_iter = st.find(*iter);
                if (st_iter == st.end()) {
                    if (road[tmp_pos][j]) {
                        if (*iter == end) {
                            return tmp.step + 1;
                        }
                        q.push(node(*iter, tmp.step + 1));
                        st.insert(*iter);
                    }
                }
                j++;
            }
        }
        return 0;
    }
};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif
    int T;
    Solution s;

    string start = "hit";
    string end = "cog";

    unordered_set<string> dict;
    //dict.insert("ab");
    //dict.insert("bb");
    //dict.insert("cb");
    debug(dict.size());

    debug(start);
    debug(end);
    int ans = s.ladderLength(start, end, dict);
    debug(ans);
    return 0;
}

