#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <iostream>

using namespace std;

class StrBlob
{
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

private:
    shared_ptr<vector<string>> data;
    void check(size_type pos, const string &msg) const;
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

int main()
{
    StrBlob sb1;
    StrBlob sb2 = {"Hello", "World"};
    sb1 = sb2;
    sb1.push_back("Bye-Bye");
    cout << sb2.front() << " " << sb2.back() << endl;
    sb2.pop_back();
    sb2.push_back("Bye~");
    cout << sb1.front() << " " << sb1.back() << endl;
}