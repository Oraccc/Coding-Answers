#include "Query.h"
#include "WordQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"
#include "Query_base.h"

using namespace std;

Query::~Query()
{
    if (--*ref_count == 0)
    {
        delete pq;
        delete ref_count;
    }
}

Query::Query(const Query &rhs)
    : pq(rhs.pq), ref_count(rhs.ref_count)
{
    ++*ref_count;
}

Query &Query::operator=(const Query &rhs)
{
    if (this != &rhs)
    {
        if (--*ref_count == 0)
        {
            delete pq;
            delete ref_count;
        }
        pq = rhs.pq;
        ref_count = rhs.ref_count;
        ++*ref_count;
    }
    return *this;
}

Query::Query(const string &s)
    : pq(new WordQuery(s)), ref_count(new size_t(1))
{
}

QueryResult Query::eval(const TextQuery &t) const
{
    return pq->eval(t);
}

string Query::rep() const
{
    return pq->rep();
}