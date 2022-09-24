#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    string sum;

    while (cin >> s)
    {
        sum = sum + s + " ";
    }

    cout << sum << endl;

    return 0;
}