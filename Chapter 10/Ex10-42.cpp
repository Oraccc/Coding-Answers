#include <list>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}

int main()
{
    list<string> words;
    for (string s; cin >> s; words.push_back(s)) {}
    elimDups(words);
    
    for (const auto &e: words)
        cout << e << " ";
    cout << endl;

    return 0;
}