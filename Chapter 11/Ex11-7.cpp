#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

typedef map<string, vector<string>> family_type;

void addFamily (family_type &families, const string &name)
{
    auto ret = families.insert({name, {}});
    if (!ret.second)
        cerr << "Already have a family name!" << endl;
}

void addChild(family_type &families, const string &family_name, const string &child_name)
{
    auto it = families.find(family_name);
    if (it != families.end())
        it->second.push_back(child_name);
    else
        cerr << "No family name given first!" << endl;
}

int main()
{
    family_type families;
    addFamily(families, "Black");
    addFamily(families, "White");
    addFamily(families, "Black");

    addChild(families, "Black", "Bob");
    addChild(families, "Black", "Alice");
    addChild(families, "White", "Bob");
    addChild(families, "Green", "Bob");

    for (const auto &family : families)
        for (const auto &name: family.second)
            cout << name << " " << family.first << endl;

    return 0;
}