#include "Person.h"

Person::Person(const Person& copy)
{
    first_name = copy.first_name;
}

const QString& Person::getLastName() const
{
    return last_name;
}

const QString& Person::getFirstName() const
{
    return first_name;
}

const QString& Person::getPatronymic() const
{
    return first_name;
}

void Person::setLastName(const QString& copy)
{
    last_name = copy;
}

void Person::setFirstName(const QString& copy)
{
    first_name = copy;
}

void Person::setPatronymic(const QString& copy)
{
    patronymic = copy;
}
