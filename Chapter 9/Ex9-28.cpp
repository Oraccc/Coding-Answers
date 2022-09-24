#include <forward_list>
#include <string>
#include <iostream>

using namespace std;

void insertStr(forward_list<string> &fls, const string &s1, const string &s2)
{
    auto pre = fls.before_begin();
    auto cur = fls.begin();

    while (cur != fls.end())
    {
        if (*cur == s1)
        {
            fls.insert_after(cur, s2);
            return;
        }
        else
            pre = cur++;
    }
    fls.insert_after(pre, s2);
}

int main()
{
    forward_list<string> fls = {"s1", "s2", "s3"};

    insertStr(fls, "s2", "s4");

    for (const auto &s : fls)
        cout << s << " ";
    cout << endl;

    insertStr(fls, "s5", "s6");
    for (const auto &s : fls)
        cout << s << " ";
    cout << endl;
}