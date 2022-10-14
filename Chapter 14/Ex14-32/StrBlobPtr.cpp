#include "StrBlobPtr.h"
#include "StrBlob.h"

using namespace std;

StrBlobPtr::StrBlobPtr() : wptr(), curr(0) {}
StrBlobPtr::StrBlobPtr(StrBlob &sb, size_type pos)
    : wptr(sb.data), curr(pos) {}

shared_ptr<vector<string>>
StrBlobPtr::check(size_type pos, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (pos >= ret->size())
        throw out_of_range(msg);
    return ret;
}

string &StrBlobPtr::operator*() const
{
    auto sp = check(curr, "deference past end of StrBlobPtr");
    return (*sp)[curr];
}

string *StrBlobPtr::operator->() const
{
    return &**this;
}

StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    auto ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator--()
{
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    auto ret = *this;
    --*this;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(int n)
{
    curr += n;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(int n)
{
    return *this += -n;
}

StrBlobPtr StrBlobPtr::operator+(int n) const
{
    StrBlobPtr ret = *this;
    return ret += n;
}

StrBlobPtr StrBlobPtr::operator-(int n) const
{
    StrBlobPtr ret = *this;
    return ret -= n;
}

int StrBlobPtr::operator-(const StrBlobPtr &rhs) const
{
    return curr - rhs.curr;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return rhs < lhs;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs < rhs);
}