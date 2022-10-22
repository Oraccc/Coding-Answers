#include <sstream>
#include <cctype>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

string TextQuery::filter_str(const string &s) const
{
    string ret;
    for (const auto &ch : s)
        if (!ispunct(ch))
            ret += tolower(ch);
    return ret;
}

TextQuery::TextQuery(ifstream &in)
    : text(new StrVec), word_map()
{
    for (string line; getline(in, line); text->push_back(line))
    {
        istringstream iss(line);
        for (string word; iss >> word;)
        {
            auto &lns = word_map[filter_str(word)];
            if (!lns)
                lns.reset(new set<line_no_type>);
            lns->insert(text->size());
        }
    }
}

QueryResult TextQuery::query(const string &word) const
{
    static shared_ptr<set<line_no_type>>
        nodata(new set<line_no_type>);
    auto filter_word = filter_str(word);
    auto it = word_map.find(filter_word);
    if (it == word_map.end())
        return QueryResult(word, 0, nodata, text);
    line_no_type total = 0;
    for (const auto &ln : *(it->second))
    {
        istringstream iss(*(text->begin() + ln));
        for (string wd; iss >> wd;)
            if (filter_str(wd) == filter_word)
                ++total;
    }
    return QueryResult(word, total, it->second, text);
}