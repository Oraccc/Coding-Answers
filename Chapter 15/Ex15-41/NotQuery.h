#ifndef NOTQUERY_H
#define NOTQUERY_H

class TextQuery;
class QueryResult;

#include <string>
#include <memory>
#include "Query.h"
#include "Query_base.h"

using namespace std;

class NotQuery : public Query_base
{
    friend Query operator~(const Query &);

    NotQuery(const Query &query) : q(query) {}

    QueryResult eval(const TextQuery &) const override;
    std::string rep() const override
    {
        return "~(" + q.rep() + ")";
    }

    Query q;
};

Query operator~(const Query &);

#endif