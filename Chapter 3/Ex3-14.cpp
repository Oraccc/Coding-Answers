#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string word;
    vector<string> text;

    while (cin >> word)
    {
        // cout << word << endl;
        text.push_back(word);
    }
    return 0;
}