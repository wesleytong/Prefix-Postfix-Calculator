#pragma once
#ifndef NODE_H

//Template class for Node 
template <class T>
class Node
{
public:
	//Data of type T so that it can be of any value
	T data;
	//Pointer for next value
	Node<T> *next;

	//Node constructor for user-inputted data 
	Node(T data) {
		this->data = data;
	}
};

#endif