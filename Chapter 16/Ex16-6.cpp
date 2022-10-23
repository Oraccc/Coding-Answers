#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename T, unsigned size>
T *begin_def(T (&arr)[size])
{
    return arr;
}

template <typename T, unsigned size>
T *end_def(T (&arr)[size])
{
    return arr + size;
}

int main()
{
    string s[] = {"sssss", "ss", "ss", "ssssszzzz"};
    cout << *begin_def(s) << endl;
    cout << *(end_def(s) - 1) << endl;
    return 0;
}