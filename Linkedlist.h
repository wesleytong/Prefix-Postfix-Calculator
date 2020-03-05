#pragma once
#ifndef _LINKEDLIST_H_
#include "Node.h"
template <class T>
class LinkedList {
public:
	//node pointer to top of list
	Node<T> *first;
	//node pointer to bottom of list
	Node<T> *last;
	//counter keeping track of number of elements in list
	int counter = 0;
	//LinkedList constructor
	LinkedList();
	//creates new list of NULL
	void newList();
	//returns true if the value inserted is in the list
	bool find(T);
	//removes the value from the list at the given index
	void subHere(int);
	//returns the number of elements in the list
	int count();
	//empties the list
	void empty();
	//adds a new value at the given index 
	void addHere(int, T);
};

//LinkedList default constructor
template<class T>
LinkedList<T>::LinkedList() {
	first = NULL;
	last = NULL;
}

//creates a new list
template<class T>
void LinkedList<T>::newList()
{
	T * newData = NULL;
}

//returns the number of elements in the list
template<class T>
int LinkedList<T>::count()
{
	return counter;
}

//adds the specified element at the specified index
template<class T>
void LinkedList<T>::addHere(int index, T data)
{
	//temporary node
	Node<T> *newNode = new Node<T>(data);
	//Adds a new value to the top of list if it is empty
	if (first == NULL) {
		first = newNode;
	}
	//if list is not empty, list will traverse up till index
	else {
		Node<T> *newTop = first;
		for (int i = 0; i < index; i++) {
			//traverses list and redefines newTop
			newTop = newTop->next;
		}
		Node<T> *oldNext = newTop->next;
		newNode->next = oldNext;
		//sets the respective value to the defined newNode value with data that needs
		//to be inserted
		newTop->next = newNode;
	}
	counter++;
}


//deletes the element at the respective index in the list
template<class T>
void LinkedList<T>::subHere(int index)
{
	if (counter == 0) {
		//if is it being deleted from the first index, assigns a temp first pointer the first pointer to one after 
		if (index == 0) {
			Node<T> *newFirst = first->next;
			//deletes first pointer
			delete first;
			//reassigns first to the next pointer value 
			first = newFirst;
		}
		else {
			//temportay new top node
			Node<T> *newTop = first;
			for (int i = 0; i < index - 1; i++) {
				//reassigns newTop to the next pointer
				newTop = newTop->next;
			}
			//temporary holder for value that needs to be deleted
			Node<T> *toBeDeleted = newTop->next;
			//assigns newTop to poiter value two spaces away, skipping one that needs to be deleted 
			newTop->next = newTop->next->next;
			//deletes the respective value
			delete toBeDeleted;

		}
	}
}

//returns true if the value being searched for exists in the list
template<class T>
bool LinkedList<T>::find(T value)
{
	Node<T> *newTop = first;
	//while the next value is not NULL, loop
	while (newTop->next != NULL) {
		//if the data of the node matches the user-inputted value, return true
		if (newTop->data == value) {
			return true;
		}
		//reassign newTop to the next node 
		newTop = newTop->next;
	}
	//if not found, return false
	return false;
}

//empties the list 
template<class T>
void LinkedList<T>::empty()
{
	//deletes nodes one by one while traversing through list 
	for (int i = 0; i < count(); i++) {
		subHere(i);
	}
}
#endif