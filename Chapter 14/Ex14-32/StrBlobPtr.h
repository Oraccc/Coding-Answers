#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

class StrBlob;

#include <vector>
#include <string>
#include <memory>

using namespace std;

class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

public:
    typedef vector<string>::size_type size_type;

    StrBlobPtr();
    explicit StrBlobPtr(StrBlob &sb, size_type pos = 0);

    string &operator[](size_type n) { return (*wptr.lock())[n]; }
    const string &operator[](size_type n) const { return (*wptr.lock())[n]; }

    string &operator*() const;
    string *operator->() const;

    StrBlobPtr &operator++();
    StrBlobPtr operator++(int);
    StrBlobPtr &operator--();
    StrBlobPtr operator--(int);

    StrBlobPtr &operator+=(int);
    StrBlobPtr &operator-=(int);
    StrBlobPtr operator+(int) const;
    StrBlobPtr operator-(int) const;
    int operator-(const StrBlobPtr &) const;

private:
    weak_ptr<vector<string>> wptr;
    size_type curr;

    shared_ptr<vector<string>>
    check(size_type pos, const string &msg) const;
};

bool operator==(const StrBlobPtr &, const StrBlobPtr &);
bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
bool operator<(const StrBlobPtr &, const StrBlobPtr &);
bool operator>(const StrBlobPtr &, const StrBlobPtr &);
bool operator<=(const StrBlobPtr &, const StrBlobPtr &);
bool operator>=(const StrBlobPtr &, const StrBlobPtr &);

StrBlobPtr operator+(const StrBlobPtr &, const StrBlobPtr &);
StrBlobPtr operator-(const StrBlobPtr &, const StrBlobPtr &);

#endif