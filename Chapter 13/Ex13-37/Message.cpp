#include "Message.h"
#include "Folder.h"

using namespace std;

void swap(Message &lhs, Message &rhs) 
{
    using std::swap;
    for (auto &fp : lhs.folders)
        fp->remMsg(&lhs);
    for (auto &fp : rhs.folders)
        fp->remMsg(&rhs);
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    for (auto &fp : lhs.folders)
        fp->addMsg(&lhs);
    for (auto &fp : rhs.folders)
        fp->addMsg(&rhs);
}

void Message::addFdr(Folder *fp) 
{
    folders.insert(fp);
}

void Message::remFdr(Folder *fp) 
{
    folders.erase(fp);
}

void Message::save(Folder &f) 
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) 
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_folders(const Message &m) 
{
    for (auto &fp : m.folders)
        fp->addMsg(this);
}

void Message::remove_from_folders() 
{
    for (auto &fp : folders)
        fp->remMsg(this);
}

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) 
{
    add_to_folders(m);
}

Message &Message::operator=(const Message &rhs) 
{
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}

Message::~Message() 
{
    remove_from_folders();
}

void Message::print() 
{
    cout << "Message <" << this << ">:<" << contents << "> in "
                << folders.size() << " folders:\n";
    for (const auto &fp : folders)
        cout << "\t<" << fp << ">\n";
}