#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr 
{
friend void swap(HasPtr &, HasPtr &);
public:
    HasPtr(const string &s = string())
        : ps(new string(s)), i(0) {}
    HasPtr(const char *cs) : ps(new string(cs)), i(0) {}
    HasPtr(const HasPtr &ori)
        : ps(new string(*ori.ps)), i(ori.i) {}
    ~HasPtr() { delete ps; }

    HasPtr &operator=(const HasPtr &rhs);

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
    cout << "HasPtr::swap(HasPtr &rhs) between <" << *ps
                << "> and <" << *rhs.ps << ">" << endl;
    using std::swap;
    swap(ps, rhs.ps);
    swap(i, rhs.i);
}

void swap(HasPtr &lhs, HasPtr &rhs) 
{
    cout << "swap(HasPtr &lhs, HasPtr &rhs) between <" << *lhs.ps
                << "> and <" << *rhs.ps << ">" << endl;
    lhs.swap(rhs);
}


HasPtr &HasPtr::operator=(const HasPtr &rhs) 
{
  auto newps = new std::string(*rhs.ps);
  delete ps;
  ps = newps;
  i = rhs.i;
  return *this;
}

bool HasPtr::operator<(const HasPtr &rhs) const 
{
  return *ps < *rhs.ps;
}

int main() 
{
    HasPtr hp1 = "World";
    HasPtr hp2 = hp1;
    HasPtr hp3;
    hp3 = hp1;
    hp1.set("Hello");

    cout << hp1.get() << endl;
    cout << hp2.get() << endl;
    cout << hp3.get() << endl;

    hp1 = hp1;
    cout << "After `hp1 = hp1`: " << hp1.get() << endl;

    swap(hp1, hp2);
    cout << hp1.get() << endl;
    cout << hp2.get() << endl;

    swap(hp1, hp1);
    cout << hp1.get() << endl;

    vector<HasPtr> v{ "Hello", "World", "P", "Q", "R", "S", "T", "U", 
        "A", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L",
        "B", "C", "D", "E", "J", "K", "L", "M", "N" };

    sort(v.begin(), v.end());

    return 0;
}