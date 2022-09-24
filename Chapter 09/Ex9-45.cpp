#include <string>
#include <iostream>

using namespace std;

string fixName(const string &name, const string &prefix, const string &postfix) 
{
    string newName = name;
    string pref = prefix + " ";
    newName.insert(newName.begin(), pref.begin(), pref.end());
    return newName.append(" " + postfix);
}

int main() 
{
    cout << fixName("James", "Mr.", "Jr.") << endl;
    return 0;
}