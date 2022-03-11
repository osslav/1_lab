#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#include "Person.h"

class PersonKeeper
{
private:
    Person myPerson;

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

    bool readPersons(const std::string& fileName);
    bool writePersons(const std::string& fileName);
};

#endif // PERSONKEEPER_H
