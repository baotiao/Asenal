/* CopyRight (c) cnHawk */

#include<iostream> 
#include<cstdio> 
#include<stdio.h>
#include<stdlib.h>
#include<algorithm> 
#include<cstring> 
#include<string>
#include<cmath> 
#include<vector> 
#include<queue> 
#include<map>
#include<ctime>
#include<set>
typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x) 
#endif
#define here cout<<"_______________here "<<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 16000010
#define PRIME 999983


//=======================================================================
class TheNumberGameDiv2 {
public:
    int minimumMoves(int A, int B);

};

string itoa(int num) {
    string str;
    str = "";
    while (num) {
        str += (num % 10) + '0';
        num /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}

struct node {
    string str;
    int len;
}tmp;

node make_node(string str, int len)
{
    node a;
    a.str = str;
    a.len = len;
    return a;
}

map<string, int> mp;
set<string> st;
queue<node> q;
set<string>::iterator it;

int bfs(string strA, string strB) {
    while (!q.empty()) {
        q.pop();
    }
    q.push(make_node(strA, 0));
    string str;
    int len = 0;
    st.clear();
    st.insert(strA);
    while (!q.empty()) {
        tmp = q.front();
        debug(tmp.str);
        q.pop();
        if (tmp.str.length() < strB.length()) {
            continue;
        }
        str = tmp.str.substr(0, tmp.str.length() - 1);
        //str = tmp.str;
        len = str.length();
        debug(len);
        debug(str);
        if (strcmp(str.c_str(), strB.c_str()) == 0) {
            return tmp.len + 1;
        } else {
            it = st.find(str);
            if (it == st.end()) {
                q.push(make_node(str, tmp.len + 1));
                st.insert(str);
            }
        }

        str = tmp.str;
        reverse(str.begin(), str.end());
        debug(str);

        if (strcmp(str.c_str(), strB.c_str()) == 0) {
            return tmp.len + 1;
        } else {
            it = st.find(str);
            if (it == st.end()) {
                q.push(make_node(str, tmp.len + 1));
                st.insert(str);
            }
        }
    }
    return -1;
}
//=======================================================================
int TheNumberGameDiv2 :: minimumMoves(int A, int B) {
        int res;
        char buff[30];
        string strA = itoa(A);
        string strB = itoa(B);
        if (strA.length() < strB.length()) {
            return -1;
        }

        mp.clear();
        st.clear();

        debug(strA);
        debug(strB);
        res = bfs(strA, strB);
        
        return res;
}
//=======================================================================

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.\n";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".\n";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE

// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        TheNumberGameDiv2 theObject;
        eq(0, theObject.minimumMoves(25, 5),2);
    }
    {
        TheNumberGameDiv2 theObject;
        eq(1, theObject.minimumMoves(5162, 16),4);
    }
    {
        TheNumberGameDiv2 theObject;
        eq(2, theObject.minimumMoves(334, 12),-1);
    }
    {
        TheNumberGameDiv2 theObject;
        eq(3, theObject.minimumMoves(218181918, 9181),6);
    }
    {
        TheNumberGameDiv2 theObject;
        eq(4, theObject.minimumMoves(9798147, 79817),-1);
    }
	while(true);
	return 0;
}
// END CUT HERE

