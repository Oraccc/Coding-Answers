#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PrintStr
{
public:
    string operator()(istream &is)
    {
        string s;
        if(getline(is, s))
            return s;
        else    
            return s;
    }
};

int main()
{
    PrintStr ps;
    vector<string> vs;
    string s = ps(cin);
    while (!s.empty())
    {
        vs.push_back(s);
        s = ps(cin);
    }
    for (const auto &l : vs)
        cout << "<" << l << ">" << endl;

    return 0;
}