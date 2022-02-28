#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <cstring>

namespace stack_exc 
{
	class EStackException
	{
	private:
		char* message;
	public:
		EStackException(const char* arg_message)
		{
			message = new char[strlen(arg_message) + 1];
			strcpy_s(message, strlen(arg_message) + 1, arg_message);
		}
		EStackException(const EStackException& arg)
		{
			message = new char[strlen(arg.message) + 1];
			strcpy_s(message, strlen(arg.message) + 1, arg.message);
		}
		~EStackException()
		{
			delete message;
		}
		const char* what() const { return message; }

	};

	class EStackEmpty : public EStackException
	{
	public:
		explicit EStackEmpty(const char* arg) : EStackException(arg) {}
		EStackEmpty(const EStackEmpty& arg) : EStackException(arg) {}
	};

}

#endif
