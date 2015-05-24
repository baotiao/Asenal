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
class TeamContestEasy {
public:
    int worstRank(vector <int> strength);

};
//=======================================================================
int TeamContestEasy :: worstRank(vector <int> strength) {
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
        int strengthARRAY[] = {5, 7, 3, 5, 7, 3, 5, 7, 3};
        vector <int> strength( strengthARRAY, strengthARRAY+ARRSIZE(strengthARRAY) );
        TeamContestEasy theObject;
        eq(0, theObject.worstRank(strength),2);
    }
    {
        int strengthARRAY[] = {5, 7, 3};
        vector <int> strength( strengthARRAY, strengthARRAY+ARRSIZE(strengthARRAY) );
        TeamContestEasy theObject;
        eq(1, theObject.worstRank(strength),1);
    }
    {
        int strengthARRAY[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        vector <int> strength( strengthARRAY, strengthARRAY+ARRSIZE(strengthARRAY) );
        TeamContestEasy theObject;
        eq(2, theObject.worstRank(strength),1);
    }
    {
        int strengthARRAY[] = {2,2,1,1,3,1,3,2,1,3,1,2,1,2,1}
           ;
        vector <int> strength( strengthARRAY, strengthARRAY+ARRSIZE(strengthARRAY) );
        TeamContestEasy theObject;
        eq(3, theObject.worstRank(strength),4);
    }
    {
        int strengthARRAY[] = {45,72,10,42,67,51,33,21,8,51,17,72}
           ;
        vector <int> strength( strengthARRAY, strengthARRAY+ARRSIZE(strengthARRAY) );
        TeamContestEasy theObject;
        eq(4, theObject.worstRank(strength),3);
    }
    {
        int strengthARRAY[] = {570466,958327,816467,17,403,953808,734850,5824,917784,921731,161921,1734,823437,3218,81,932681,2704,981643,1232,475,873323,6558,45660,1813,4714,224,
           32301,28081,6728,17055,561,15146,842613,5559,1860,783,989,2811,20664,112531,1933,866794,805528,53821,2465,137385,39,2007};
        vector <int> strength( strengthARRAY, strengthARRAY+ARRSIZE(strengthARRAY) );
        TeamContestEasy theObject;
        eq(5, theObject.worstRank(strength),6);
    }
    {
        int strengthARRAY[] = {610297,849870,523999,6557,976530,731458,7404,795100,147040,110947,159692,40785,4949,2903,1688,37278,620703,28156,16823,1159,12132,971379,5916,1159,988589,
           12215,133,1490,911360,920059,544070,40249,514852,852,745070,1105,715897,714696,589133,698317,5683,631612,16453,101000,764881,101,2053,754661};
        vector <int> strength( strengthARRAY, strengthARRAY+ARRSIZE(strengthARRAY) );
        TeamContestEasy theObject;
        eq(6, theObject.worstRank(strength),10);
    }
	while(true);
	return 0;
}
// END CUT HERE

