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

private:
    pos cursor = 0;
    pos width = 0;
    pos height = 0;
    string contents;
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

int main()
{
    return 0;
}