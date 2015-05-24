#ifndef solver_h
#define solver_h

#include <iostream>
#include <algorithm>
#include "clause.h"
#include "clause_impl.h"
#include "formula.h"
#include "formula_impl.h"

using namespace std;
using namespace Sat;

class Solver{
    public:
        bool solve(FormulaImpl f);
};

#endif
