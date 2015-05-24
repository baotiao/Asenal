#include <iostream>
#include <map>
#include <vector>
#include <set>

#define N 10

using namespace std;

#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;


int main(int argc, char *argv[])
{
    multiset<int> st;
    st.insert(1);
    debug(st.count(1));
    st.insert(1);
    debug(st.count(1));
    multiset<int>::iterator it;
    it = st.begin();
    it++;
    st.erase(it);
    debug(st.count(1));
    debug(st.count(10));
    return 0;
}
