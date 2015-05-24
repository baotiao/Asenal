#include <stdio.h>
#include <iostream>

#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(11);
    v.push_back(1);

    vector<int>::iterator iter;

    map<string, int> mp;

    map<string, int>::iterator mp_iter;

    iter = v.begin();
    for (; iter != v.end(); iter++) {
        printf("%d\n", *iter);
    }


    pair<int, int> p(10, 11);

    cout << p.first << endl;

    pair<double, double> poi(10.1, 11.1);
    pair<double, double> poi1(10.1, 11.1);



    set<int> st;
    st.insert(10);

    return 0;
}
