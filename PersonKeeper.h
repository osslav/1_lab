#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#include "Person.h"
#include "MyStack.h"
#include <QString>
#include <QTextStream>
#include <QFile>
#include <memory>

//класс для чтения/записи стека из Person, выполнен по примеру паттерна Singleton
class PersonKeeper
{
private:
    std::unique_ptr<QTextStream> stream;                                            //текущий поток

    PersonKeeper() {}                                                               //запрет на доступ снаружи для конструкторов, деструктора и оператора =
    ~PersonKeeper() {}

    PersonKeeper(const PersonKeeper&) {}
    const PersonKeeper& operator =(const PersonKeeper&) { return instance(); }

public:
    static PersonKeeper& instance()                                                 //функция получения ссылки на объект PersonKeeper
    {
        static PersonKeeper p;
        return p;
    }

    void setStream(std::unique_ptr<QTextStream> newStream) { stream = std::move(newStream); }                   //функция установки текущего потока
    std::unique_ptr<QTextStream> getStream() { auto outStream = std::move(stream); return outStream; }          //функция возврата текущего потока

    MyStack<Person> readPersons() const;                                            //чтение и запись из потока стека из элементов Person
    void writePersons(MyStack<Person> stack) const;
};

#endif // PERSONKEEPER_H
