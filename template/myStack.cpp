#ifndef MYSTACK_CPP
#define MYSTACK_CPP
#include "myStack.h"

using namespace std;



template <typename T>
myStack <T> ::myStack()
{
	vector <T> stack;
}
template <typename T>
myStack<T> :: ~myStack()
{
	data.clear();
}
template <typename T>
void myStack<T> ::push(T number)
{
	data.push_back(number);
}
template <typename T>
T myStack<T> ::pop()
{
	T rValue = data.back();
	data.pop_back();
	return  rValue;
}
// accessor funciton
template <typename T>
T myStack<T> ::getSize()
{
	return data.size();
}
template <typename T>
T myStack<T>::isEmpty()
{
	return data.empty();
}
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


