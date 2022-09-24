#include <iostream>

using namespace std;

int fact(int v)
{
    int ret = 1;
    while (v > 1)
    {
        ret *= v--;
    }
    return ret;
}

int main()
{
    int num;
    cin >> num;
    cout << fact(num) << endl;
    return 0;
}