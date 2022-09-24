#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        try
        {
            if (b == 0)
            {
                throw runtime_error("Divided By Zero!");
            }
            cout << a/b << endl;
        }
        catch (runtime_error err)
        {
            cout << err.what() << endl;
            cout << "Enter Again? Enter 'y' or 'n': ";
            char c;
            cin >> c;
            if (!cin || c == 'n') break;
        }
    }
}