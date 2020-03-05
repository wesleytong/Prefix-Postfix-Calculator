#include "Calculator.h"
#include "Stack.h"
#include <string>
#include <iostream>
#include "Linkedlist.h"
#include "Node.h"
#include "Queue.h"
//Function to return precedence of operators
int Calculator::precedence(char c)
{
	int temp = 0;
	if (c == '*' || c == '/' || c == '%')
		temp = 1;
	else if (c == '+' || c == '-')
		temp = 2;

	return temp;
}


//Function for infix to postfix, takes string argument 
string Calculator::infixToPostfix(string input)
{
	int size = input.length();
	//stack for operators
	Stack<char> postfix;
	string output = "";

	for (int i = 0; i < size; i++)
	{
		//checks if the value inputted is an operator
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%')
		{
			//while NOT empty and the top value is not ( and the precedence of the top of stack is lower than or equal to the value in the input 
			while (!postfix.isEmpty() && postfix.topVal() != '(' && precedence(postfix.topVal()) <= precedence(input[i]))
			{
				//Add the top value to the output then pops
				output += (postfix.topVal());
				postfix.pop();
			}
			//pushes last operator to the stack 
			postfix.push(input[i]);
		}

		//pushes ( to stack
		else if (input[i] == '(')
		{
			postfix.push(input[i]);
		}

		//pushes ) to stack
		else if (input[i] == ')')
		{
			while (postfix.topVal() != '(')
			{
				output += (postfix.topVal());
				postfix.pop();
			}
			postfix.pop();
		}
		//if value is a number, add to output 
		else
		{
			output += (input[i]);
		}
	}

	//while stack is not empty, add top value of stack to output
	while (!postfix.isEmpty())
	{
		output += (postfix.topVal());
		postfix.pop();
	}
	return output;

}

//function for infix to prefix 
//SAME AS POSTFIX WITH FEW CHANGES (commented)
string Calculator::infixToPrefix(string input) {
	int size = input.length();
	//operator stack
	Stack<char> prefix;
	string output = "";

	std::reverse(input.begin(), input.end());

	for (int i = 0; i < size; i++)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%')
		{
			//prefix.topVal() != '(' chanegs to prefix.topVal() != ')'
			while (!prefix.isEmpty() && prefix.topVal() != ')' && precedence(prefix.topVal()) <= precedence(input[i]))
			{
				output += (prefix.topVal());
				prefix.pop();
			}
			prefix.push(input[i]);
		}
		//pushes ) to stack
		else if (input[i] == ')')
		{
			prefix.push(input[i]);
		}
		//pushes ( to stack
		else if (input[i] == '(')
		{
			while (prefix.topVal() != ')')
			{
				output += (prefix.topVal());
				prefix.pop();
			}
			prefix.pop();
		}
		//if number, adds to output
		else
		{
			output += (input[i]);
		}
	}

	while (!prefix.isEmpty())
	{
		output += (prefix.topVal());
		prefix.pop();
	}

	//reverses the output to account for prefix notation
	std::reverse(output.begin(), output.end());

	return output;
}
int Calculator::evaluatePostfix(string input)
{
	//instantiates e object for evaluation
	Stack<int> e;

	for (int i = 0; i < input.length(); i++)
	{
		//if input finds space, continue
		if (input[i] == ' ') continue;
		else if (charOperator(input[i])) //if char is an operator
		{
			int op2 = e.topVal(); //sets top to two operators, pops, and performs operations
			e.pop();
			int op1 = e.topVal();
			e.pop();
			int result;
			if (input[i] == '+') result = op1 + op2;
			else if (input[i] == '-') result = op1 - op2;
			else if (input[i] == '*') result = op1 * op2;
			else if (input[i] == '/') result = op1 / op2;
			else if (input[i] == '%') result = op1 % op2;
			e.push(result); //pushes result back to stack
		}
		else if (isNumericDigit(input[i]))
		{
			int operand = 0;
			while (i < input.length() && isNumericDigit(input[i]))
			{
				operand = (operand * 10) + (input[i] - '0');
				i++;
			}
			i--;
			e.push(operand);
		}
	}
	return e.topVal();
}
int Calculator::evaluatePrefix(string input)
{
	Stack<int> e;
	for (int i = input.length() - 1; i >= 0; i--)
	{
		if (input[i] == ' ') continue;

		else if (charOperator(input[i])) //sets top to two operators, pops, and performs operations
		{
			int op1 = e.topVal();
			e.pop();
			int op2 = e.topVal();
			e.pop();
			int result;
			if (input[i] == '+') result = op1 + op2;
			else if (input[i] == '-') result = op1 - op2;
			else if (input[i] == '*') result = op1 * op2;
			else if (input[i] == '/') result = op1 / op2;
			else if (input[i] == '%') result = op1 % op2;
			e.push(result);
		}
		else
		{
			//pushes the input and uses - '0' to convert to an int
			e.push(input[i] - '0');
		}
	}

	return e.topVal();
}
//function to check if operator
bool Calculator::charOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return true;
	else
		return false;
}
//function to check if number
bool Calculator::isNumericDigit(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}
