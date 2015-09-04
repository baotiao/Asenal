#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring> 
#include <string>
#include <cmath> 
#include <vector> 
#include <list>
#include <queue> 
#include <map>
#include <ctime>
#include <set>
typedef long long lld; 

#ifdef DEBUG
#define debug(x) cout<<__LINE__<<" "<<#x<<"="<<x<<endl;
#else
#define debug(x)
#endif
#define here cout<<__LINE__<< "  " << "_______________here" <<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 16000010
#define PRIME 999983

class Node {
public:

  Node(std::string name) :
    name_(name),
    flag_(0)
  {};
  ~Node() {};

  void AddChild(Node *a) {
    children_.push_back(a);
  }

  std::string name() const
  {
    return name_;
  }

  std::list<Node *>& children()
  {
    return children_;
  }
  
  int flag() const
  {
    return flag_;
  }

  void set_flag(int flag)
  {
    flag_ = flag;
  }

private:
  int flag_;
  std::string name_;
  std::list<Node *> children_;

  Node(const Node&);
  void operator=(const Node&);
};

void FindLength(Node *node, std::vector<Node *> &path, std::vector<Node *> &ans)
{
  if (node->children().empty()) {
    if (path.size() > ans.size()) {
      while (!ans.empty()) {
        ans.pop_back();
      }
      ans = path;
    }
  }

  std::list<Node *>::iterator iter;
  for (iter = node->children().begin(); iter != node->children().end(); iter++) {
    if ((*iter)->flag() == 0) {
      (*iter)->set_flag(1);
      path.push_back((*iter));
      FindLength((*iter), path, ans);
      path.pop_back();
      (*iter)->set_flag(0);
    }
  }
  
}

int main()
{

  Node *a = new Node("a");
  Node *b = new Node("b");
  Node *c = new Node("c");
  Node *d = new Node("d");
  Node *e = new Node("e");

  a->AddChild(b);
  a->AddChild(c);
  a->AddChild(d);
  b->AddChild(d);
  c->AddChild(d);
  d->AddChild(c);
  c->AddChild(e);
  d->AddChild(e);

  std::vector<Node *> path;
  std::vector<Node *> ans;
  path.push_back(a);
  ans.push_back(a);
  FindLength(a, path, ans);
  
  printf("The max length is %zu\n", ans.size());
  std::vector<Node *>::iterator iter;
  for (iter = ans.begin(); iter != ans.end(); iter++) {
    printf("%s\n", (*iter)->name().c_str());
  }

  delete(a);
  delete(b);
  delete(c);
  delete(d);
  delete(e);
  return 0;
}

