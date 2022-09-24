#include <string>
#include <iostream>

using namespace std;

void replaceStr(string &s, const string &oldVal, const string &newVal)
{
    for (string::size_type pos = 0; pos < s.size();)
    {
        if (s.substr(pos, oldVal.size()) == oldVal)
        {
            s.replace(pos, oldVal.size(), newVal);
            pos += newVal.size();
        }
        else
            ++pos;
    }
}

int main()
{
    string s{"tho thru"};
    replaceStr(s, "tho", "though");
    cout << s << endl;
    replaceStr(s, "thru", "through");
    cout << s << endl;
}