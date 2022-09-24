#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending = "s") 
{
    return (ctr > 1) ? word + ending : word;
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
   
    auto iter = partition(words.begin(), words.end(),
        [sz](const string &s) { return s.size() >= sz; });

    auto count = iter - words.begin();

    cout << count << " " << make_plural(count, "word") << " of length "
        << sz << " or longer." << endl;

    for_each(words.begin(), iter,
        [](const string &s) { cout << s << " "; });
}

int main() 
{
    vector<string> words;
    for (string s; cin >> s; words.push_back(s)) {}
    biggies(words, 3);
    cout << endl;
    biggies(words, 5);

    return 0;
}