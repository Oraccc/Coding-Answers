#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<char> vc{'H', 'e', 'l', 'l', 'o', '!'};
    string str(vc.cbegin(), vc.cend());

    cout << str << endl;

    return 0;
}