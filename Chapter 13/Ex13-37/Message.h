#include <string>
#include <set>
#include <iostream>

using namespace std;
class Folder;

class Message 
{
friend class Folder;
friend void swap(Message &, Message &);
friend void swap(Folder &, Folder &);
public:
    explicit Message(const string &s = "") : contents(s), folders() {}

    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

    void print();

private:
    string contents;
    set<Folder *> folders;

    void add_to_folders(const Message &);
    void remove_from_folders();

    void addFdr(Folder *);
    void remFdr(Folder *);
};

void swap(Message &, Message &);
