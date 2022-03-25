#include "MyStack.h"
#include "PersonKeeper.h"
#include <QTextStream>
QTextStream cout(stdout);

int main()                                                          //тестовый пример
{
    try
    {
        Person arr[2];                                              //инициаллизация тестового стека
        arr[0].setLastName("Ivanov");
        arr[0].setFirstName("Ivan");
        arr[0].setPatronymic("Ivanovich");
        arr[1].setLastName("Sidorov");
        arr[1].setFirstName("Sidor");
        arr[1].setPatronymic("Sidorovich");
        MyStack<Person> testStack(arr, 2);                          //создание тестовых стеков

        QFile test_file("test_file.txt");                           //создание потока для работы с файлом "test_file.txt"
        QTextStream* stream = new QTextStream(&test_file);
        PersonKeeper::instance().setStream(stream);

        test_file.open(QIODevice::WriteOnly);                       //запись стека в файл
        PersonKeeper::instance().writePersons(testStack);
        test_file.close();

        test_file.open(QIODevice::ReadOnly);                        //чтение стека из файла
        MyStack<Person> testStack2 = PersonKeeper::instance().readPersons();
        test_file.close();

        PersonKeeper::instance().setStream(&cout);                  //вывод прочитанных данных в консоль(для проверки)
        PersonKeeper::instance().writePersons(testStack2);
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
