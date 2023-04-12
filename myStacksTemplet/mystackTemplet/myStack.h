#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <vector>
using namespace std;

class myStack {
private:
	vector<int> data;

public:
	myStack();
	~myStack();
	void push(int);
	int pop();
	int getSize(); // added function to get the size of the vector.
	bool isEmpty();
	void print();
	friend std::ostream& operator << (std::ostream&, myStack&);

};
#endif
