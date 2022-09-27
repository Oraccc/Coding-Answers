#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <fstream>
#include "Sales_item.h"

using namespace std;

bool compareIsbn(const Sales_item &sd1, const Sales_item &sd2) 
{
    return sd1.isbn() < sd2.isbn();
}

int process_transaction(istream &in, ostream &out) 
{
    istream_iterator<Sales_item> i_iter(in), eof;
    vector<Sales_item> trans(i_iter, eof);
    if (trans.empty()) 
    {
        cerr << "No data!" << endl;
        return -1;
    }

    sort(trans.begin(), trans.end(), compareIsbn);

    ostream_iterator<Sales_item> o_iter(out, "\n");

    for (auto bg = trans.begin(), ed = bg; bg != trans.end(); bg = ed) 
    {
        ed = find_if_not(bg, trans.end(), [bg](const Sales_item &i) { return i.isbn() == bg->isbn(); });
        o_iter = accumulate(bg, ed, Sales_item(bg->isbn()));
    }
    return 0;
}

int main(int argc, char **argv)
{
    ifstream in(argv[1]);
    if (!in) 
    {
        cerr << "Fail to open file: " << argv[1] << endl;
        return -1;
    }

    process_transaction(in, cout);

    return 0;
}