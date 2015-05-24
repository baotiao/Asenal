#include "debug.h"
#include "clause.h"
#include "formula.h"


using namespace std;
using namespace Sat;


void Formula::readClauses(istream& is)
{
  while (!is.eof()) {
    Clause& c = addClause();
    c.readClause(is);
    int tmp = c.maxVar();
    if (tmp > maxVar) maxVar = tmp;
  }
}


void Formula::dumpClauses()
{
  for (int i = 0; i < numClauses(); ++i) {
    getClause(i).dumpClause();
  }
}
