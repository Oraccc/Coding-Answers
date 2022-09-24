#include <string>

using namespace std;

string (&func1())[10];

using arrString = string[10];

arrString& func2();

auto func3() -> string(&)[10];

string str[10] = {};

decltype(str) &func4();

int main()
{
    return 0;
}