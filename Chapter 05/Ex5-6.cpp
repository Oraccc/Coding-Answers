#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int score;

    const vector<string> ranks = {"F", "D", "C", "B", "A", "S"};
    string rank;

    cin >> score;

    switch (score / 10){
        case 0: case 1: case 2: case 3: case 4: case 5:
            rank = ranks[0];
            break;
        case 6:
            rank = ranks[1];
            break;
        case 7:
            rank = ranks[2];
            break;
        case 8:
            rank = ranks[3];
            break;
        case 9:
            rank = ranks[4];
            break;
        case 10:
            rank = ranks[5];
            break;
        default:
            break;
    }

    cout << rank << endl;
}