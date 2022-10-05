#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char *ca = new char[s.size() + 1];
    strcpy(ca, s.c_str());

    cout << ca << endl;

    return 0;
}