#include "Person.h"

Person::Person(const Person& copy)
{
    first_name = copy.first_name;
}

const std::string& Person::getLastName() const
{
    return last_name;
}

const std::string& Person::getFirstName() const
{
    return first_name;
}

const std::string& Person::getPatronymic() const
{
    return first_name;
}

void Person::setLastName(const std::string& copy)
{
    last_name = copy;
}

void Person::setFirstame(const std::string& copy)
{
    first_name = copy;
}

void Person::getPatronymic(const std::string& copy)
{
    patronymic = copy;
}
