#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class HasPtr 
{
friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const string &s = string())
        : ps(new string(s)), i(0) {}
    HasPtr(const char *cs) : ps(new string(cs)), i(0) {}

    ~HasPtr();
    HasPtr(const HasPtr &rhs)
        : ps(new string(*rhs.ps)), i(rhs.i) 
    {
        cout << "HasPtr::HasPtr(const HasPtr &rhs)" << endl;
    }

#ifndef COPY_N_SWAP_ASSIGNMENT_OP
    HasPtr &operator=(const HasPtr &rhs);
#endif
    HasPtr(HasPtr &&rhs) noexcept : ps(rhs.ps), i(rhs.i) 
    {
        rhs.ps = nullptr;
        cout << "HasPtr::HasPtr(HasPtr &&rhs)" << endl;
    }
#ifndef COPY_N_SWAP_ASSIGNMENT_OP
    HasPtr &operator=(HasPtr &&rhs) noexcept;
#endif

#ifdef COPY_N_SWAP_ASSIGNMENT_OP
    HasPtr &operator=(HasPtr rhs);
#endif

    void swap(HasPtr &rhs);
    bool operator<(const HasPtr &rhs) const;

    const string &get() const { return *ps; }
    void set(const string &s) { *ps = s; }

private:
    string *ps;
    int i;
};

void HasPtr::swap(HasPtr &rhs) 
{
    cout << "HasPtr::swap(HasPtr &rhs)" << endl;
    using std::swap;
    swap(ps, rhs.ps);
    swap(i, rhs.i);
}

void swap(HasPtr &lhs, HasPtr &rhs) 
{
    cout << "swap(HasPtr &lhs, HasPtr &rhs)" << endl;
    lhs.swap(rhs);
}

HasPtr::~HasPtr() 
{
    delete ps;
}

#ifndef COPY_N_SWAP_ASSIGNMENT_OP
HasPtr &HasPtr::operator=(const HasPtr &rhs) 
{
    cout << "HasPtr::operator=(const HasPtr &rhs)" << endl;
    auto newps = new string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept 
{
    cout << "HasPtr::operator=(HasPtr &&rhs)" << endl;
    if (this != &rhs) {
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
    }
    return *this;
}
#endif

#ifdef COPY_N_SWAP_ASSIGNMENT_OP
HasPtr &HasPtr::operator=(HasPtr rhs) 
{
    ::swap(*this, rhs);
    return *this;
}
#endif

bool HasPtr::operator<(const HasPtr &rhs) const 
{
    return *ps < *rhs.ps;
}

void testHasPtrVec(vector<HasPtr> &v) 
{
    cout << "\nBefore sort " << v.size() << " elements:\n";
    for (const auto &e : v)
        cout << e.get() << endl;
    cout << "\nSorting:\n";
    sort(v.begin(), v.end());
    cout << "\nAfter sort:\n";
    for (const auto &e : v)
        cout << e.get() << endl;
}

int main() 
{
    HasPtr hp1 = "str1";

    cout << "=== copy constructor ===\n";
    HasPtr hp2 = hp1;
    cout << hp1.get() << endl;
    cout << hp2.get() << endl;

    cout << "=== copy-assignment operator ===\n";
    HasPtr hp3;
    hp3 = hp1;
    cout << hp1.get() << endl;
    cout << hp3.get() << endl;

    cout << "=== move constructor ===\n";
    HasPtr hp4 = std::move(hp1);
    cout << hp4.get() << endl;

    cout << "=== move-assignment operator ===\n";
    hp1 = std::move(hp4);
    cout << hp1.get() << endl;

    return 0;
}