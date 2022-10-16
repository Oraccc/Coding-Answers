#include <iostream>

using namespace std;

class IfThenElse
{
public:
    int operator() (bool condition, int t, int f) const 
    {
        return condition ? t : f;
    }
};

int main() 
{
    int n;
    cin >> n;
    cout << IfThenElse()(n > 0, 1, -1) << endl;
    return 0;
}