#include <memory>
#include <iostream>

using namespace std;

struct destination
{
    unsigned id;
    explicit destination(unsigned des_id = 0) : id(des_id) {}
};

struct connection
{
    destination *dest;
};

connection connect(destination *dest)
{
    connection new_conn;
    new_conn.dest = dest;
    cout << "Setup connection to " << new_conn.dest->id << endl;
    return new_conn;
}

void disconnect(connection conn)
{
    cout << "Stop connection to " << conn.dest->id << endl;
}

void f(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> p(&c, [](connection *p){ disconnect(*p); });

    cout << "Using connection " << c.dest->id << endl;
}

int main()
{
    destination d(5);
    f(d);

    return 0;
}