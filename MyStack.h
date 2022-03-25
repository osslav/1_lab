#ifndef MYSTACK_H
#define MYSTACK_H

#include "Exception.h"

template <class T>                                      //объявление шаблонного класса для стека
class MyStack;

template <class T>                                      //определение класса для элемента стека
class Node
{
private:                                                //все его поля закрыты и доступны только для класса стека
    Node<T>* next;                                      //стек односвязный, поэтому один указатель на следующий элемент
    T elem;                                           //данные элемента стека

	friend class MyStack<T>;
};

template <class T>                                      //определение класса для стека
class MyStack
{
private:
    Node<T>* head;                                      //верхний элемент стека
    unsigned int countNode;                             //количество элементов стека

public:
    MyStack(const T* arr = nullptr, int count = 0);     //конструктор из массива(используется еще как конструктор по умолчанию)
    MyStack(const MyStack<T>& copy);                    //конструктор копирования

    ~MyStack();                                         //деструктор
	
    MyStack& operator =(const MyStack& copy);           //опреация присваивания
	
    void push(const T &newElem);						//добавление элемента в стек
    const T top() const;								//получение элемента из стека(без удаления)
    void pop();											//удаление верхнего элемента из стека
    unsigned int getCount() { return countNode;	};      //получение длины стека

	
};



template <class T>                                      //определение конструктора из массива для стека
MyStack<T>::MyStack(const T* arr, int count)            //требуется массив и количество элементов массива
{
    if ((arr && count == 0) || (!arr && count != 0))    //предотвращение проблем при работе с массивом
	{
		arr = nullptr;
		count = 0;
	}

	head = nullptr;
	countNode = 0;

    for (int i = 0; i < count; i++)                     //запись элементов массива в стек
	{
		Node<T>* oldHead = head;
		head = new Node<T>;

		head->next = oldHead;
		head->elem = arr[i];

		countNode++;
	}
}

template <class T>                                      //конструктор копирования для стека
MyStack<T>::MyStack(const MyStack& copy)                //требуется константная ссылка на стек
{
	head = nullptr;
	countNode = 0;

    if (copy.head)                                      //запись первого элемента в стек
	{
		head = new Node<T>;
		head->elem = copy.head->elem;
		countNode++;

		Node<T>* copyElem = copy.head->next;
		Node<T>* thisElem = head;
        while (copyElem)                                //пока есть элементы в копируемом стеке, происходит запись
		{
			thisElem->next = new Node<T>;
			thisElem = thisElem->next;
			thisElem->elem = copyElem->elem;

			copyElem = copyElem->next;
			countNode++;
		}
        thisElem->next = nullptr;                       //поскольку элементов для записи больше нет, записываем в поле next последнего элемента nullptr
	}

}

template <class T>
MyStack<T>::~MyStack()                                  //деструктор стека
{
    while (head)                                        //удалем элементы пока они есть
	{
		Node<T>* oldHead = head;
		head = head->next;
		delete oldHead;
	}
}

template <class T>                                      //функция записи нового элемента в стек
void MyStack<T>::push(const T& newElem)                 //требуется константная ссылка на элемент, функция ничего не возвращает
{
    Node<T>* newHead = new Node<T>;                     //создание нового элемента стека
	newHead->elem = newElem;
	newHead->next = head;

    head = newHead;                                     //запись его в голову стека
    countNode++;
}

template <class T>                                      //функция взятие элемента из головы стека
const T MyStack<T>::top() const                         //функция не изменяет полей класса и не требует аргументов, возвращает элемент из головы стека
{
    if (countNode == 0)                                 //если стек пуст, то срабатывает исключение
        throw stack_exc::EStackEmpty("Error! Stack empty, you can't get elem\n");

    return head->elem;                                  //возвращает элемент
}

template <class T>                                      //функция удаления элемента из головы стека
void MyStack<T>::pop()                                  //аргументов не требует, ничего не возвращает
{
    if (countNode == 0)                                 //если стек пуст, то срабатывает исключение
        throw stack_exc::EStackEmpty("Error! Stack empty, you can't delete elem\n");

    Node<T>* oldHead = head;                            //перезапись головы стека
	head = head->next;
	countNode--;

    delete oldHead;                                     //удаление старой головы стека
}

template <class T>                                      //опреатор присваивания стека
MyStack<T>& MyStack<T>::operator =(const MyStack<T>& copy)          //требует ссылку на копируемый стек, возвращает ссылку на текущий стек
{
    if (this == &copy)                                  //если мы присваиваем стек самому себе, то можно завершить функцию
		return *this;

	countNode = copy.countNode;

    Node<T>* thisElem = head, * copyElem = copy.head;   //для экономии ресурсов элементы не пересоздаются, а принимают новые данные, пока возможно избежать удаления или создания элементов
	while (thisElem->next && copyElem)
	{
		thisElem->elem = copyElem->elem;
		
		if (thisElem->next) thisElem = thisElem->next;
		copyElem = copyElem->next;
	}

    if (copyElem)                                       //в зависимости от того, какой стек был длиннее - мы либо удаляем лишние узлы из текущего стека, либо создаем дополнительные
	{
		while (copyElem)
		{
			thisElem->elem = copyElem->elem;

			copyElem = copyElem->next;

			if (copyElem)
			{
				thisElem->next = new Node<T>;
				thisElem = thisElem->next;
			}
			else
				thisElem->next = nullptr;
		}
		
	}
	else
	{
		Node<T>* oldThisElem = thisElem;
		thisElem = thisElem->next;
		oldThisElem->next = nullptr;
		while (thisElem)
		{
			Node<T>* oldElem = thisElem;
			thisElem = thisElem->next;
			delete oldElem;
		}
	}

	return *this;
}
#endif // !MYSTACK_H


