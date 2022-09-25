#include <iostream>

using namespace std;

int main()
{
    int n;
    auto isZero = [&n]() -> bool {return n > 0 ? --n, false : true;};

    cin >> n;

    while (!isZero())
        cout << n << endl;

    return 0;
}