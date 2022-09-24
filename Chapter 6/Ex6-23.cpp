#include <iostream>
#include <iterator>

using namespace std;

void print(const int *beg, const int *end)
{
    while (beg != end)
    {
        cout << *beg++ << endl;
    }
}

int main()
{
    int j[2] = {0, 1};
    print(begin(j), end(j));
}