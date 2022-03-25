#include "PersonKeeper.h"

MyStack<Person> PersonKeeper::readPersons() const
{
    if (!stream)
        throw person_keeper_exc::EStreamError("Error! Stream is nullptr, you can't read stack of persons\n");

    if (!stream->device()->isReadable())
        throw person_keeper_exc::EStreamError("Error! We can't read from stream\n");

    MyStack<Person> stack;
    QString string;

    string = stream->readLine();
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

        string = stream->readLine();

        stack.push(newPerson);
    }
    return stack;
}

void PersonKeeper::writePersons(MyStack<Person> stack) const
{
    if (!stream)
        throw person_keeper_exc::EStreamError("Error! Stream is nullptr, you can't read stack of persons\n");

    if (!stream->device()->isWritable())
        throw person_keeper_exc::EStreamError("Error! We can't write in stream\n");


    while (stack.getCount() > 0)
    {
        *stream << stack.top().getLastName() << ' ';
        *stream << stack.top().getFirstName() << ' ';
        *stream << stack.top().getPatronymic() << '\n';
        stack.pop();
    }
}
