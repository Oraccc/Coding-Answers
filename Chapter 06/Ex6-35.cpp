#include <iostream>

using namespace std;

int factorial(int val)
{
    if (val > 1)
        return factorial(--val) * val; // Not Correct!
    return 1;
}

int main()
{
    cout << factorial(5) << endl;
}