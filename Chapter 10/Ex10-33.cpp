#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char**argv) 
{
    if (argc < 4) 
    {
        return -1;
    }
    ifstream in(argv[1]);

    ofstream out_odd(argv[2]), out_even(argv[3]);

    istream_iterator<int> i_iter(in), eof;
    ostream_iterator<int> odd_iter(out_odd, " "), even_iter(out_even, "\n");
    
    for_each(i_iter, eof, [&](int i) { i % 2 ? odd_iter = i : even_iter = i; });

    return 0;
}