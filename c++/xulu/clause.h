#ifndef clause_h
#define clause_h

#include <fstream>

namespace Sat {

class Clause {

public:
  // Constructor and Destructor
  Clause() {}
  virtual ~Clause() {}

  // Read the clause from the input stream
  void readClause(std::istream& is);

  // Dump the clause to cout
  void dumpClause() const;

  // Add a literal to the clause
  virtual void addLiteral(int lit) = 0;

  // Get the largest variable in the clause
  virtual int maxVar() const = 0;

  // Get the number of variables in the clause
  virtual int numLits() const = 0;

  // Get the i^th literal in the clause
  virtual int getLit(int i) const = 0;
};

} // end of namespace Sat

#endif
