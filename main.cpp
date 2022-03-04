#include <MyStack.h>
#include <QTextStream>
QTextStream cout(stdout);

int main()                                                      //тестовый пример
{
    try
    {
        double arr[6] = { 0.1, 0.2, 0.3, 0.4, 0.5, 0.6 };
        double arr1[6] = { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6 };
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
