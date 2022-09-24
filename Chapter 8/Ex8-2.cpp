#include <iostream>
#include <string>

using namespace std;

istream &read(istream &is)
{
    is.clear();
    string str;
    while (is >> str)
        cout << str << " ";
    cout << endl;
    is.clear();

    return is;
}

int main()
{
    read(cin);

    return 0;
}