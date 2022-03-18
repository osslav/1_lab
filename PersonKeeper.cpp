#include "PersonKeeper.h"
#include <QTextStream>
#include <QFile>

MyStack<Person> PersonKeeper::readPersons(const QString& fileName)
{
    MyStack<Person> stack;
    QFile file (fileName);

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString string;

        string = stream.readLine();
        while (string.length() != 0)
        {
            Person newPerson;

            int startIndex = -1, lenth = 0;
            for (int partName = 0; partName < Person::COUNT_PART_NAME; partName++)
            {
                startIndex = startIndex + lenth + 1;
                lenth = 0;

                while(startIndex + lenth < string.length() && string[startIndex + lenth] != ' ')
                    lenth++;

                switch(partName)
                {
                    case 0: newPerson.setLastName(string.mid(startIndex, lenth));
                    break;
                    case 1: newPerson.setFirstName(string.mid(startIndex, lenth));
                    break;
                    case 2: newPerson.setPatronymic(string.mid(startIndex, lenth));
                }

            }

            string = stream.readLine();

            stack.push(newPerson);
        }
        file.close();
    }
    return stack;
}

void PersonKeeper::writePersons(MyStack<Person> stack, const QString& fileName)
{
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        while (stack.getCount() > 0)
        {
            stream << stack.top().getLastName() << ' ';
            stream << stack.top().getFirstName() << ' ';
            stream << stack.top().getPatronymic() << '\n';
            stack.pop();
        }

        file.close();
    }
}
