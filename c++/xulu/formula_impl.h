#ifndef formula_impl_h
#define formula_impl_h

#include <iostream>
#include <fstream>
#include <vector>

#include "formula.h"
#include "clause.h"
#include "clause_impl.h"

using namespace std;
using namespace Sat;
class FormulaImpl: public Formula {
    private:
        
    public:
        vector<ClauseImpl> clauseList;
        FormulaImpl();
        ~FormulaImpl();
        Clause& addClause();
        int numClauses() const;
        Clause& getClause(int);
        bool consistent();
        bool emptyClause();
        bool unitClause();
        bool pureClause();
        void updateClause(int);
        void unit_propagate();
        void pure_literal_assign();
};
#endif
