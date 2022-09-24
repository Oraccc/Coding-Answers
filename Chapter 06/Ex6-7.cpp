#include <iostream>
#include "Chapter6.h"

using namespace std;

int main()
{
    for (size_t i = 0; i != 10; ++i)
    {
        cout << count_calls() << endl;
    }

    return 0;
}