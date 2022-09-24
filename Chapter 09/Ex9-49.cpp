#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool containAscenderOrDescender(const string &s)
{
    const string ascenders_and_descenders{"bdfghijklpqty"};
    return s.find_first_of(ascenders_and_descenders) != string::npos;
}

int main() 
{
    string filename;
    cin >> filename;
    ifstream in(filename);
    
    if (in.is_open()) 
    {
        string longestWord, word;
        while (in >> word)
        {
            if (!containAscenderOrDescender(word) && word.size() > longestWord.size())
                longestWord = word;
        }
        
        if (longestWord.empty())
            cout << "There is no word contains neither ascenders nor descenders in file " 
            << filename << endl;
        else
            cout << "The longest word that contains neither ascenders nor descenders in file " 
            << filename << " is \"" << longestWord << "\"." << endl;
    } 
    else 
    {
        cerr << "Can not open file: " << filename << endl;
    }

    return 0;
}