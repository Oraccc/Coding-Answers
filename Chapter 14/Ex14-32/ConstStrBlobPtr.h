#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H

class StrBlob;

#include <vector>
#include <string>
#include <memory>

using namespace std;

class ConstStrBlobPtr
{
    friend bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
    friend bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

public:
    typedef vector<string>::size_type size_type;

    ConstStrBlobPtr();
    explicit ConstStrBlobPtr(const StrBlob &sb, size_type pos = 0);

    const string &operator[](size_type n) const { return (*wptr.lock())[n]; }

    const string &operator*() const;
    const string *operator->() const;

    ConstStrBlobPtr &operator++();
    ConstStrBlobPtr operator++(int);
    ConstStrBlobPtr &operator--();
    ConstStrBlobPtr operator--(int);

    ConstStrBlobPtr &operator+=(int);
    ConstStrBlobPtr &operator-=(int);
    ConstStrBlobPtr operator+(int) const;
    ConstStrBlobPtr operator-(int) const;
    int operator-(const ConstStrBlobPtr &) const;

private:
    weak_ptr<vector<string>> wptr;
    size_type curr;

    shared_ptr<vector<string>>
    check(size_type pos, const string &msg) const;
};

bool operator==(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator!=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator<=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);
bool operator>=(const ConstStrBlobPtr &, const ConstStrBlobPtr &);

#endif