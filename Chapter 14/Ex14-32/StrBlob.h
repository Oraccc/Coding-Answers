#ifndef STRBLOB_H
#define STRBLOB_H

class StrBlobPtr;
class ConstStrBlobPtr;

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <iostream>

using namespace std;

class StrBlob
{
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);
    friend bool operator<(const StrBlob &, const StrBlob &);
    friend bool operator>(const StrBlob &, const StrBlob &);
    friend bool operator<=(const StrBlob &, const StrBlob &);
    friend bool operator>=(const StrBlob &, const StrBlob &);

public:
    typedef vector<string>::size_type size_type;

    StrBlob();
    StrBlob(initializer_list<string> il);

    StrBlob(const StrBlob &);
    StrBlob &operator=(const StrBlob &);

    string &operator[](size_type n) { return (*data)[n]; }
    const string &operator[](size_type n) const { return (*data)[n]; }

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const string &s);
    void push_back(string &&s);
    void pop_back();

    string &front();
    const string &front() const;
    string &back();
    const string &back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;

private:
    shared_ptr<vector<string>> data;

    void check(size_type pos, const string &msg) const;
};

bool operator==(const StrBlob &, const StrBlob &);
bool operator!=(const StrBlob &, const StrBlob &);
bool operator<(const StrBlob &, const StrBlob &);
bool operator>(const StrBlob &, const StrBlob &);
bool operator<=(const StrBlob &, const StrBlob &);
bool operator>=(const StrBlob &, const StrBlob &);

inline void StrBlob::push_back(const string &s)
{
    data->push_back(s);
}

inline void StrBlob::push_back(string &&s)
{
    cout << "StrBlob::push_back(string &&s)" << endl;
    data->push_back(move(s));
}

#endif