#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <cstring>

namespace stack_exc 
{
    class EStackException                                               //класс для исключений стека
	{
	private:
        char* message;                                                  //закрытое поле - сообщение о сработавшем исключении
	public:
        EStackException(const char* arg_message)                        //конструктор из константной строки
		{
            message = new char[strlen(arg_message) + 1];
			strcpy_s(message, strlen(arg_message) + 1, arg_message);
		}
        EStackException(const EStackException& arg)                     //конструктор копирования
		{
			message = new char[strlen(arg.message) + 1];
			strcpy_s(message, strlen(arg.message) + 1, arg.message);
		}
        ~EStackException()                                              //деструктор
		{
			delete message;
		}
        const char* what() const { return message; }                    //функция, возвращающее константную строку - сообщение об исключении

	};

    class EStackEmpty : public EStackException                          //класс наследник для EStackException, нужен для исключений, связанных с тем, что стек пуст
    {                                                                   //новых полей не содержит - только поле с сообщением из EStackException
	public:
        explicit EStackEmpty(const char* arg) : EStackException(arg) {}     //конструктор из константной строки, запрещено неявное использование
        EStackEmpty(const EStackEmpty& arg) : EStackException(arg) {}       //конструктор копирования, неявное использование разрешено для работы catch()
	};

}

#endif
