#include <iostream>
#include <fstream>

#include "StrBlob.h"
#include "StrBlobPtr.h"


StrBlobPtr::StrBlobPtr() : wptr(), curr(0) {}
StrBlobPtr::StrBlobPtr(StrBlob &sb, size_type pos) : wptr(sb.data), curr(pos) {}

shared_ptr<vector<string>> StrBlobPtr::check(size_type pos, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("Unbound StrBlobPtr");
    if (pos >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string &StrBlobPtr::deref() const 
{
    auto sp = check(curr, "Deference past end of StrBlobPtr");
    return (*sp)[curr];
}

StrBlobPtr &StrBlobPtr::inc() 
{
    check(curr, "Increment past end of StrBlobPtr");
    ++curr;
    return *this;
}