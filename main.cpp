#include "MyStack.h"
#include "PersonKeeper.h"
#include <QTextStream>

QTextStream cout(stdout);

QString testFileName("test_file4.txt");                                                     //имя тестового текстового файла

int main()                                                                                  //тестовый пример
{
    try
    {
        QFile test_file(testFileName);                                                      //инициаллизация тестового файла
        std::unique_ptr<QTextStream> streamFile(new QTextStream(&test_file));               //создание указателя на файловый поток
        std::unique_ptr<QTextStream> streamCout(new QTextStream(stdout));                   //создание указателя на консольный поток вывода
        PersonKeeper::instance().setStream(std::move(streamFile));                          //установка файлового потока в PersonKepeer

                                                                                            //чтение стека из тестового файла
        test_file.open(QIODevice::ReadOnly);                                                //открытие файла на чтение
        MyStack<Person> testStack2 = PersonKeeper::instance().readPersons();                //непосредственно чтение
        test_file.close();                                                                  //закрытие файла

        PersonKeeper::instance().setStream(std::move(streamCout));                          //установка консольного потока в PersonKepeer
        PersonKeeper::instance().writePersons(testStack2);                                  //вывод прочитанных данных в консоль(для проверки)
    }
    catch (const stack_exc::EStackEmpty & e)                        //отлов исключений, связанных с тем, что стек пуст
    {
        cout << "\nException in MyStack, EStackEmpty: " << e.what();
    }
    catch(const person_keeper_exc::EStreamError & e)                //отлов исключений, связанных с потоком в методах класса PersonKeeper
    {
        cout << "\nException in PersonKeeper, EStreamError: " << e.what();
    }
    catch (...)                                                     //отлов других исключений, о которых ничего не известно
    {
        cout << "\nUnknow error\n";
    }

    return 0;
}
