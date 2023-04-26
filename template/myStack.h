#pragma once
#pragma once
#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <vector>

using namespace std;

// template class header file
// the class was made to convert the class myStack to be a generic class to accept various data types.
template <typename T>
class myStack
{

private:
	vector<T> data; // vector used to dynamically store and remove the data

public:
	myStack(); // constructor
	~myStack(); // destructor
	void push(T); // mutator
	T pop(); // accessor/ mutator
	T getSize(); // added function to get the size of the vector.
	T isEmpty(); // checks if the vector is empty 
	void print(); // prints the stack to the console 
	//friend std::ostream& operator << (std::ostream&, myStack&);


};

#endif
