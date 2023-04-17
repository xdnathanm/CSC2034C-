#pragma once
#pragma once
#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class myStack
{

private:
	vector<T> data;

public:
	myStack();
	~myStack();
	void push(T);
	T pop();
	T getSize(); // added function to get the size of the vector.
	T isEmpty();
	void print();
	//friend std::ostream& operator << (std::ostream&, myStack&);


};

#endif
