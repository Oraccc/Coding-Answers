#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
    if (beg != end)
    {
        cout << *beg << endl;
        printVector(++beg, end);
    }
    return;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    printVector(v.cbegin(), v.cend());
    return 0;
}