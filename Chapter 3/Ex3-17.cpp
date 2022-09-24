#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string word;
    vector<string> text;

    while (cin >> word)
    {
        text.push_back(word);
    }

    for (auto &i : text)
    {
        for (auto &j : i)
        {
            j = toupper(j);
        }
    }

    for (auto i : text)
    {
        cout << i << endl;
    }

    return 0;
}