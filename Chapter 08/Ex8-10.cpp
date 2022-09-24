#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<string> vs;
    string filename;
    cin >> filename;
    ifstream in(filename);

    if (!in)
    {
        cerr << "Fail to open file: " << filename << endl;
        return -1;
    }
    for (string line; getline(in, line); vs.push_back(line)) {}
    for (const auto &e : vs)
    {
        istringstream iss(e);
        for (string word; iss >> word; cout << word << endl) {}
    }

    return 0;
}