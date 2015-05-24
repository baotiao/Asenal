#include <iostream>
#include <map>
#include <vector>

#define N 10

using namespace std;

#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;

struct node {
    int cnt;
    double ang;
}q[4];

bool cmp(node a, node b)
{
    return a.cnt < b.cnt;
}

bool cmp1(node a, node b)
{
    return a.ang < b.ang;
}

int main(int argc, char *argv[])
{
    return 0;
}
