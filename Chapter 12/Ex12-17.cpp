#include <memory>

using namespace std;

void process(shared_ptr<int> ptr) {}
void process_unique(unique_ptr<int> ptr) {}

int main()
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef unique_ptr<int> IntP;

    // process_unique(pi2);
    IntP p2(pi2);

    return 0;
}