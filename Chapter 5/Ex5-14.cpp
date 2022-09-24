#include <iostream>
#include <string>

using namespace std;

int main()
{
    string currentStr, prevStr, maxStr;
    int repeat = 1, maxRepeat = 1;

    while (cin >> currentStr)
    {
        if (currentStr == prevStr)
        {
            ++repeat;
        }

        else 
        {
            repeat = 1;
            prevStr = currentStr;
        }

        if (repeat > maxRepeat)
        {
            maxRepeat = repeat;
            maxStr = currentStr;
        }
    }

    if (maxRepeat > 1)
    {
        cout << "Word: " << maxStr << " occurs " << maxRepeat << " times \n";
    }
    else
    {
        cout << "No Repeated Words! \n"; 
    }
}