#include <iostream>

using namespace std;

class Debug {
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o)
        : hw(h), io(i), other(o) {}

    constexpr bool any() const { return hw || io || other; }
    void set_hw(bool b) { hw = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { other = b; }

private:
    bool hw;
    bool io;
    bool other;
};

int main() {
    constexpr Debug io_sub(false, true, false);
    if (io_sub.any())
        cout << "Error message 1" << endl;

    constexpr Debug nodbg = false;
    if (nodbg.any())
        cout << "Error message 2" << endl;

    Debug dbg(false);
    if (dbg.any())
        cout << "Error message 3" << endl;

    dbg.set_other(true);
    if (dbg.any())
        cout << "Error message 4" << endl;


    return 0;
}