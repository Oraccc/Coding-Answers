#include "NotQuery.h"
#include <memory>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

QueryResult NotQuery::eval(const TextQuery &t) const
{
    auto result = q.eval(t);
    auto ret_lines = make_shared<set<line_no_type>>();
    auto bg = result.cbegin(), ed = result.cend();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n)
    {
        if (bg == ed || *bg != n)
            ret_lines->insert(n);
        else if (bg != ed)
            ++bg;
    }
    return QueryResult(rep(), ret_lines->size(), ret_lines, result.get_file());
}

Query operator~(const Query &query)
{
    return new NotQuery(query);
}