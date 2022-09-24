#include <iostream>
#include <string>

using namespace std;

struct Person
{
    Person() = default;
    Person(const string &n): name(n) {}
    Person(const string &n, const string &a): name(n), address(a) {}
    Person(istream &);

    string getName() const { return name; }
    string getAddress() const { return address; }

    string name;
    string address;
};

istream &read(istream &is, Person &rhs)
{
    is >> rhs.name >> rhs.address;
    return is;
}

ostream &print(ostream &os, const Person &rhs)
{
    os << rhs.getName() << " " << rhs.getAddress();
    return os;
}

Person::Person(istream &is)
{
    read(is, *this);
}

int main()
{
    Person p1;
    Person p2("Alice");
    Person p3("Alice", "Earth");
    Person p4(cin);

    print(cout, p1) << endl;
    print(cout, p2) << endl;
    print(cout, p3) << endl;
    print(cout, p4) << endl;
    
    return 0;
}