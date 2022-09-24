#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void elimDups (vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter (const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    vector<string> words;
    for (string s; cin >> s; words.push_back(s)){}
    elimDups(words);
    stable_sort(words.begin(), words.end(), isShorter);

    for (const auto &e : words)
        cout << e << " ";
    cout << endl;

    return 0;
}