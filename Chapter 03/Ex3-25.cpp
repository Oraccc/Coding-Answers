#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned score;
    vector<int> count(11, 0);
    auto beg = count.begin();

    while(cin >> score)
    {
        if (score <= 100)
        {
            ++*(beg + (score / 10));
        }
    }

    for (auto c : count)
    {
        cout << c << ' ';
    }

    return 0;
}