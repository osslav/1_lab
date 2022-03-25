#include "PersonKeeper.h"

//чтение данных из потока в стек элементов Person
MyStack<Person> PersonKeeper::readPersons() const
{
    if (!stream)                                                                                                //проверки что поток существует и открыт для чтения
        throw person_keeper_exc::EStreamError("Error! Stream is nullptr, you can't read stack of persons\n");

    if (!stream->device()->isReadable())
        throw person_keeper_exc::EStreamError("Error! We can't read from stream\n");

    MyStack<Person> stack;
    QString string;

    string = stream->readLine();                                                                                //из потока считываем строку целиком(предполагая что в ней ФИО)
    while (string.length() != 0)                                                                                //пока последняя считанная строка из потока не пуста, заполняем стек
    {
        Person newPerson;
                                                                                                                //копирование из строки в поля Person ведется посимвольно
        int startIndex = -1, lenth = 0;                                                                         //для этого инициаллизируем переменные для индекса текущего символа и длины слова
        for (int partName = 0; partName < Person::COUNT_PART_NAME; partName++)                                  //копируем сиволы из строки пока не заполним все части имени
        {
            startIndex = startIndex + lenth + 1;                                                                //обновление индекса и длины
            lenth = 0;

            while(startIndex + lenth < string.length() && string[startIndex + lenth] != ' ')                    //подсчет длины текущего слова
                lenth++;

            switch(partName)                                                                                    //определяем часть имени и копируем туда полученную строку
            {
                case 0: newPerson.setLastName(string.mid(startIndex, lenth));
                break;
                case 1: newPerson.setFirstName(string.mid(startIndex, lenth));
                break;
                case 2: newPerson.setPatronymic(string.mid(startIndex, lenth));
            }

        }

        string = stream->readLine();                                                                            //считываем следующую строку и заносим в стек элемент

        stack.push(newPerson);
    }
    return stack;
}

//запись данных из потока в стек элементов Person
void PersonKeeper::writePersons(MyStack<Person> stack) const
{

    if (!stream)                                                                                                //проверки что поток существует и открыт для записи
        throw person_keeper_exc::EStreamError("Error! Stream is nullptr, you can't read stack of persons\n");

    if (!stream->device()->isWritable())
        throw person_keeper_exc::EStreamError("Error! We can't write in stream\n");


    while (stack.getCount() > 0)                                                                                //пока стек не пуст, записываем данные в поток
    {
        *stream << stack.top().getLastName() << ' ';
        *stream << stack.top().getFirstName() << ' ';
        *stream << stack.top().getPatronymic() << '\n';
        stack.pop();
    }
}
