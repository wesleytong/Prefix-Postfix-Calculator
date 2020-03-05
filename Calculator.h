//Deepkiran Sangha and Wesley Tong
//Goel 22C
#pragma once
#include <string>
#include <iostream>
//#include <stack>
#include "Stack.h"
#include "Queue.h"
#include "Node.h"
#include "LinkedList.h"
using namespace std;

class Calculator
{
public:

	int precedence(char);
	string infixToPostfix(string);
	string infixToPrefix(string);
	int evaluatePostfix(string);
	int evaluatePrefix(string);
	bool charOperator(char);
	bool isNumericDigit(char);
};
