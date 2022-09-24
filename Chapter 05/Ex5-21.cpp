#include <iostream>
#include <string>

using namespace std;

int main()
{
    string prevString, nextString;
    bool repeated = false;

    while (cin >> nextString)
    {
        if (nextString[0] < 'A' || nextString[0] > 'Z')
        {
            prevString = nextString;
        }
        else if (prevString == nextString)
        {
            cout << "Repeated Words: " << nextString << endl;
            repeated = true;
            break;
        }
        else
        {
            prevString = nextString;
        }
    }
    if (!repeated)
    {
        cout << "No Repeated Words!" << endl;
    }

    return 0;
}