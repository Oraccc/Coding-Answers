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
    string s = ps(cin);

    cout << s << endl;
}