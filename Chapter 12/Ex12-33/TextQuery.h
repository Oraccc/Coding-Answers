#ifndef TEXTQUERY_H
#define TEXTQUERY_H

class QueryResult;

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include "StrBlob.h"

using namespace std;

class TextQuery 
{
public:
    typedef StrBlob::size_type line_no;

    TextQuery(ifstream &);

    QueryResult query(const string &) const;

private:
    shared_ptr<StrBlob> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

#endif