#include "Message.h"
#include "Folder.h"

using namespace std;

void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    for (auto &mp : lhs.messages)
        mp->remFdr(&lhs);
    for (auto &mp : rhs.messages)
        mp->remFdr(&rhs);
    swap(lhs.messages, rhs.messages);
    for (auto &mp : lhs.messages)
        mp->addFdr(&lhs);
    for (auto &mp : rhs.messages)
        mp->addFdr(&rhs);
}

void Folder::addMsg(Message *mp) 
{
    messages.insert(mp);
}

void Folder::remMsg(Message *mp) 
{
    messages.erase(mp);
}

void Folder::save(Message &m) 
{
    messages.insert(&m);
    m.addFdr(this);
}

void Folder::remove(Message &m) 
{
    messages.erase(&m);
    m.remFdr(this);
}

Folder::Folder(const Folder &f) : messages(f.messages) 
{
    for (auto &mp : messages)
        mp->addFdr(this);
}

Folder &Folder::operator=(const Folder &rhs) 
{
    for (auto &mp : messages)
        mp->remFdr(this);
    messages = rhs.messages;
    for (auto &mp : messages)
        mp->addFdr(this);
    return *this;
}

Folder::~Folder() 
{
    for (auto &mp : messages)
        mp->remFdr(this);
}

void Folder::print() 
{
    cout << "Folder <" << this << "> contains " << messages.size()
                << " messages:\n";
    for (const auto &mp : messages)
        cout << "\t<" << mp << ">:<" << mp->contents << ">\n";
}
