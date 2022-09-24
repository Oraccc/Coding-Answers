#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool longStr (const string &s)
{
    return s.size() >= 5;
}

int main()
{
    vector<string> words;
    for (string s; cin >> s; words.push_back(s)) {}
    auto long_bg = partition(words.begin(), words.end(), longStr);
    for (auto it = words.begin(); it != long_bg; ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}