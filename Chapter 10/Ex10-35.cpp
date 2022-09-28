#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vi{0, 1, 2, 3, 4, 5};
    for (auto it = --vi.end(); it + 1 != vi.begin(); --it)
        cout << *it << " ";
    
    cout << endl;

    return 0;
}