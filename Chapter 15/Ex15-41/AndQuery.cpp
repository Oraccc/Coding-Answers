#include "AndQuery.h"
#include <memory>
#include <algorithm>
#include <iterator>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

QueryResult AndQuery::eval(const TextQuery &t) const
{
    auto left = lhs.eval(t), right = rhs.eval(t);
    auto ret_lines = make_shared<set<line_no_type>>();
    set_intersection(left.cbegin(), left.cend(), right.cbegin(), right.cend(),
                    inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines->size(), ret_lines, left.get_file());
}

Query operator&(const Query &lhs, const Query &rhs)
{
    return new AndQuery(lhs, rhs);
}