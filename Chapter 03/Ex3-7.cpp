#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s = "Hello, Bye!";
    string tmp;
    for (auto c: s)
    {
        if (!ispunct(c))
            tmp += c;
    }

    cout << tmp << endl;
    return 0;
}