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
class PolygonTraversal2 {
public:
    int count(int N, vector <int> points);

};
//=======================================================================
int PolygonTraversal2 :: count(int N, vector <int> points) {
        int res;
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
        int pointsARRAY[] = {1, 3, 5};
        vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
        PolygonTraversal2 theObject;
        eq(0, theObject.count(5, points),1);
    }
    {
        int pointsARRAY[] = {1, 4, 2};
        vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
        PolygonTraversal2 theObject;
        eq(1, theObject.count(6, points),1);
    }
    {
        int pointsARRAY[] = {2, 4, 7};
        vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
        PolygonTraversal2 theObject;
        eq(2, theObject.count(7, points),2);
    }
    {
        int pointsARRAY[] = {1, 2, 3, 4, 6, 5};
        vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
        PolygonTraversal2 theObject;
        eq(3, theObject.count(7, points),0);
    }
    {
        int pointsARRAY[] = {1, 5, 10};
        vector <int> points( pointsARRAY, pointsARRAY+ARRSIZE(pointsARRAY) );
        PolygonTraversal2 theObject;
        eq(4, theObject.count(11, points),1412);
    }
	while(true);
	return 0;
}
// END CUT HERE

