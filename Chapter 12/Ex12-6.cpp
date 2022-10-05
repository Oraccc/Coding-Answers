#include <vector>
#include <iostream>

using namespace std;

vector<int> *factory_veci()
{
    return new vector<int>();
}

void set_veci(vector<int> *vip)
{
    for (int i; cin >> i; vip->push_back(i)) {}
}

void print_veci(vector<int> *vip)
{
    for (const auto &i : *vip)
        cout << i << " ";
    cout << endl;
}

int main()
{
    auto *p = factory_veci();
    set_veci(p);
    print_veci(p);
    delete p;

    return 0;
}