#include <string>
#include <iostream>

using namespace std;

void findAllStr_v1(const string &s, const string &s2) 
{
    string::size_type pos = 0;
    while((pos = s.find_first_of(s2, pos)) != string::npos) 
    {
        cout << "Find character " << s[pos] << " at " << pos << endl;
        ++pos;
    }
}

void findAllStr_v2(const string &s, const string &s2) 
{
    string::size_type lastpos = 0;
    string::size_type pos = 0;
    while((pos = s.find_first_not_of(s2, pos)) != string::npos) 
    {
        for (auto i = lastpos; i != pos; ++i)
        cout << "Find character " << s[i] << " at " << i << endl;
        lastpos = ++pos;
    }
    for (auto i = lastpos; i != s.size(); ++i)
        cout << "Find character " << s[i] << " at " << i << endl;
}

void searchStr(const string &s) 
{
    const string numbers{"1234567890"};
    const string alphabets{"abcdefghijklmnopqrstuvwxyz"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    cout << "First version\n";
    cout << "Search string " << s << " for numeric characters:\n";
    findAllStr_v1(s, numbers);

    cout << "Search string " << s << " for alphabetic characters:\n";
    findAllStr_v1(s, alphabets);

    cout << "\nSecond version\n";
    cout << "Search string " << s << " for numeric characters:\n";
    findAllStr_v2(s, numbers);

    cout << "Search string " << s << " for alphabetic characters:\n";
    findAllStr_v2(s, alphabets);
}

int main() 
{
    string s{"ab2c3d7R4E6"};
    searchStr(s);
    cout << endl;

    return 0;
}