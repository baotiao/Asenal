#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>

#include "formula.h"
#include "clause.h"
#include "clause_impl.h"
#include "formula_impl.h"
#include "debug.h"

using namespace std;
using namespace Sat;

FormulaImpl::FormulaImpl()
{
    clauseList.clear();
}

FormulaImpl::~FormulaImpl()
{
    clauseList.clear();
}

Clause& FormulaImpl::addClause()
{
    ClauseImpl *tmp = new ClauseImpl();
    clauseList.push_back(*tmp);
    return clauseList.at(clauseList.size() - 1);
}

int FormulaImpl::numClauses() const
{
    return clauseList.size();
}

Clause& FormulaImpl::getClause(int i)
{
    return clauseList.at(i);
}

bool FormulaImpl::consistent()
{
    //Assert(clauseList.size());
    if (clauseList.size() == 0) {
        return true;
    }
    return false;
}

bool FormulaImpl::emptyClause()
{
    for (int i = 0; i < clauseList.size(); i++) {
        if (clauseList.at(i).literalList.size() == 0) {
            return true;
        }
    }
    return false;
}

bool FormulaImpl::unitClause()
{
    int lit;
    vector<ClauseImpl>::iterator it;
    vector<int>::iterator intit;
    int flag = 0;
    int fenter = 0;
    while (1) {
        flag = 0;
        for (int i = 0; i < clauseList.size(); i++) {
            if (clauseList.at(i).literalList.size() == 1) {
                lit = clauseList.at(i).literalList.at(0);
                it = clauseList.begin();
                clauseList.erase(it + i);
                for (int j = 0; j < clauseList.size(); j++) {
                    intit = find(clauseList.at(j).literalList.begin(), clauseList.at(j).literalList.end(), lit);
                    if (intit != clauseList.at(j).literalList.end()) {
                        it = clauseList.begin();
                        clauseList.erase(it + j);
                        j--;
                        continue;
                    }
                    intit = find(clauseList.at(j).literalList.begin(), clauseList.at(j).literalList.end(), -lit);
                    if (intit != clauseList.at(j).literalList.end()) {
                        clauseList.at(j).literalList.erase(intit);
                    }
                }
                flag = 1;
                fenter = 1;
                break;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    if (fenter == 0) {
        return false;
    }
    return true;
}

bool FormulaImpl::pureClause()
{
    set<int> literals;
    for (int i = 0; i < clauseList.size(); i++) {
        for (int j = 0; j < clauseList.at(i).literalList.size(); j++) {
            literals.insert(clauseList.at(i).literalList.at(j));
        }
    }
    set<int>::iterator iter = literals.begin();
    set<int>::iterator findit;
    set<int> ans = literals;
    vector<int>::iterator initer;
    for (;iter != literals.end(); iter++) {
        findit = literals.find(*iter * -1);
        if (findit != literals.end()) {
            if (ans.find(*iter) != ans.end()) {
                ans.erase(ans.find(*iter));
            }
            if (ans.find(*iter * -1) != ans.end()) {
                ans.erase(ans.find(*iter * -1));
            }
        }
    }
    int flag = 0;
    for (iter = ans.begin(); iter != ans.end(); iter++) {
        for(int j = 0; j < clauseList.size(); j++) {
            initer = find(clauseList.at(j).literalList.begin(), clauseList.at(j).literalList.end(), *iter);
            if (initer != clauseList.at(j).literalList.end()) {
                clauseList.erase(clauseList.begin() + j);
                j--;
                flag = 1;
            }
        }
    }
    if (flag) {
        return true;
    }
    return false;
}

void FormulaImpl::updateClause(int lit)
{
    vector<int>::iterator iter;
    for (int i = 0; i < clauseList.size(); i++) {
        iter = find(clauseList.at(i).literalList.begin(), clauseList.at(i).literalList.end(), lit);
        if (iter != clauseList.at(i).literalList.end()) {
            clauseList.erase(clauseList.begin() + i);
            i--;
            continue;
        }
        iter = find(clauseList.at(i).literalList.begin(), clauseList.at(i).literalList.end(), -lit);
        if (iter != clauseList.at(i).literalList.end()) {
            clauseList.at(i).literalList.erase(iter);
        }
    }
}
