#include <map>
#include <set>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <fstream>

using namespace std;

string trimStr(string s)
{
    const char *punctuations{"\"'`:*-_;,.?!()[]{}"};
    for (auto &c : s)
        if (c >= 'A' && c <= 'Z') c -= 'A' - 'a';
    size_t bg = s.find_first_not_of(punctuations);
    if (bg == string::npos)
        return "";
    size_t ed = s.find_last_not_of(punctuations);
    return s.substr(bg, ed - bg + 1);
}

map<string, size_t> count_maps(vector<string> &words)
{
    map<string, size_t> counts;
    for (const auto &w : words)
        ++counts[trimStr(w)];
    return counts;
}

int main()
{
    string filename;
    cin >> filename;
    ifstream in(filename);
    if (!in.is_open())
    {
        return -1;
    }

    istream_iterator<string> i_iter(in), eof;
    vector<string> words(i_iter, eof);

    auto counts = count_maps(words);
    for (const auto &w : counts)
        cout << "\"" << w.first << "\" occurs " << w.second << (w.second > 1 ? " times." : " time.") << endl;

    return 0;
}