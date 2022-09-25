#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;

string make_plural(size_t ctr, const string &word, const string &ending = "s") 
{
    return (ctr > 1) ? word + ending : word;
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void elimDups(vector<string> &words) 
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> words, vector<string>::size_type sz) 
{
    elimDups(words);
        
    auto iter = partition(words.begin(), words.end(), bind(check_size, _1, sz));

    auto count = count_if(words.begin(), words.end(), bind(check_size, _1, sz));

    cout << count << " " << make_plural(count, "word") << " of length "
        << sz << " or longer." << endl;

    for_each(words.begin(), iter,
        [](const string &s) { cout << s << " "; });
}

int main() 
{
    vector<string> words;
    for (string s; cin >> s; words.push_back(s)) {}
    biggies(words, 6);
    cout << endl;

    return 0;
}