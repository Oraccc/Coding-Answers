#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename Iterator, typename Value>
auto myFind(Iterator first, Iterator last, Value const& value)
{
    for (; first != last && *first != value; ++first);
    return first;
}


int main()
{
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    bool result = v.cend() != myFind(v.cbegin(), v.cend(), 5);
    cout << (result ? "found" : "not found") << endl;

    return 0;
}