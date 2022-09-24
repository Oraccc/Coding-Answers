#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> read(const string &filename)
{
    ifstream in(filename);
    vector<string> vs;
    if(in)
    {
        for(string s; in >> s;)
            vs.push_back(s);
    }
    else
    {
        cerr << "Fail to open file: " << filename << endl;
    }
    return vs;
}

int main()
{
    string filename;
    cin >> filename;
    auto vs = read(filename);
    for (const auto &s : vs)
        cout << s << endl;
}