#ifndef TEXTQUERY_H
#define TEXTQUERY_H

class QueryResult;

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;

class TextQuery 
{
public:
    typedef vector<string>::size_type line_no;

    explicit TextQuery(ifstream &in);

    QueryResult query(const string &word) const;

private:
    shared_ptr<vector<string>> text;
    map<string, shared_ptr<set<line_no>>> word_map;
};

#endif