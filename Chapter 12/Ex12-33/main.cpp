#include <iostream>
#include <fstream>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;

        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    cout << "Enter the filename to look up: ";
    string s;
    cin >> s;
    ifstream in(s);
    if (!in.is_open())
    {
        cerr << "cannot open file: " << s << endl;
        return -1;
    }
    runQueries(in);

    return 0;
}