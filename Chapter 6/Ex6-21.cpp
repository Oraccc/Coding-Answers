#include <iostream>

using namespace std;

int compare(const int v, const int *p)
{
    return (v >= *p) ? v : *p;
}

int main()
{
    int v1 = 3, v2 = 4;
    int *p = &v2;
    cout << compare(v1, p) << endl;
}