#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename T, unsigned size>
constexpr unsigned getSize(const T(&)[size])
{
    return size;
}

int main()
{
    string s[] = { "sss" };
    cout << getSize(s) << endl;

    char c[] = "s";
    cout << getSize(c) << endl;
    return 0;
}