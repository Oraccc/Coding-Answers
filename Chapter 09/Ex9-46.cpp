#include <string>
#include <iostream>

using namespace std;

string fixName(const string &name, const string &prefix, const string &postfix) 
{
    string newName = name;
    newName.insert(0, prefix + " ");
    return newName.insert(newName.size(), " " + postfix);
}

int main() 
{
    cout << fixName("James", "Mr.", "Jr.") << endl;
    return 0;
}