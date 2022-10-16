#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class StrLength
{
public:
    StrLength(size_t l) : len(l) {}
    bool operator()(const string &s) const
    {
        return s.size() == len;
    }
private:
    size_t len;
};

int main()
{
    string filename;
    cin >> filename;
    ifstream ifs(filename);
    if(!ifs.is_open())
    {
        return -1;
    }
    istream_iterator<string> iter(ifs), eof;

    // for(; iter != eof; ++iter)
    // {
    //     cout << *iter << endl;
    // }

    for (size_t i = 1; i <= 10; ++i)
    {
        int count = count_if(iter, eof, StrLength(i));
        cout << "Length " << i << ": " << count << endl;
    }
}