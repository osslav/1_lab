#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#include "Person.h"
#include "MyStack.h"
#include <QString>

class PersonKeeper
{
private:
    PersonKeeper() {}
    ~PersonKeeper() {}

    PersonKeeper(const PersonKeeper&) {}
    const PersonKeeper& operator =(const PersonKeeper&) { return instance(); }

public:
    static PersonKeeper& instance()
    {
        static PersonKeeper p;
        return p;
    }

    MyStack<Person> readPersons(const QString& fileName);
    void writePersons(MyStack<Person> stack, const QString& fileName);
};

#endif // PERSONKEEPER_H
