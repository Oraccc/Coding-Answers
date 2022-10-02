#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, string> trans_type;

trans_type build_map(ifstream &dict) 
{
    trans_type trans;
    string abbr, expr;
    while (dict >> abbr && getline(dict, expr))
        if (expr.size() > 1)
        trans[abbr] = expr.substr(1);
        else
        cerr << "Error: No rule for " << abbr << endl;
    return trans;
}

const string &transform(const string &s, const trans_type &trans) 
{
    auto it = trans.find(s);
    if (it != trans.end())
        return it->second;
    else
        return s;
}

void word_transform(ifstream &dict, ifstream &in, ofstream &out) 
{
    auto trans_map = build_map(dict);
    string line;
    while (getline(in, line)) 
    {
        istringstream iss(line);
        string word;
        bool firstword = true;
        while (iss >> word) 
        {
            if (firstword)
                firstword = false;
            else
                out << " ";
            out << transform(word, trans_map);
        }
        out << "\n";
    }
}

int main(int argc, char **argv) 
{
    if (argc < 2) 
    {
        return -1;
    }

    ifstream in_dict(argv[1]);

    if (!in_dict.is_open()) 
    {
        cerr << "Cannot open file: " << argv[1] << endl;
        return -1;
    }
    ifstream in_text;

    in_text.open(argv[2]);
    if (!in_text.is_open()) 
    {
        cerr << "Cannot open file: " << argv[2] << endl;
        return -2;
    }

    ofstream out_text(argv[3]);

    if (!out_text.is_open()) 
    {
        cerr << "Cannot open file: " << argv[3] << endl;
        return -1;
    }

    word_transform(in_dict, in_text, out_text);

    return 0;
}