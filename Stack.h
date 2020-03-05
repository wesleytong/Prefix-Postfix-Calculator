#pragma once
#include "LinkedList.h"
#ifndef _STACK_H
template <class T>

//LinkedList is private to prevent from Stack objects using LinkedList methods 
class Stack : private LinkedList<T>
{
private:
	Node<T> *top;
public:
	int counter = 0;
	Stack();
	void push(T data);
	void pop();
	T topVal();
	void show();
	bool isEmpty(); //check if ptr = null; in beginning of each method must check for stack overflow/underflow 
};


template<class T>
Stack<T>::Stack() {
	//no need 
}

//implements LinkedList method of addHere(int, T) to push data to top of stack 
template<class T>
void Stack<T>::push(T inVal)
{
	/*
	Node<T> *nodePtr = new Node<T>(data);
	if (counter == 0) {
	nodePtr->next = NULL;
	top = nodePtr;
	cout << "Item has been pushed" << endl;
	}
	else {
	Node<T> *temp = top;
	top = nodePtr;
	nodePtr->next = temp;
	cout << "Else Loop Reached" << endl;
	}
	counter++;
	*/
	Node<T> *tempNode = new Node<T>(inVal);
	tempNode->data = inVal;
	tempNode->next = top;
	top = tempNode;
	counter++;

	//addHere(0, data);
}

//returns the value at the top of the stack
template<class T>
T Stack<T>::topVal() {
	T nothing = NULL;
	if (top == NULL)
		return nothing;
	else
		return top->data;
}

//pops the top value at the stack 
//uses LinkedList method of subHere(int)
template<class T>
void Stack<T>::pop()
{
	Node <T> *temp;
	if (counter == 0) {
		cout << "No values to pop" << endl;
	}
	temp = top->next;
	delete top;
	top = temp;
	//cout << "Popped" << endl;
	counter--;

	//cout << "Popped" << endl;
	//subHere(0);

	/*if (top == NULL)
	cout << "Nothing to pop\n";
	else
	{
	Node<T> * old = top;
	top = top->next;
	counter--;
	delete(old);
	}*/
	//delete top;
	//cout << "Popped" << endl;

	/*
	T  *temp;
	if (isEmpty() == true) {
	cout << "No data in stack" << endl;
	}
	temp = top;
	*(top++);
	delete temp;*/
	//counter--;
}

//prints the values in the stack 
template<class T>
void Stack<T>::show()
{
	Node<T> *temp;
	temp = top;
	//checks if stack is empty before attemping to print 
	while (temp != NULL)
	{
		cout << temp->data << "," << endl;
		temp = temp->next;
	}
}

//checks if the stack is empty 
template<class T>
bool Stack<T>::isEmpty()
{
	if (top == NULL)
		return true;
	else
		return false;
}
#endif