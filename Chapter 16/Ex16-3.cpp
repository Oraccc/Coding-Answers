#include <iostream>
#include <vector>
using namespace std;

class Sales_data{ };

template<typename T>
int compare(const T& lhs, const T& rhs)
{
    if(lhs < rhs) return -1;
    if(rhs < lhs) return  1;
    return 0;
}

int main()
{
    cout << compare(1, 0) << endl;
    vector<int> vec1{ 1, 2, 3 }, vec2{ 4, 5, 6 };
    cout << compare(vec1, vec2) << endl;

    return 0;
}