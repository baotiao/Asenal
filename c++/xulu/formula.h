#ifndef formula_h
#define formula_h

#include <fstream>
#include <vector>

namespace Sat {

class Clause;

class Formula {
  int maxVar;  // maximum variable in this formula

public:
  // Constructor and Destructor
  Formula() : maxVar(0) {}
  virtual ~Formula() {}

  // Read the formula from the input stream
  void readClauses(std::istream& is);

  // Dump formuls to cout
  void dumpClauses();

  // Add a new Clause to the Formula
  // Return a reference to the new clause
  virtual Clause& addClause() = 0;

  // Get the number of clauses
  virtual int numClauses() const = 0;

  // Get the i^th clause in the formula
  virtual Clause& getClause(int i) = 0;
};

} // end of namespace Sat

#endif
