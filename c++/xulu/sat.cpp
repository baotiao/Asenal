#include <iostream>
#include "debug.h"
#include "formula_impl.h"
#include "solver.h"


using namespace std;
using namespace Sat;


int main(int argc, char **argv)
{
    if (argc != 2) {
        cout << "Expected filename" << endl;
        return 0;
    }
    istream* is = new ifstream(*(argv+1));
    if (!(*is)) {
        cout << "File not found" << endl;
        return 0;
    }
    FormulaImpl f;
    f.readClauses(*is);
    Assert(f.numClauses() > 0);

    f.dumpClauses();
    Solver sat;
    if (sat.solve(f)) {
        cout << "Satisfiable" << endl;
    }
    else {
        cout << "Unsatisfiable" << endl;
    }

    return 0;
}
