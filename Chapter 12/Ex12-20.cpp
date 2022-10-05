#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <iostream>
#include <fstream>

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

class StrBlobPtr {
public:
    typedef vector<string>::size_type size_type;

    StrBlobPtr();
    explicit StrBlobPtr(StrBlob &sb, size_type pos = 0);

    string &deref() const;
    StrBlobPtr &inc();

private:
    weak_ptr<vector<string>> wptr;
    size_type curr;

    shared_ptr<vector<string>>
    check(size_type pos, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

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

int main()
{
    cout << "Input the file name: ";
    string filename;
    cin >> filename;
    ifstream in(filename);

    if (!in.is_open()) {
        cerr << "Cannot open file: " << filename << endl;
        return -1;
    }
    StrBlob texts;
    for (string word; in >> word; texts.push_back(word)) {}

    StrBlobPtr p = texts.begin();
    for (StrBlob::size_type pos = 0; pos != texts.size(); ++pos, p.inc())
        cout << pos + 1 << ":\t" << p.deref() << endl;

    // The following loop cannot be compiled, because we don't define the `!=`
    // operator for `StrBlobPtr`
    //for (StrBlobPtr p = texts.begin(); p != texts.end(); p.inc())

    return 0;
}