#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    string filename;
    cin >> filename;
    ifstream in(filename);
    if (!in.is_open())
    {
        cerr << "Fail to open " << filename << endl;
        return -1;
    }

    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(in, line))
    {
        PersonInfo info;
        record.clear();

        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for (const auto &e : people)
    {
        cout << e.name << ": ";
        for (const auto &p : e.phones)
            cout << p << " ";
        cout << endl;
    }

    return 0;
}