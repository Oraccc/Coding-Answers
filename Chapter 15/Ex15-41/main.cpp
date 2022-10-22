#include <iostream>
#include <fstream>
#include "Query.h"
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);

    Query q = Query("fiery") & Query("bird") | Query("wind");
    cout << "==================" << endl;
    cout << q << endl;
    cout << "==================" << endl;
    print(cout, q.eval(tq)) << endl;

    q = Query("fiery") & Query("bird") | ~Query("wind");
    cout << "==================" << endl;
    cout << q << endl;
    cout << "==================" << endl;
    print(cout, q.eval(tq)) << endl;

    while (true)
    {
        cout << "Enter word to look for, or 'q' to exit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    cout << "Enter the file name to look up: ";
    string filename;
    cin >> filename;
    ifstream in(filename);
    if (!in.is_open())
    {
        cerr << "Cannot open file: " << filename << endl;
        return -1;
    }
    runQueries(in);

    return 0;
}