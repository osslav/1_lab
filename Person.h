#ifndef PERSON_H
#define PERSON_H

#include <QString>
//класс для хранения ФИО человека
class Person
{
private:
    QString last_name;      //фамилия
    QString first_name;     //имя
    QString patronymic;     //отчество
public:
    const QString& getLastName() const;
    const QString& getFirstName() const;
    const QString& getPatronymic() const;
    void setLastName(const QString& copy);
    void setFirstName(const QString& copy);
    void setPatronymic(const QString& copy);

    static const int COUNT_PART_NAME = 3;       //количество частей имени
};



#endif // PERSON_H
