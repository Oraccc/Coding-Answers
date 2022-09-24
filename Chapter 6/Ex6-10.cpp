#include <iostream>

using namespace std;

void swap(int &v1, int &v2)
{
    int tmp;
    tmp = v2;
    v2 = v1;
    v1 = tmp;
}

int main()
{
    int v1 = 3, v2 = 4;
    swap(v1, v2);
    cout << "v1: " << v1 << endl;
    cout << "v2: " << v2 << endl;
}