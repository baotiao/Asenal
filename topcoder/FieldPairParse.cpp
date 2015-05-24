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
class FieldPairParse {
public:
    vector <int> getPairs(vector <string> data);

};
//=======================================================================
vector <int> FieldPairParse :: getPairs(vector <string> data) {
        vector <int> res;
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
        string dataARRAY[] = {
           "XXXXX    XXXXX",
           "XXXX    XXXXX "
           };
        vector <string> data( dataARRAY, dataARRAY+ARRSIZE(dataARRAY) );
        int retrunValueARRAY[] = {3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FieldPairParse theObject;
        eq(0, theObject.getPairs(data),retrunValue);
    }
    {
        string dataARRAY[] = {
           "XXXXXXXXXX     XXXXXXXXXXX",
           "XXXXXXXXXXXXXXXXX    XXXXX"
           };
        vector <string> data( dataARRAY, dataARRAY+ARRSIZE(dataARRAY) );
        FieldPairParse theObject;
        eq(1, theObject.getPairs(data),vector <int>());
    }
    {
        string dataARRAY[] = {
           "X X X",
           "X X X"
           };
        vector <string> data( dataARRAY, dataARRAY+ARRSIZE(dataARRAY) );
        FieldPairParse theObject;
        eq(2, theObject.getPairs(data),vector <int>());
    }
    {
        string dataARRAY[] = {
           "XXXX      X  X           X X   X",
           "XX       XXX XX   X   X   X XXX "
           };
        vector <string> data( dataARRAY, dataARRAY+ARRSIZE(dataARRAY) );
        int retrunValueARRAY[] = {5, 1, 3, 3, 2 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FieldPairParse theObject;
        eq(3, theObject.getPairs(data),retrunValue);
    }
    {
        string dataARRAY[] = {"XXXX      X  X           X X   X"};
        vector <string> data( dataARRAY, dataARRAY+ARRSIZE(dataARRAY) );
        int retrunValueARRAY[] = {6, 2, 11, 1, 3 };
        vector <int> retrunValue( retrunValueARRAY, retrunValueARRAY+ARRSIZE(retrunValueARRAY) );
        FieldPairParse theObject;
        eq(4, theObject.getPairs(data),retrunValue);
    }
    {
        string dataARRAY[] = {"XXX XXX XXX XXX XXX"};
        vector <string> data( dataARRAY, dataARRAY+ARRSIZE(dataARRAY) );
        FieldPairParse theObject;
        eq(5, theObject.getPairs(data),vector <int>());
    }
	while(true);
	return 0;
}
// END CUT HERE

