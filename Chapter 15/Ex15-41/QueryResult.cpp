#include "QueryResult.h"

using namespace std;

string make_plural(int cnt, const string &s,
                   const string &postfix = "s")
{
    return cnt > 1 ? s + postfix : s;
}

ostream &print(ostream &os, const QueryResult &qr)
{
    cout << "\"" << qr.word << "\" occurs " << qr.total << " "
         << make_plural(qr.total, "time") << ":\n";
    for (const auto &ln : *qr.line_numbers)
        cout << "(line " << ln + 1 << ") "
             << *(qr.line_text->begin() + ln) << endl;
    return os;
}