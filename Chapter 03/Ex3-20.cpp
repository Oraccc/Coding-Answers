#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int i;
    vector<int> nums;

    while (cin >> i)
    {
        nums.push_back(i);
    }

    if (!nums.empty())
    {
        for (vector<int>::size_type j = 0; j < nums.size() / 2; ++j)
        {
            cout << nums[j] + nums[nums.size() - 1 - j] << endl;
        }

        if (nums.size() % 2 != 0)
        {
            cout << nums[nums.size() / 2] << endl;
        }
    }

    return 0;
}