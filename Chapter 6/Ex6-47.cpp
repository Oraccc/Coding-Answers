#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>::iterator beg, vector<int>::iterator end)
{
    #ifndef NDEBUG
    cout << "In Function: " << __func__ << ", " << "Vector Size: " << end - beg << endl;
    #endif

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
    printVector(v.begin(), v.end());

    return 0;
}