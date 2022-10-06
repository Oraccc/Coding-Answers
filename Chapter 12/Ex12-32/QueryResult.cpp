#include "QueryResult.h"
#include "StrBlobPtr.h"

using namespace std;

string make_plural(int cnt, const string &s, const string &postfix = "s") 
{
    return cnt > 1 ? s + postfix : s;
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs" << qr.lines->size() << " "
    << make_plural(qr.lines->size(), "time", "s") << endl;

    for (auto num : *qr.lines)
        os << "  " << "(line " << num + 1 << ") " << "\t" << StrBlobPtr(*qr.file, num).deref() << endl;
    
    return os;
}