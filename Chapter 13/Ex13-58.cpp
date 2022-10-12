#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Foo 
{
public:
    Foo() = default;
    Foo(initializer_list<int> il) : data(il) { }

    Foo sorted() &&;
    Foo sorted() const &;

    void print() const;

private:
    vector<int> data;
};

Foo Foo::sorted() && 
{
    cout << "Foo Foo::sorted() &&" << endl;
    sort(data.begin(), data.end());
    return *this;
}

/* 
Foo Foo::sorted() const & 
{
    cout << "Foo Foo::sorted() const &" << endl;
    Foo ret(*this);
    return ret.sorted();
}
*/

Foo Foo::sorted() const & 
{
    cout << "Foo Foo::sorted() const &" << endl;
    return Foo(*this).sorted();
}


void Foo::print() const 
{
    cout << "<" << this << ">";
    for (const auto &i : data)
        cout << " " << i;
    cout << endl;
}

int main() 
{
    Foo f1; f1.print();
    Foo f2 { 9, 2, 6, 5, 3, 8, 4, 1, 7 }; f2.print();
    Foo f3 = f2.sorted(); f2.print(); f3.print();
    Foo f4 = Foo({ 2, 6, 5, 3, 8, 4, 1, 7 }).sorted(); f4.print();

    return 0;
}