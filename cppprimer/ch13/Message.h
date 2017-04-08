#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
#include <set>
#include <iostream>
#include "./Folder.h"
using namespace std;


class Folder;

class Message{
    friend class Folder;
public:
    explicit Message(const string & str = ""):contents(str){}

    Message(const Message &);
    Message & operator=(const Message & rhs);
    ~Message();

    void save(Folder &);
    void remove(Folder &);

    string & getMessage() const;
private:
    string contents;//消息文本
    set<Folder*> folders;

    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

string & Message::getMessage() const
{
   return contents; 
}


void Message::save(Folder & f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder & f)
{
    folders.erase(&f);
    f.remMsg(this);
}


void Message::add_to_Folders(const Message & m)
{
    for(auto f : m.folders)
        f->addMsg(this);
}

Message::Message(const Message & m):contents(m.contents), folders(m.folders)
{
    add_to_Folders(m); 
}

void Message::remove_from_Folders()
{
    for(auto f : folders)
        f->remMsg(this);
}

Message::~Message()
{
    remove_from_Folders();
}

Message & Message::operator=(const Message & rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;

    add_to_Folders(rhs);
    return *this;
}

void Message::add_to_Folders(const Message &m)
{
    for(set<Folder*>::iterator f = m.folders.begin(); f != m.folders.end(); ++f)
        (*f)->addMsg(this);
}


void MESSAGE_H_::remove_from_Folders()
{
    for(set<Folder *>::iterator f = folders.begin(); f != folders.end(); ++f)
        (*f)->remMsg(this);

    folders.clear();
}

#endif
