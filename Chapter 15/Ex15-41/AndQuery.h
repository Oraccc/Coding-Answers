#ifndef ANDQUERY_H
#define ANDQUERY_H

class TextQuery;
class QueryResult;

#include <string>
#include "BinaryQuery.h"

using namespace std;

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);

    AndQuery(const Query &l, const Query &r) : BinaryQuery(l, r, "&"){}

    QueryResult eval(const TextQuery &) const override;
};

Query operator&(const Query &, const Query &);

#endif