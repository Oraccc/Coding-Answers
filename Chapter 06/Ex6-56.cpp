#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int addVal (int a, int b)
{
    cout << "Called Add" << endl;
    return a + b;
}

int subtractVal (int a, int b)
{
    cout << "Called Subtract" << endl;
    return a - b;
}

int multiplyVal (int a, int b)
{
    cout << "Called Multiply" << endl;
    return a * b;
}

int divideVal (int a, int b)
{
    cout << "Called Divide" << endl;
    try
    {
        if (b == 0)
        {
            throw runtime_error("Divided by 0.");
        }
        return a / b;
    }
    catch (runtime_error err)
    {
        cerr << err.what() << endl;
        return 0;
    }
}

int main()
{
    vector<int (*)(int, int)> vf;

    vf.push_back(addVal);
    vf.push_back(subtractVal);
    vf.push_back(multiplyVal);
    vf.push_back(divideVal);

    for (const auto &e : vf)
    {
        cout << e(8, 4) << endl;
    }

    return 0;
}