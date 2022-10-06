#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
    allocator<string> alloc;
    constexpr size_t n = 100;

    auto const p = alloc.allocate(n);

    string s;
    auto q = p;

    while (cin >> s && q != p + n)
        alloc.construct(q++, s);
    
    for (auto pos = p; pos != q; ++pos)
        cout << *pos << endl;
    
    while (q != p)
        alloc.destroy(--q);

    alloc.deallocate(p, n);

    return 0;
}