#ifndef MYSTACK_H
#define MYSTACK_H

template <class T>
class MyStack;

template <class T>
class Node
{
private:
	Node<T>* next;
	int elem;

	friend class MyStack<T>;
};

template <class T>
class MyStack
{
private:
	Node<T>* head;
	unsigned int countNode;

public:
	MyStack(const T* arr = nullptr, int count = 0);
	MyStack(const MyStack<T>& copy);

	~MyStack();
	
	MyStack& operator =(const MyStack& copy);
	
	void push(const T &newElem);							//add elem in stack
	const T top() const;									//get elem from stack
	void pop();												//delete elem from stack
	unsigned int getCount() { return countNode;	};

	
};



template <class T>
MyStack<T>::MyStack(const T* arr, int count)
{
    if ((arr && count == 0) || (!arr && count != 0))
	{
		arr = nullptr;
		count = 0;
	}

	head = nullptr;
	countNode = 0;

	for (int i = 0; i < count; i++)
	{
		Node<T>* oldHead = head;
		head = new Node<T>;

		head->next = oldHead;
		head->elem = arr[i];

		countNode++;
	}
}

template <class T>
MyStack<T>::MyStack(const MyStack& copy)
{
	head = nullptr;
	countNode = 0;

	if (copy.head)
	{
		head = new Node<T>;
		head->elem = copy.head->elem;
		countNode++;

		Node<T>* copyElem = copy.head->next;
		Node<T>* thisElem = head;
		while (copyElem)
		{
			thisElem->next = new Node<T>;
			thisElem = thisElem->next;
			thisElem->elem = copyElem->elem;

			copyElem = copyElem->next;
			countNode++;
		}
		thisElem->next = nullptr;
	}

}

template <class T>
MyStack<T>::~MyStack()
{
	while (head)
	{
		Node<T>* oldHead = head;
		head = head->next;
		delete oldHead;
	}
}

template <class T>
void MyStack<T>::push(const T& newElem)
{
    Node<T>* newHead = new Node<T>;
	newHead->elem = newElem;
	newHead->next = head;

	head = newHead;
}

template <class T>
const T MyStack<T>::top() const
{

	return head->elem;
}

template <class T>
void MyStack<T>::pop()
{

	Node<T>* oldHead = head;
	head = head->next;
	countNode--;

	delete oldHead;
}

template <class T>
MyStack<T>& MyStack<T>::operator =(const MyStack<T>& copy)
{
	if (this == &copy)
		return *this;

	countNode = copy.countNode;

	Node<T>* thisElem = head, * copyElem = copy.head;
	while (thisElem->next && copyElem)
	{
		thisElem->elem = copyElem->elem;
		
		if (thisElem->next) thisElem = thisElem->next;
		copyElem = copyElem->next;
	}

	if (copyElem)
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


