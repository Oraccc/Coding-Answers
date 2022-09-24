#include <iostream>
#include <vector>

using namespace std;

int func1(int a, int b);
int func2(int c, int d);

int func1(int a, int b)
{
    cout << "Called Func1: " << a << " " << b << endl;
    return 0;
}

int func2(int c, int d)
{
    cout << "Called Func2: " << c << " " << d << endl;
    return 0;
}

int main()
{
    vector<int (*)(int, int)> vf;

    vf.push_back(&func1);
    // vf.push_back(func1); Also Works
    vf.push_back(&func2);

    for (auto &e : vf)
    {
        (*e)(1, 2);
        // e(3, 4); Also Works
    }

    return 0;
}