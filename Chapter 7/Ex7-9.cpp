#include <iostream>
#include <string>

using namespace std;

struct Person
{
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

int main()
{
    Person p1;
    read(cin, p1);
    print(cout, p1) << endl;
    
    return 0;
}