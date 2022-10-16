#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> vi { 12, 34, 56, 78, 90, 123, 456, 789 };
    auto it = find_if_not(vi.begin(), vi.end(),
        bind(modulus<int>(), n, placeholders::_1));
    if (it != vi.end())
        cout << n << " is divisible by " << *it << endl;
    else
        cout << "Find nothing." << endl;
    return 0;
}