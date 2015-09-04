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

  std::vector<std::string> path_;

private:
  int flag_;
  std::string name_;
  std::list<Node *> children_;


  Node(const Node&);
  void operator=(const Node&);
};


int FindPath(Node *node, std::map<std::string, int> &path, std::vector<std::string> &ans)
{
  
  if (path[node->name()] != -1) {
    return path[node->name()];
  }
  if (node->children().empty()) {
    node->path_.push_back(node->name());
    path[node->name()] = 0;
    ans = node->path_;
    return path[node->name()];
  }

  std::list<Node *>::iterator iter;
  int tmp;
  for (iter = node->children().begin(); iter != node->children().end(); iter++) {
    tmp = FindPath((*iter), path, ans) + 1;
    if (path[node->name()] < tmp) {
      node->path_ = (*iter)->path_;
      node->path_.push_back(node->name());
      path[node->name()] = tmp;
    }
  }
  ans = node->path_;
  return path[node->name()];
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
  c->AddChild(e);
  d->AddChild(e);

  std::map<std::string, int> path;
  path["a"] = -1;
  path["b"] = -1;
  path["c"] = -1;
  path["d"] = -1;
  path["e"] = -1;

  std::vector<std::string> ans;

  int res = FindPath(a, path, ans);

  printf("ans is %d\n", res);
  std::vector<std::string>::iterator iter;
  for (iter = ans.begin(); iter != ans.end(); iter++) {
    std::cout << *iter << std::endl;
  }



  delete(a);
  delete(b);
  delete(c);
  delete(d);
  delete(e);
  return 0;
}

