#include "ConstStrBlobPtr.h"
#include "StrBlob.h"

using namespace std;

ConstStrBlobPtr::ConstStrBlobPtr() : wptr(), curr(0) {}
ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &sb, size_type pos)
    : wptr(sb.data), curr(pos) {}

shared_ptr<vector<string>>
ConstStrBlobPtr::check(size_type pos, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound ConstStrBlobPtr");
    if (pos >= ret->size())
        throw out_of_range(msg);
    return ret;
}

const string &ConstStrBlobPtr::operator*() const
{
    auto sp = check(curr, "dereference past end of ConstStrBlobPtr");
    return (*sp)[curr];
}

const string *ConstStrBlobPtr::operator->() const
{
    return &**this;
}

ConstStrBlobPtr &ConstStrBlobPtr::operator++()
{
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr ConstStrBlobPtr::operator++(int)
{
    auto ret = *this;
    ++*this;
    return ret;
}

ConstStrBlobPtr &ConstStrBlobPtr::operator--()
{
    --curr;
    check(curr, "decrement past begin of ConstStrBlobPtr");
    return *this;
}

ConstStrBlobPtr ConstStrBlobPtr::operator--(int)
{
    auto ret = *this;
    --*this;
    return ret;
}

ConstStrBlobPtr &ConstStrBlobPtr::operator+=(int n)
{
    curr += n;
    return *this;
}

ConstStrBlobPtr &ConstStrBlobPtr::operator-=(int n)
{
    return *this += -n;
}

ConstStrBlobPtr ConstStrBlobPtr::operator+(int n) const
{
    ConstStrBlobPtr ret = *this;
    return ret += n;
}

ConstStrBlobPtr ConstStrBlobPtr::operator-(int n) const
{
    ConstStrBlobPtr ret = *this;
    return ret -= n;
}

int ConstStrBlobPtr::operator-(const ConstStrBlobPtr &rhs) const
{
    return curr - rhs.curr;
}

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return rhs < lhs;
}

bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs < rhs);
}