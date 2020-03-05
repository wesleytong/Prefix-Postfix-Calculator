#pragma once
#include "linkedlist.h"
#ifndef _QUEUE_H
template <class T>

//LinkedList is private to prevent from Queue objects using LinkedList methods 
class Queue : private LinkedList<T>
{
public:
	int counter = 0;
	Queue();
	void enqueue(T data);
	void dequeue();
	T front();
	T rear();
	void show();
	bool isEmpty(); //check if ptr = null; in beginning of each method must check for Queue\ overflow/underflow 
	void queueEmpty();
};

template<class T>
void Queue<T>::queueEmpty()
{
	/*for (int i = 0; i < count(); i++) {
	subHere(i);
	}*/
	empty();
	//uses the empty function from LinkedList
}
template<class T>
Queue<T>::Queue() {
	//no need 
}

//implements LinkedList method of addHere(int, T) to enqueue data to front of Queue 
template<class T>
void Queue<T>::enqueue(T data)
{
	/*
	Node<T> *nodePtr = new Node<T>(data);
	if (counter == 0) {
	nodePtr->next = NULL;
	front = nodePtr;
	cout << "Item has been enqueueed" << endl;
	}
	else {
	Node<T> *temp = front;
	front = nodePtr;
	nodePtr->next = temp;
	cout << "Else Loop Reached" << endl;
	}
	counter++;
	*/

	addHere((count() - 1), data);
}

//returns the value at the front of the Queue
template<class T>
T Queue<T>::front() {
	return peek(0);
}
template <class T>
T Queue<T>::rear() {
	return peek(count());
}
//dequeues the front value at the Queue 
//uses LinkedList method of subHere(int)
template<class T>
void Queue<T>::dequeue()
{
	cout << "dequeued" << endl;
	subHere(count() - 1);

	/*if (front == NULL)
	cout << "Nothing to dequeue\n";
	else
	{
	Node<T> * old = front;
	front = front->next;
	counter--;
	delete(old);
	}*/
	//delete front;
	//cout << "dequeueped" << endl;

	/*
	T  *temp;
	if (isEmpty() == true) {
	cout << "No data in Queue" << endl;
	}
	temp = front;
	*(front++);
	delete temp;*/
	//counter--;
}

//prints the values in the Queue 
template<class T>
void Queue<T>::show()
{
	Node<T> *temp;
	temp = first;
	//checks if Queue is empty before attemping to print 
	while (temp != NULL)
	{
		cout << temp->data << "," << endl;
		temp = temp->next;
	}
}

//checks if the Queue is empty 
template<class T>
bool Queue<T>::isEmpty()
{
	if (front == NULL)
		return true;
	else
		return false;
}
#endif