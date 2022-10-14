#include <iostream>
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"

using namespace std;

class StrBlobPtrPtr
{
public:
    StrBlobPtrPtr(StrBlobPtr *p) : ptr(p) {}

    StrBlobPtr *operator->() const
    {
        return ptr;
    }

private:
    StrBlobPtr *ptr;
};


int main()
{
    StrBlob s{"abc", "defg", "hi"};

    StrBlobPtr p(s);
    cout << *p++ << endl;
    cout << *p << endl;
    cout << p->back() << endl;
    cout << p.operator->()->back() << endl;

    ConstStrBlobPtr cp(s);
    cout << *cp++ << endl;
    cout << *cp << endl;
    cout << cp->back() << endl;

    StrBlobPtrPtr pp(&p);
    cout << pp->operator->()->back() << endl;
    return 0;
}