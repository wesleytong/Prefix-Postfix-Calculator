//Deepkiran Sangha and Wesley Tong
//Goel 22C
#include "Calculator.h"
#include "Stack.h"
#include "Queue.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string exp = "";
	cout << "Enter an expression to evaluate" << endl;
	getline(cin, exp);
	//checks for input validity, if invalid input ends program
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '%' && exp[i] <= '0' && exp[i] >= '999')
		{
			cout << "Invalid Input" << endl;
			exp.clear();
			system("pause");
			return 0;
		}
		//if letters inputted, ends program
		else if (isalpha(exp[i]))
		{
			cout << "Invalid Input: Alphabetic Values NOT Accepted " << endl;
			exp.clear();
			system("pause");
			return 0;
		}
	}
	string prefix = "";
	string postfix = "";

	//Calculator object 
	Calculator calc;

	//infix to postfix value
	postfix = calc.infixToPostfix(exp);
	cout << "The postfix evaluation is: ";
	cout << postfix << endl;
	cout << "This expression evaluates to: ";

	//evaluates postfix
	cout << calc.evaluatePostfix(postfix) << endl;
	cout << "The prefix evaluation is: ";

	//infix to prefix value
	prefix = calc.infixToPrefix(exp);
	cout << prefix << endl;
	cout << "This expression evaluates to: ";

	//evaluates prefix
	cout << calc.evaluatePrefix(prefix) << endl;

	system("pause");
	return 0;
}
