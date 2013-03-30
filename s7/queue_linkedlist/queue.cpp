#include <iostream>
#include "queue.h"
#include "../complex/complex.h"

template<class T>
Queue<T>::Item::Item(const T& v, Item *n)
{
	val = v;
	next = n;
}

template<class T>
Queue<T>::Queue()
{
	head = tail = new Item(0, NULL);
}

template<class T>
Queue<T>::~Queue()
{
	while(!isEmpty())
		pop();
	delete head;
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return head == tail;
}

template<class T>
void Queue<T>::push(const T& v)
{
	tail->val = v;
	tail->next = new Item(0, NULL);
	tail = tail->next;
}

template<class T>
T Queue<T>::pop()
{
	if(isEmpty())
		return 0;
	Item *tmp = head;
	head = head->next;
	T v = tmp->val;
	delete tmp;
	return v;
}

void __helper_Queue()
{
	Queue<int> qi;
	qi.push(5);
	Queue<float> qf;
	qf.push(5.5);
	Queue<Complex> qc;
	qc.push(Complex(1,1));
}
