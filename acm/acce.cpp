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
#define debug(x) cout<<#x<<"="<<x<<endl;
#define here cout<<"_______________here "<<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 16000010
#define PRIME 999983

int main()
{
    vector<int> firstvector, secondvector;
    for (int i=1; i<=5; i++)
    { firstvector.push_back(i); secondvector.push_back(i*10); }

    copy (secondvector.begin(),secondvector.end(),back_inserter(firstvector));

    vector<int>::iterator it;
    for ( it = firstvector.begin(); it!= firstvector.end(); ++it )
        cout << *it << " ";
    cout << endl;
    return 0;
}
