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
    const std::string& getLastName() const;
    const std::string& getFirstName() const;
    const std::string& getPatronymic() const;
    void setLastName(const std::string& copy);
    void setFirstame(const std::string& copy);
    void getPatronymic(const std::string& copy);
};



#endif // PERSON_H
