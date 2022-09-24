#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    list<int> li{1, 2, 3};
    vector<int> vi{4, 5, 6};

    vector<double> vd1(li.begin(), li.end());
    vector<double> vd2(vi.begin(), vi.end());

    cout << vd1[0] << " " << vd2[0] << endl;

    return 0;
}