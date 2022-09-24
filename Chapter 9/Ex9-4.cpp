#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<int>::const_iterator findValue(vector<int>::const_iterator begin, vector<int>::const_iterator end, int k)
{
    for (auto it = begin; it != end; ++it)
    {
        if (k == *it)
            return it;
    }

    return end;
}

int main()
{
    string str;
    cout << "Input Int Vector: " << endl;
    getline(cin, str);
    istringstream iss(str);
    vector<int> vi;
    int k;
    while (iss >> k)
        vi.push_back(k);
    cout << "Input Target Value: " << endl;
    cin >> k;
    auto it = findValue(vi.cbegin(), vi.cend(), k);
    if (it == vi.cend())
        cout << "Can't found " << k << " in range!" << endl;
    else
        cout << "Found " << *it << " at postion " << it - vi.cbegin() << endl;

    return 0;
}