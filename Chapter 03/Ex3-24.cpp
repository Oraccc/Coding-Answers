#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    vector<int> nums;

    while (cin >> num)
    {
        nums.push_back(num);
    }

    for (auto beg = nums.cbegin(), end = nums.cend(); beg < end; ++beg)
    {
        --end;
        cout << *beg + *end << endl;
    }

    return 0;
}