#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums{1,2,3,4,5};

    for (auto it = nums.cbegin(); it != nums.cend(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}