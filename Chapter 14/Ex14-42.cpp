#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
int main() 
{
    vector<int> vi { 1000, 2000, 3000, 4000, 5000 };
    cout << count_if(vi.begin(), vi.end(),
        bind(greater<int>(), placeholders::_1, 1024)) << endl;

    vector<string> vs { "pooh", "pooh", "abc", "pooh" };
    cout << *find_if(vs.begin(), vs.end(),
        bind(not_equal_to<string>(), placeholders::_1, "pooh")) << endl;

    transform(vi.begin(), vi.end(), vi.begin(),
        bind(multiplies<int>(), placeholders::_1, 2));

    for (const auto &i : vi)
        cout << i << ' ';
    cout << endl;

    return 0;
}