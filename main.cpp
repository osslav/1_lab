#include <MyStack.h>
#include <QTextStream>
QTextStream cout(stdout);

int main() {
    double arr[6] = { 1, 2, 3, 4, 5, 6 };
    double arr1[6] = { 11, 12, 13, 14, 15, 16 };
    MyStack<double> test(arr, 5), test1(arr1, 6);
    test = test1;

    while (test.getCount() > 0)
    {
        cout << test.top() << ' ';
        test.pop();
    }
    cout << endl;

    return 0;
}
