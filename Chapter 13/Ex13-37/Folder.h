#include <set>
#include <string>
#include <iostream>

using namespace std;
class Message;

class Folder 
{
friend class Message;
friend void swap(Message &, Message &);
friend void swap(Folder &, Folder &);

public:
    Folder() = default;

    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();

    void save(Message &);
    void remove(Message &);

    void print();

private:
    set<Message *> messages;

    void addMsg(Message *);
    void remMsg(Message *);
};

void swap(Folder &, Folder &);