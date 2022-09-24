#include <iostream>

using namespace std;

void exchangePointer(int * &p1, int *&p2)
{
    int * tmp = p2;
    p2 = p1;
    p1 = tmp;
}

int main()
{
    int v1 = 10, v2 = 20;
    int *p1 = &v1, *p2 = &v2;
    cout << p1 << '\t' << p2 << endl;
    cout << *p1 << '\t' << *p2 << endl;
    exchangePointer(p1, p2);
    cout << p1 << '\t' << p2 << endl;
    cout << *p1 << '\t' << *p2 << endl;
}