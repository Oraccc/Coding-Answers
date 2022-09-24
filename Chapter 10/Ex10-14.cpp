#include <iostream>

using namespace std;

int main()
{
    auto sum = [] (int a, int b) {return a + b;};

    cout << sum(3, 4) << endl;

    return 0;
}