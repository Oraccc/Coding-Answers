#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool checkUpper(const string &s)
{
    for (auto c : s)
    {
        if (isupper(c))
            return true;
    }

    return false;
}

void stringLower(string &s)
{
    for (auto &c : s)
        c = tolower(c);
}

int main()
{
    string s = "Big Apple";
    cout << checkUpper(s) << endl;
    stringLower(s);
    cout << s << endl;
    cout << checkUpper(s) << endl;
}