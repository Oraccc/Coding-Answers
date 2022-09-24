#include <iostream>

using namespace std;

int main()
{
    int x = 3;
    auto sum = [x] (int i) {return x + i;};
    cout << sum(4) << endl;

    return 0;
}