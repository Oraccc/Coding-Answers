#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 3};

    vector<int>::size_type shortSize = (v1.size() > v2.size()) ? v2.size() : v1.size();

    for (vector<int>::size_type i = 0; i < shortSize; ++i)
    {
        if (v1[i] != v2[i])
        {
            cout << "False" << endl;
            return 0;
        }
    }

    cout << "True" << endl;
    return 0;
}
