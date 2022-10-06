#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

using namespace std;

class StrBlobPtr;

class StrBlob
{
friend class StrBlobPtr;

public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    void push_back(const string &s) {data->push_back(s);};
    void pop_back();

    string &front();
    const string &front() const;
    string &back();
    const string &back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    shared_ptr<vector<string>> data;
    void check(size_type pos, const string &msg) const;

};


#endif