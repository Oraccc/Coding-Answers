#include <iostream>
#include <fstream>
#include <initializer_list>
#include "StrBlob.h"
#include "StrBlobPtr.h"

using namespace std;


StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

StrBlob::StrBlob(const StrBlob &sb)
    : data(make_shared<vector<string>>(*sb.data)) {}

StrBlob &StrBlob::operator=(const StrBlob &sb) 
{
    data = make_shared<vector<string>>(*sb.data);
    return *this;
}

void StrBlob::check(size_type pos, const string &msg) const
{
    if (pos >= data->size())
        throw out_of_range(msg);
}

void StrBlob::pop_back()
{
    check(0, "pop back on empty StrBlob");
    data->pop_back();
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

