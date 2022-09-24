#include <forward_list>
#include <iostream>

using namespace std;

int main()
{
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto pre = flst.before_begin();
    auto cur = flst.begin();

    while (cur != flst.end())
    {
        if (*cur % 2)
        {
            cur = flst.erase_after(pre);
        }
        else
        {
            pre = cur;
            ++cur;
        }
    }

    for (const auto &i : flst)
        cout << i << " ";
    cout << endl;

    return 0;
}