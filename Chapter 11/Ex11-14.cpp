#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

typedef map<string, vector<pair<string, string>>> family_type;

void addFamily (family_type &families, const string &name)
{
    auto ret = families.insert({name, {}});
    if (!ret.second)
        cerr << "Already have a family name!" << endl;
}

void addChild(family_type &families, const string &family_name, const string &child_name,
    const string &birthday)
{
    auto it = families.find(family_name);
    if (it != families.end())
        it->second.push_back({child_name, birthday});
    else
        cerr << "No family name given first!" << endl;
}

int main()
{
    family_type families;
    addFamily(families, "Black");
    addFamily(families, "White");
    addFamily(families, "Black");

    addChild(families, "Black", "Bob", "1990-1-1");
    addChild(families, "Black", "Alice", "1990-2-1");
    addChild(families, "White", "Bob", "1990-3-1");
    addChild(families, "Green", "Bob", "1990-4-1");

    for (const auto &family : families)
        for (const auto &child: family.second)
            cout << child.first << " " << family.first << " " << child.second << endl;

    return 0;
}