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
#define N 30
#define PRIME 999983


//=======================================================================
class CityMap {
public:
    string getLegend(vector <string> cityMap, vector <int> POIs);

};
//=======================================================================
string CityMap :: getLegend(vector <string> cityMap, vector <int> POIs) {
    string res;
    int a[N];
    clr(a, 0);
    res = "";
    int cLen = cityMap.size();
    int len;
    for (int i = 0; i < cLen; i++) {
        len = cityMap[i].length();
        for (int j = 0; j < len; j++) {
            if (cityMap[i][j] == '.') {
            } else {
                a[cityMap[i][j] - 'A']++;
            }
        }
    }
    int plen = POIs.size();
    for (int i = 0; i < plen; i++) {
        for (int j = 0; j < 26; j++) {
            if (a[j] == POIs[i]) {
                res += ('A' + j);
                break;
            }
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
        string cityMapARRAY[] = {"M....M",
            "...R.M",
            "R..R.R"};
        vector <string> cityMap( cityMapARRAY, cityMapARRAY+ARRSIZE(cityMapARRAY) );
        int POIsARRAY[] = {3, 4};
        vector <int> POIs( POIsARRAY, POIsARRAY+ARRSIZE(POIsARRAY) );
        CityMap theObject;
        eq(0, theObject.getLegend(cityMap, POIs),"MR");
    }
    {
        string cityMapARRAY[] = {"XXXXXXXZXYYY"};
        vector <string> cityMap( cityMapARRAY, cityMapARRAY+ARRSIZE(cityMapARRAY) );
        int POIsARRAY[] = {1, 8, 3};
        vector <int> POIs( POIsARRAY, POIsARRAY+ARRSIZE(POIsARRAY) );
        CityMap theObject;
        eq(1, theObject.getLegend(cityMap, POIs),"ZXY");
    }
    {
        string cityMapARRAY[] = {"...........",
            "...........",
            "...........",
            "..........T"};
        vector <string> cityMap( cityMapARRAY, cityMapARRAY+ARRSIZE(cityMapARRAY) );
        int POIsARRAY[] = {1};
        vector <int> POIs( POIsARRAY, POIsARRAY+ARRSIZE(POIsARRAY) );
        CityMap theObject;
        eq(2, theObject.getLegend(cityMap, POIs),"T");
    }
    {
        string cityMapARRAY[] = {"AIAAARRI.......GOAI.",
            ".O..AIIGI.OAAAGI.A.I",
            ".A.IAAAARI..AI.AAGR.",
            "....IAI..AOIGA.GAIA.",
            "I.AIIIAG...GAR.IIAGA",
            "IA.AOA....I....I.GAA",
            "IOIGRAAAO.AI.AA.RAAA",
            "AI.AAA.AIR.AGRIAAG..",
            "AAAAIAAAI...AAG.RGRA",
            ".J.IA...G.A.AA.II.AA"}
           ;
        vector <string> cityMap( cityMapARRAY, cityMapARRAY+ARRSIZE(cityMapARRAY) );
        int POIsARRAY[] = {16,7,1,35,11,66}
           ;
        vector <int> POIs( POIsARRAY, POIsARRAY+ARRSIZE(POIsARRAY) );
        CityMap theObject;
        eq(3, theObject.getLegend(cityMap, POIs),"GOJIRA");
    }
	while(true);
	return 0;
}
// END CUT HERE

