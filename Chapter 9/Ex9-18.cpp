#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    deque<string> words;
    string word;

    while (cin >> word)
        words.push_back(word);
        
    for (auto it = words.cbegin(); it != words.cend(); ++it)
        cout << *it << endl;
    
    return 0;
}