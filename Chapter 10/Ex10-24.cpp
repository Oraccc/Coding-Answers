#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

int findFirstLonger(vector<int> &vi, const string &s)
{
    auto it = find_if(vi.begin(), vi.end(), bind(check_size, s, _1));

    return *it;
}

int main()
{
    string s;
    cin >> s;
    vector<int> vi;

    for (int i; cin >> i; vi.push_back(i)) {}
    cout << findFirstLonger(vi, s) << endl;

    return 0;
}