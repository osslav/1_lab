#include <MyStack.h>
#include <QTextStream>
QTextStream cout(stdout);

int main()                                                      //тестовый пример
{
    try
    {
        double arr[6] = { 1, 2, 3, 4, 5, 6 };
        double arr1[6] = { 11, 12, 13, 14, 15, 16 };
        MyStack<double> test(arr, 5), test1(arr1, 6);           //создание тестовых стеков
        test = test1;                                           //пример работы оператора =

        while (test.getCount() > 0)                             //пока стек не пуст, в консоль выводится верхний элемент и затем удаляется
        {
            cout << test.top() << ' ';
            test.pop();
        }
        test.pop();                                             //здесь стек пуст, поэтому срабатывает исключение
        cout << endl;

    }
    catch (const stack_exc::EStackEmpty & e)                    //отлов исключений, связанных с тем, что стек пуст
    {
        cout << "\nException EStackEmpty: " << e.what();
    }
    catch (...)                                                 //отлов других исключений, о которых ничего не известно
    {
        cout << "\nUnknow error\n";
    }

    return 0;
}
