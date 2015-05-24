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
class SkiResortsEasy {
public:
    int minCost(vector <int> altitude);

};
//=======================================================================
int SkiResortsEasy :: minCost(vector <int> altitude) {
    int res;
    int len = altitude.size();
    res = 0;
    int now = altitude[0];
    for (int i = 1; i < len; i++) {
        if (altitude[i] > now) {
            res += altitude[i] - now;
        } else {
            now = altitude[i];
        }


    }
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
        int altitudeARRAY[] = {30, 20, 20, 10};
        vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
        SkiResortsEasy theObject;
        eq(0, theObject.minCost(altitude),0);
    }
    {
        int altitudeARRAY[] = {5, 7, 3};
        vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
        SkiResortsEasy theObject;
        eq(1, theObject.minCost(altitude),2);
    }
    {
        int altitudeARRAY[] = {6, 8, 5, 4, 7, 4, 2, 3, 1};
        vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
        SkiResortsEasy theObject;
        eq(2, theObject.minCost(altitude),6);
    }
    {
        int altitudeARRAY[] = {749, 560, 921, 166, 757, 818, 228, 584, 366, 88};
        vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
        SkiResortsEasy theObject;
        eq(3, theObject.minCost(altitude),2284);
    }
    {
        int altitudeARRAY[] = {712, 745, 230, 200, 648, 440, 115, 913, 627, 621, 186, 222, 741, 954, 581, 193, 266, 320, 798, 745};
        vector <int> altitude( altitudeARRAY, altitudeARRAY+ARRSIZE(altitudeARRAY) );
        SkiResortsEasy theObject;
        eq(4, theObject.minCost(altitude),6393);
    }
	while(true);
	return 0;
}
// END CUT HERE

