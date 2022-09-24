#include <iostream>
#include <iterator>

using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    int *last = end(a); 

    for (int *beg = begin(a); beg != last; ++beg)
    {
        *beg = 0;
    }

    for (auto i : a)
        cout << i << endl;

    return 0;
}