#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    multimap<string, string> publishers;

    publishers.insert({"Alice", "Book A"});
    publishers.insert({"Alice", "Book B"});
    publishers.insert({"Bob", "Book C"});
    publishers.insert({"Mio", "Book A"});
    publishers.insert({"Mio", "Book D"});
    publishers.insert({"Lanz", "Book A"});

    do
    {
        cout << "All publishers are :\n";
        for (const auto &e : publishers)
            cout << "Author: " << e.first << "\tBook Name: " << e.second << endl;
        
        string name;
        cout << "\nEnter the name you want to delete (Type 'Q' to quit): ";
        cin >> name;

        if (name == "Q")
            break;
        
        auto it = publishers.find(name);
        if (it != publishers.cend())
            publishers.erase(it->first);

        else
            cerr << "Not found!" << endl;
    } while (cin);
    
    
    return 0;
}