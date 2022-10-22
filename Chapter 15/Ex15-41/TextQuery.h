#ifndef TEXTQUERY_H
#define TEXTQUERY_H

class QueryResult;

#include <fstream>
#include <string>
#include <map>
#include <set>
#include <memory>
#include "StrVec.h"

using namespace std;

class TextQuery
{
public:
    using line_no_type = StrVec::size_type;

    explicit TextQuery(ifstream &in);

    QueryResult query(const string &word) const;

private:
    string filter_str(const string &) const;
    shared_ptr<StrVec> text;
    map<string, shared_ptr<set<line_no_type>>> word_map;
};

#endif