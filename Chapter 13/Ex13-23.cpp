#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &orig) : ps(new string(*orig.ps)), i(orig.i) {}

    HasPtr &operator=(const HasPtr &rhs);
    ~HasPtr();

    const string &get() const { return *ps; }
    void set(const string &s) { *ps = s; }

private:
    string *ps;
    int i;
};
HasPtr::~HasPtr()
{
    delete ps;
}

HasPtr &HasPtr::operator=(const HasPtr &rhs) 
{
    auto newps = new string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}

int main()
{
    HasPtr hp1("World");
    HasPtr hp2 = hp1;

    cout << hp2.get() << endl;

    hp1.set("Hello");

    cout << hp1.get() << endl;

    return 0;
}