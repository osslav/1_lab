#include "Person.h"

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
    return patronymic;
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
