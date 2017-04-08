#ifndef FOLDER_H_
#define FOLDER_H_

#include <string>
#include <set>
#include <iostream>
#include "./Message.h"
using namespace std;

class Message;

class Folder{
    friend class Message;
public:
    Folder(){}
    Folder(const Folder & );
    Folder & operator=(const Folder &);
    ~Folder();
    
    void save(Message & );
    void remove(Message &);
    void debug_print();
private:
    void add_to_Messages(const Folder & f);
    void remove_from_Msgs();
    void addMsg(Message * m);
    void remMsg(Message * m);

private:
    string name;
    set<Message *> msgs;
};

void Folder::add_to_Messages(const Folder & f)
{
    for(set<Message*>::iterator msg = f.msgs.begin(); msg != f.msgs.end(); ++msg)
        (*msg)->save(this);
}

Folder::Folder(const Folder & f):msgs(f.msgs)
{
    add_to_Messages(f);
}

Folder & Folder::operator=(const Folder & f)
{
    remove_from_Msgs();
    msgs = f.msgs;
    add_to_Messages(f);

    return * this;
}

void Folder::remove_from_Msgs()
{
    while(!msgs.empty())
        (*msgs.begin())->remove(*this);
}

void Folder::print()
{
    cout << "name: " << name << ", Message: ";
    for(auto m : messages){
        cout << m->getMessage() << endl;
    }
}

void Folder::addMsg(Message * m)
{
    messages.insert(m);
}

void Folder::remMsg(Message * m)
{
    messages.erase(m);
}


#endif
