#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <set>
#include <string>
#include "StrVec.h"

using namespace std;

class QueryResult
{
    friend ostream &print(ostream &os, const QueryResult &qr);

public:
    using line_no_type = StrVec::size_type;

    QueryResult(const string &wd,
                line_no_type t,
                shared_ptr<set<line_no_type>> lns,
                shared_ptr<StrVec> lt)
        : word(wd), total(t), line_numbers(lns), line_text(lt) {}

    set<line_no_type>::iterator begin() { return line_numbers->begin(); }
    set<line_no_type>::iterator end() { return line_numbers->end(); }

    set<line_no_type>::const_iterator
    cbegin() const { return line_numbers->cbegin(); }

    set<line_no_type>::const_iterator
    cend() const { return line_numbers->cend(); }

    shared_ptr<StrVec> get_file() { return line_text; }

private:
    string word;
    line_no_type total;
    shared_ptr<set<line_no_type>> line_numbers;
    shared_ptr<StrVec> line_text;
};

ostream &print(ostream &os, const QueryResult &qr);

#endif