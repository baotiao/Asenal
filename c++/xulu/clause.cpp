#include <iostream>
#include "clause.h"


using namespace std;
using namespace Sat;


void Clause::readClause(istream& is)
{
  static int lit = 0;
  if (lit != 0) addLiteral(lit);
  while (!is.eof()) {
    is >> lit;
    if (lit == 0) break;
    addLiteral(lit);
  }
  is >> lit;
}


void Clause::dumpClause() const
{
  int i;
  cout << "(";
  for (i = 0; i < numLits() - 1; ++i) {
    cout << getLit(i) << ", ";
  }
  if (numLits() != 0) {
    cout << getLit(i);
  }
  cout << ")" << endl;
}
