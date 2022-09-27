#include <iterator>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    string filename;
    cin >> filename;
    ifstream in(filename);
    if (!in.is_open())
    {
        return -1;
    }
    istream_iterator<string> iter(in), eof;
    vector<string> vs(iter, eof);
    for (const auto &s: vs)
        cout << s << endl;

    return 0;
}