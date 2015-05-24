#ifndef clause_impl_h
#define clause_impl_h

#include <iostream>

#include "clause.h"
#include "formula.h"

using namespace Sat;
using namespace std;

class ClauseImpl: public Clause {
    private:
    public:
        vector<int> literalList;
        int maxNum;
        ClauseImpl() {};
        ~ClauseImpl(); 
        void addLiteral(int);
        int maxVar() const; 
        int numLits() const;
        int getLit(int) const;
        //void deleteLiteral(int);
};
#endif
