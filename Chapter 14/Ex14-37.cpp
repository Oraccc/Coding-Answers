#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Equal
{
public:
    Equal(int v) : val(v) {}
    bool operator() (int rhs)
    {
        return val == rhs;
    }
private:
    int val;
};

int main()
{
    vector<int> vi {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int oldVal, newVal;
    cin >> oldVal >> newVal;
    replace_if(vi.begin(), vi.end(), Equal(oldVal), newVal);
    for (const auto &l : vi)
        cout << "<" << l << ">" << endl;
    
    return 0;
}