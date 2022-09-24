#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Screen;

class Window_mgr
{
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);
    Window_mgr();

private:
    vector<Screen> screens;
};

class Screen 
{
friend void Window_mgr::clear(ScreenIndex);

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

Window_mgr::Window_mgr() : screens{Screen(24, 80, ' ')} {}

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

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
    Window_mgr windows;

    windows.clear(0);

    return 0;
}