#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vi;
    for (int i; cin >> i; vi.push_back(i)) {}
    list<int> li;
    sort(vi.begin(), vi.end());
    unique_copy(vi.begin(), vi.end(), back_inserter(li));
    for_each(li.begin(), li.end(), [](int i) {cout << i << " ";});

    return 0;
}