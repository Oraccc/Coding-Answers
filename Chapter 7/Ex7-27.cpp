#include <string>
#include <iostream>

using namespace std;

class Screen 
{
public:
    using pos = string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' '){}
    Screen(pos ht, pos wd, char c)
        : height(ht), width(wd), contents(ht * wd, c){}

    char get() const { return contents[cursor];}
    char get(pos ht, pos wd) const;

    Screen &move(pos row, pos col);

    Screen &set(char);
    Screen &set(pos, pos, char);

    Screen &display(ostream &os)
        {do_display(os); return *this;}

    const Screen &display(ostream &os) const
        {do_display(os); return *this;}

private:
    pos cursor = 0;
    pos width = 0;
    pos height = 0;
    string contents;

    void do_display(ostream &os) const {os << contents;}
};

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    
    return 0;
}