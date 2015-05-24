#include <iostream>
#include <algorithm>
#include "clause_impl.h"

using namespace std;
using namespace Sat;

ClauseImpl::~ClauseImpl()
{
    literalList.clear();
}

void ClauseImpl::addLiteral(int lit)
{
    literalList.push_back(lit);
    if (literalList.size() == 1) {
        maxNum = lit;
    } else {
        maxNum = max(maxNum, lit);
    }
}

int ClauseImpl::maxVar() const
{
    return maxNum;
}

int ClauseImpl::numLits() const
{
    return literalList.size();
}

int ClauseImpl::getLit(int i) const
{
    return literalList.at(i);
}

