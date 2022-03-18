#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
private:
    QString last_name;
    QString first_name;
    QString patronymic;
public:
    Person() {}
    Person(const Person&);
    const QString& getLastName() const;
    const QString& getFirstName() const;
    const QString& getPatronymic() const;
    void setLastName(const QString& copy);
    void setFirstName(const QString& copy);
    void setPatronymic(const QString& copy);
};



#endif // PERSON_H
