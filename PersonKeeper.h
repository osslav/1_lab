#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#include "Person.h"
#include "MyStack.h"
#include <QString>
#include <QTextStream>
#include <QFile>

class PersonKeeper
{
private:
    QTextStream* stream = nullptr;

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

    void setStream(QTextStream* newStream) { stream = newStream; }


    MyStack<Person> readPersons() const;
    void writePersons(MyStack<Person> stack) const;
};

#endif // PERSONKEEPER_H
