#include <string>
#include <iostream>

using namespace std;

class Employee 
{
public:
    Employee() : name(), id(++eid) {}
    explicit Employee(const string &n) : name(n), id(++eid) {}
    Employee(const Employee &e) : name(e.name), id(++eid) {}

    Employee &operator= (const Employee &e) { name = e.name; return *this; }

    const string &getName() const { return name; }
    int getID() const { return id; }

private:
    string name;
    int id;
    static int eid;
};

int Employee::eid = 0;

int main() 
{
    Employee e1;
    Employee e2("Zhang San");
    Employee e3 = e2;
    cout << e1.getName() << " " << e1.getID() << endl;
    cout << e2.getName() << " " << e2.getID() << endl;
    cout << e3.getName() << " " << e3.getID() << endl;

    return 0;
}