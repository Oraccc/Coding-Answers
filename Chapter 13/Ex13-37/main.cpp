#include "Folder.h"
#include "Message.h"

using namespace std;

int main() 
{
    Folder f1, f2;
    Message m1("m1"), m2("m2"), m3("m3"), m4("m4"), m5("m5");

    m1.save(f1); m2.save(f1); m5.save(f1);
    m3.save(f2); m4.save(f2); m5.save(f2);
    cout << "\n===== Message save =====\n";
    f1.print(); f2.print(); cout << endl;
    m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

    {
        Message m6(m5);
        cout << "\n===== Message copy-constructor =====\n";
        f1.print(); f2.print(); cout << endl;
        m5.print(); m6.print();

        m6 = m1;
        cout << "\n===== Message copy-assignment operator =====\n";
        f1.print(); f2.print(); cout << endl;
        m5.print(); m6.print();
    }

    cout << "\n===== Message destructor =====\n";
    f1.print(); f2.print(); cout << endl;
    m5.print();

    swap(m1, m3);
    cout << "\n===== Message swap =====\n";
    f1.print(); f2.print(); cout << endl;
    m1.print(); m3.print();
    swap(m1, m3);

    swap(m1, m1);
    cout << "\n===== Message swap self =====\n";
    f1.print(); f2.print(); cout << endl;
    m1.print();

    m1.remove(f1); m2.remove(f1); m5.remove(f1);
    m3.remove(f2); m4.remove(f2); m5.remove(f2);
    cout << "\n===== Message remove =====\n";
    f1.print(); f2.print(); cout << endl;
    m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

    f1.save(m1); f1.save(m2); f1.save(m5);
    f2.save(m3); f2.save(m4); f2.save(m5);
    cout << "\n===== Folder save =====\n";
    f1.print(); f2.print(); cout << endl;
    m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

    {
        Folder f3(f1);
        cout << "\n===== Folder copy-constructor =====\n";
        f1.print(); f2.print(); f3.print(); cout << endl;
        m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

        f3 = f2;
        cout << "\n===== Folder copy-assignment operator =====\n";
        f1.print(); f2.print(); f3.print(); cout << endl;
        m1.print(); m2.print(); m3.print(); m4.print(); m5.print();
    }
    cout << "\n===== Folder destructor =====\n";
    f1.print(); f2.print(); cout << endl;
    m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

    swap(f1, f2);
    cout << "\n===== Folder swap =====\n";
    f1.print(); f2.print(); cout << endl;
    m1.print(); m2.print(); m3.print(); m4.print(); m5.print();
    swap(f1, f2);

    swap(f1, f1);
    cout << "\n===== Folder swap self =====\n";
    f1.print(); f2.print(); cout << endl;
    m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

    f1.remove(m1); f1.remove(m2); f1.remove(m5);
    f2.remove(m3); f2.remove(m4); f2.remove(m5);
    cout << "\n===== Folder remove =====\n";
    f1.print(); f2.print(); cout << endl;
    m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

    return 0;
}