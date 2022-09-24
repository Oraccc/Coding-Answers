#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<int> li;
    vector<int> vi;

    string s;
    cout << "Please enter list<int> li: " << endl;
    getline(cin, s);
    istringstream iss(s);
    int k;
    while (iss >> k)
        li.push_back(k);
    cout << "Please enter vector<int> vi: " << endl;
    getline(cin, s);
    iss.clear();
    iss.str(s);
    while (iss >> k)
        vi.push_back(k);
    
    auto lit = li.cbegin();
    auto vit = vi.cbegin();
    for (; lit != li.cend() && vit != vi.cend(); ++lit, ++vit)
    {
        if (*lit < *vit)
        {
            cout << "li < vi" << endl;
            return 0;
        }
        if (*lit > *vit)
        {
            cout << "li > vi" << endl;
            return 0;
        }
    }
    if (li.size() == vi.size())
        cout << "li == vi" << endl;
    else if (lit == li.cend())
        cout << "li < vi" << endl;
    else
        cout << "li > vi" << endl;
    
    return 0;
}