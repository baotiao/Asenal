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

class WordDictionary {
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<" = "<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN -9999999
#define N 30
#define PRIME 999983
public:
    struct node {
        node() {
            for (int i = 0; i < N; i++) {
                next[i] = NULL;
            }
        }
        node* next[N];
    };

    WordDictionary() 
    {
        head_ = new node();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        int len = word.length();
        node* p = head_;
        int idx;
        for (int i = 0; i < len; i++) {
            idx = word[i] - 'a';
            debug(idx);
            if (p->next[idx] == NULL) {
                p->next[idx] = new node();
            }
            p = p->next[idx];
        }
        p->next[26] = new node();
        
    }

    bool dfs(const string &word, node* p, int idx, int len)
    {
        if (idx >= len) {
            if (p->next[26] != NULL) {
                return true;
            }
            return false;
        }
        if (word[idx] == '.') {
            debug(idx);
            for (int i = 0; i < N; i++) {
                if (p->next[i] != NULL) {
                    debug(i);
                    if (dfs(word, p->next[i], idx + 1, len)) {
                        return true;
                    }
                }
            }
        } else {
            if (p->next[word[idx] - 'a'] != NULL) {
                if (dfs(word, p->next[word[idx] - 'a'], idx + 1, len)) {
                    return true;
                }
            }
        }
        return false;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int len = word.length();
        return dfs(word, head_, 0, word.length());
    }

private:

    node* head_;

};

int main()
{
    #ifdef DEBUG
    freopen("a", "r", stdin);
    #endif

    WordDictionary w;
    w.addWord("ab");
    /*
     * debug(w.search("a"));
     */
    debug(w.search("a"));

    return 0;
}
