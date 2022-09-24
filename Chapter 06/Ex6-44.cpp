#include <iostream>
#include <string>

using namespace std;

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    string s1 = "hello";
    string s2 = "next";

    cout << isShorter(s1, s2) << endl;
    cout << isShorter(s2, s1) << endl;

    return 0;
}