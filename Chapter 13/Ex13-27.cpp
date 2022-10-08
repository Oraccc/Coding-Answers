#include <string>
#include <iostream>

using namespace std;

class HasPtr 
{
public:
    HasPtr(const string &s = string())
        : ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &ori)
        : ps(ori.ps), i(ori.i), use(ori.use) { ++*use; }
    ~HasPtr();

    HasPtr &operator=(const HasPtr &rhs);

    const string &get() const { return *ps; }
    void set(const string &s) { *ps = s; }

private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr::~HasPtr() 
{
    if (--*use == 0) 
    {
        delete ps;
        delete use;
    }
}

HasPtr &HasPtr::operator=(const HasPtr &rhs) 
{
    ++*rhs.use;
    if (--*use == 0) 
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

int main() {
    HasPtr hp1 = string("World");
    HasPtr hp2 = hp1;
    HasPtr hp3;
    hp3 = hp1;
    hp1.set("Hello");

    cout << hp1.get() << endl;
    cout << hp2.get() << endl;
    cout << hp3.get() << endl;

    hp1 = hp1;
    cout << "After `hp1 = hp1`: " << hp1.get() << endl;

    return 0;
}