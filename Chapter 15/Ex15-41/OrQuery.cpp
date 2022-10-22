#include "OrQuery.h"
#include <memory>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

QueryResult OrQuery::eval(const TextQuery &t) const
{

    auto left = lhs.eval(t), right = rhs.eval(t);
    auto ret_lines =
        make_shared<set<line_no_type>>(left.cbegin(), left.cend());
    ret_lines->insert(right.cbegin(), right.cend());
    return QueryResult(rep(), ret_lines->size(), ret_lines, left.get_file());
}

Query operator|(const Query &lhs, const Query &rhs)
{

    return new OrQuery(lhs, rhs);
}