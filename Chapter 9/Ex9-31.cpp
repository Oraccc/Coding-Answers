#include <iostream>
#include <list>
#include <forward_list>

using namespace std;

void changeFlst(forward_list<int> &flst)
{
    for (auto pre = flst.before_begin(), cur = flst.begin(); cur != flst.end();)
    {
        if (*cur % 2)
        {
            pre = flst.insert_after(pre, *cur);
            ++pre;
            ++cur;
        }
        else
        {
            cur = flst.erase_after(pre);
        }
    }
}

int main()
{
    forward_list<int> flst = {1, 2, 3, 4, 5, 6};
    changeFlst(flst);

    for (const auto &c : flst)
        cout << c << endl;

    return 0;
}