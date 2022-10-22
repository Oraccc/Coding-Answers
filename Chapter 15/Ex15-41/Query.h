#ifndef QUERY_H
#define QUERY_H

class TextQuery;
class QueryResult;
class Query_base;

#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Query
{
    friend Query operator~(const Query &);
    friend Query operator&(const Query &, const Query &);
    friend Query operator|(const Query &, const Query &);

public:
    Query(const string &);

    ~Query();
    Query(const Query &);
    Query &operator=(const Query &);

    QueryResult eval(const TextQuery &t) const;
    string rep() const;

private:
    Query(Query_base *&&query) : pq(query), ref_count(new size_t(1))
    {
        query = nullptr;
    }

    Query_base *pq;
    size_t *ref_count;
};

inline ostream &operator<<(ostream &os, const Query &q)
{
    return os << q.rep();
}

#endif
