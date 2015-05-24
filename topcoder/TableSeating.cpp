/* CopyRight (c) cnHawk */

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
class TableSeating {
public:
    double getExpected(int numTables, vector <int> probs);

};
//=======================================================================
double TableSeating :: getExpected(int numTables, vector <int> probs) {
        double res;
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
        int probsARRAY[] = {100};
        vector <int> probs( probsARRAY, probsARRAY+ARRSIZE(probsARRAY) );
        TableSeating theObject;
        eq(0, theObject.getExpected(4, probs),4.0);
    }
    {
        int probsARRAY[] = {0,100};
        vector <int> probs( probsARRAY, probsARRAY+ARRSIZE(probsARRAY) );
        TableSeating theObject;
        eq(1, theObject.getExpected(4, probs),3.3333333333333335);
    }
    {
        int probsARRAY[] = {0,0,0,0,0,50,50};
        vector <int> probs( probsARRAY, probsARRAY+ARRSIZE(probsARRAY) );
        TableSeating theObject;
        eq(2, theObject.getExpected(5, probs),0.0);
    }
    {
        int probsARRAY[] = {9,9,9,9,9,9,9,9,9,9,10};
        vector <int> probs( probsARRAY, probsARRAY+ARRSIZE(probsARRAY) );
        TableSeating theObject;
        eq(3, theObject.getExpected(12, probs),7.871087929710551);
    }
	while(true);
	return 0;
}
// END CUT HERE

