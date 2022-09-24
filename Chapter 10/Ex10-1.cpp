#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi{1, 2, 3, 3, 4, 3, 5};

    cout << count(vi.begin(), vi.end(), 3) << endl;

    return 0;
}