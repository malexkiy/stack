#include "stack.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void stack_push(stack<int>* _stack, string arg);

void stack_pop(stack<int>* _stack);

void stack_last(stack<int>* _stack);

void stack_print(stack<int>* _stack);


int main()
{
	stack<int> st;

	for (string str; getline(cin, str);)
	{
		switch (str[0])
		{
		case '+':
			stack_push(&st, str.replace(str.begin(), str.begin() + 1, ""));
			break;
		case '?':
			stack_last(&st);
			break;
		case '-':
			stack_pop(&st);
			break;
		case '=':
			stack_print(&st);
			break;
		}
	}


	return 0;
}


void stack_push(stack<int>* _stack, string arg)
{
	if (arg.length() == 0 || arg.length() == 1)
		cout << "An error has occurred while reading arguments" << endl;
	else
	{
		int num;
		stringstream ss;
		ss << arg;
		ss >> num;
		_stack->push(num);
	}
}


void stack_pop(stack<int>* _stack)
{
	try {
		_stack->pop();
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
}


void stack_last(stack<int>* _stack)
{
	if (_stack->count_)
		cout << _stack->array_[_stack->count_ - 1] << endl;
	else
		cout << "Stack is empty" << endl;
}


void stack_print(stack<int>* _stack)
{
	if (_stack->count_ == 0)
		cout << "Stack is empty" << endl;
	else
	{
		for (int i = 0; i < _stack->count_; i++)
		{
			cout << _stack->array_[i] << " ";
		}
		cout << endl;
	}
}
