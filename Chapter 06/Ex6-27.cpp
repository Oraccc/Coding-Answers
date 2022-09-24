#include <iostream>

using namespace std;

int calSum(initializer_list<int> li)
{
    int sum = 0;

    for (auto beg = li.begin(); beg != li.end(); ++beg)
    {
        sum += *beg;
    }

    return sum;
}

int main()
{
    cout << calSum({1, 2, 3, 4, 5, 6, 7, 8, 9}) << endl;
}