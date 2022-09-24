#include <iostream>

using namespace std;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

auto arrRef(int i) -> int (&)[5]
{
    return i % 2 ? odd : even;
}

int main()
{
    int (&arr)[5] = arrRef(1);
    int *arr2 = arrRef(2);

    cout << arr[0] << endl;
    cout << arr2[0] << endl;

    return 0;
}