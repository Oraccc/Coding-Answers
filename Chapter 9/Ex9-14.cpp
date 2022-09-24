#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main()
{
    list<const char *> lc = {"Alice", "Bob", "David"};
    vector<string> vs;

    vs.assign(lc.begin(), lc.end());

    for (const auto &c : vs)
        cout << c << endl;

    return 0;
}