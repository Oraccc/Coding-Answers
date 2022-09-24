#include <iostream>
#include <vector>
#include <iterator>

using  namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    vector<int> iv(begin(a), end(a));

    for (auto i : iv)
    {
        cout << i << endl;
    }
    
    return 0;
}