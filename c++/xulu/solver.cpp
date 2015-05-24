#include <iostream>
#include <algorithm>
#include <vector>

#include "clause.h"
#include "clause_impl.h"
#include "formula.h"
#include "formula_impl.h"
#include "solver.h"

using namespace std;
using namespace Sat;

bool Solver::solve(FormulaImpl f)
{
    //printf("=======================\n");
    //f.dumpClauses();
    if (f.consistent()) {
        return true;
    } else if (f.emptyClause()) {
        return false;
    } else if (f.unitClause()) {
        return solve(f);
    } else if (f.pureClause()) {
        return solve(f);
    }
    int lit = f.clauseList.at(0).literalList.at(0);
    FormulaImpl ftmp = f;
    ftmp.updateClause(lit);
    if (solve(ftmp)) {
        return true;
    }
    ftmp = f;
    ftmp.updateClause(-1 * lit);
    if (solve(ftmp)) {
        return true;
    }
    return false;
}
