#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<string> vs;
    for (string number; cin >> number; vs.push_back(number)) {}

    double sum = 0;
    for (const auto &s : vs)
        sum += stod(s);
    
    cout << sum << endl;

    return 0;
}