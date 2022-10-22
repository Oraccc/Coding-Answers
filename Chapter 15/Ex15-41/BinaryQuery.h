#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include <string>
#include "Query_base.h"
#include "Query.h"

using namespace std;

class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, const string &o)
        : lhs(l), rhs(r), op(o) {}

    string rep() const override
    {
        return "(" + lhs.rep() + " " + op + " " + rhs.rep() + ")";
    }

    Query lhs, rhs;
    string op;
};

#endif
