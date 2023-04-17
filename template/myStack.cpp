#ifndef MYSTACK_CPP
#define MYSTACK_CPP
#include "myStack.h"
// template class for myStack
// changes the type value for the class to be generic so that various data types can be used with the 
// myStack class.
using namespace std;


// constructor
template <typename T>
myStack <T> ::myStack()
{
	vector <T> stack;
}
// destructor
template <typename T>
myStack<T> :: ~myStack()
{
	data.clear();
}
// mutator, addes a value to the stack vector.
template <typename T>
void myStack<T> ::push(T number)
{
	data.push_back(number);
}
// accesor/ mutator, returns and removes a value from the class stack.
template <typename T>
T myStack<T> ::pop()
{
	T rValue = data.back();
	data.pop_back();
	return  rValue;
}
// returns the size of the stack, not needed for this assignment, but is legacy code lol. 
template <typename T>
T myStack<T> ::getSize()
{
	return data.size();
}
// checks if the stack is empty
template <typename T>
T myStack<T>::isEmpty()
{
	return data.empty();
}
// prints the contents of the stack to the console. 
template <typename T>
void myStack<T> ::print()
{
	cout << " Info from vector: ";
	for (auto i = data.begin(); i != data.end(); i++)
	{
		cout << *i << " ";
	}
}
#endif


