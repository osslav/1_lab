#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
    std::string last_name;
    std::string first_name;
    std::string patronymic;
public:
    Person();
    Person(const Person&);
    const std::string& getLastName() const { return last_name; }
    const std::string& getFirstName() const { return first_name; }
    const std::string& getPatronymic() const { return first_name; }
    void setLastName(const std::string& copy) { last_name = copy; }
    void setFirstame(const std::string& copy) { first_name = copy; }
    void getPatronymic(const std::string& copy) { patronymic = copy; }
};


#endif // PERSON_H
