#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string words;
    vector<string> text;
    while (getline(cin, words))
    {
        text.push_back(words);
    }

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        for (auto c = (*it).begin(); c != (*it).end(); ++c)
        {
            *c = toupper(*c);
        }
    }

    for (auto it = text.cbegin(); it != text.cend(); ++it)
    {
        cout << *it << endl;
    }
    
    return 0;
}