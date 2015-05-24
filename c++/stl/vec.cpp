#include<stdio.h>
#include<vector>
#include<iostream>
#include<iterator>
using namespace std;

int main()
{
    vector<int> v;
    vector<int>::iterator iter;
    v.push_back(10);
    v.push_back(11);
    for (int i=0; i<2; i++) {
        cout<<v[i]<<endl;
    }

    v.pop_back();

    for (int i=0; i<v.size(); i++) {
        cout<<v[i]<<endl;
    }

    for (iter = v.begin(); iter != v.end(); iter++) {
        cout<<*iter<<endl;
    }
    return 0;
}

