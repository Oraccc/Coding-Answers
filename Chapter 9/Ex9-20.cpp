#include <list>
#include <deque>
#include <iostream>

using namespace std;

int main()
{
    list<int> input;
    deque<int> even, odd;

    int i;
    while (cin >> i)
    {
        input.push_back(i);
    }

    for (auto it = input.cbegin(); it != input.cend(); ++it)
    {
        if (*it % 2)
            odd.push_back(*it);
        else
            even.push_back(*it);
    }

    cout << "Odd: ";
    for (const auto &i : odd)
        cout << i << " ";
    cout << endl;

    cout << "Even: ";
    for (const auto &i : even)
        cout << i << " ";
    cout << endl;

    return 0;
}