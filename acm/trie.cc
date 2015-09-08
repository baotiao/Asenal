#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring> 
#include <string>
#include <cmath> 
#include <vector> 
#include <stack>
#include <queue> 
#include <map>
#include <ctime>
#include <set>
typedef long long lld; 
using namespace std; 
#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#define debug2(x, y) cout<<__LINE__<<" "<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl;
#else
#define debug(x)
#define debug2(x, y)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7fffffff 
#define MIN 0x80000000
#define N 16000010
#define PRIME 999983
class Stack {
public:
  queue<int> q1;
  queue<int> q2;
  // Push element x onto stack.
  void push(int x) {
    q1.push(x);
  }

  // Removes the element on top of the stack.
  void pop() {
    int tmp;
    while (!q1.empty()) {
      tmp = q1.front();
      q1.pop();
      if (!q1.empty()) {
        q2.push(tmp);
      }
    }
    queue<int> tq = q1;
    q1 = q2;
    q2 = tq;
  }
  // Get the top element.
  int top() {
    int tmp;
    while (!q1.empty()) {
      tmp = q1.front();
      q2.push(tmp);
      q1.pop();
    }
    queue<int> tq = q1;
    q1 = q2;
    q2 = tq;

    return tmp;
  }

  // Return whether the stack is empty.
  bool empty() {
    if (q1.empty() && q2.empty()) {
      return true;
    }
    return false;

  }

};
