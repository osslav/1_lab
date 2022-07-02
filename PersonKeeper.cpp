#include "PersonKeeper.h"

//чтение данных из потока в стек элементов Person
MyStack<Person> PersonKeeper::readPersons() const
{
    if (!stream)                                                                                                //проверки что поток существует и открыт для чтения
        throw person_keeper_exc::EStreamError("Error! Stream is nullptr, you can't read stack of persons\n");

    MyStack<Person> stack;

    if (!stream->atEnd())                                                                   //проверка - есть ли данные в потоке
    {
        if (!stream->device()->isReadable())
            throw person_keeper_exc::EStreamError("Error! We can't read from stream\n");
                                                                                       //создаем стек для сохранения результата
        QString string;                                                                                             //буфер для хранения считанной из потока строки

        string = stream->readLine();                                                                                //из потока считываем строку целиком в буфер
        int startIndex = 0, lenth = 0;                                                                              //индекс начала и длина текущего слова для обработки буфера
        while (string.length() != 0)                                                                                //пока последняя считанная строка из потока не пуста, заполняем стек
        {
            Person newPerson;                                                                                       //новый объект для стека
                                                                                                                    //копирование из строки в поля Person ведется посимвольно
            bool isEndCurrentPerson = false;                                                                        //флаг - была ли встречена запятая в буфере
            for (int partName = 0; partName < Person::COUNT_PART_NAME && !isEndCurrentPerson; partName++)           //пока не все имя заполнено и не конец имени в буфере, сохраняем в newPerson
            {
                startIndex = startIndex + lenth;                                                                    //обновление индекса и длины
                lenth = 0;

                while(startIndex < string.length() && string.at(startIndex) == ' ')   //удаляем незначащие пробелы и запятые
                    startIndex++;

                while(startIndex + lenth < string.length() && string.at(startIndex + lenth) != ' ' && string.at(startIndex + lenth) != ',')       //подсчет длины текущего слова
                    lenth++;

                if(startIndex + lenth >= string.length() || string.at(startIndex + lenth) == ',')                      //проверяем достигли ли мы конца имени в строке
                    isEndCurrentPerson = true;

                switch(partName)                                                                                    //определяем часть имени и копируем туда полученную строку
                {
                    case 0: newPerson.setLastName(string.mid(startIndex, lenth));
                    break;
                    case 1: newPerson.setFirstName(string.mid(startIndex, lenth));
                    break;
                    case 2: newPerson.setPatronymic(string.mid(startIndex, lenth));
                }

            }

            while(startIndex + lenth < string.length() && string.at(startIndex + lenth - 1) != ',')                 //ищем конец имени в буфере(если вдруг он не был найден ранее)
                lenth++;


            if (startIndex + lenth >= string.length())                                                              //если мы вышли за границу буфера, то обновляем его, индекс начала имени и длину
            {
                startIndex = lenth = 0;
                string = stream->readLine();
            }



            stack.push(newPerson);                                                                                  //заносим в стек элемент
        }
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
