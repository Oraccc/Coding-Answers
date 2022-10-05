#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const char *c1 = "Hello ";
    const char *c2 = "World";

    char *c3 = new char[strlen(c1) + strlen(c2) + 1];

    strcpy(c3, c1);
    strcat(c3, c2);

    cout << c3 << endl;

    delete [] c3;

    return 0;
}