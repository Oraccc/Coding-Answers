#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8};
    auto end = iv.end();

    for (auto begin = iv.begin(); begin != end; ++begin)
    {
        *begin = (*begin % 2) ? *begin * 2 : *begin;
    }

    for (auto a : iv)
    {
        cout << a << endl;
    }

    return 0;
}