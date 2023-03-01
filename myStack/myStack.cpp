#include <iostream>
#include <myStack.h>
using namespace std;



// the constructor
// create an instence of myStack
class myStack {

private:
	vector < int> data;
public:
	myStack()
	{
		vector <int> data = { 0 };
	}
	// the destructor
	 ~myStack()
	{
		 data.clear();
	}


	void push(int number)
	{
		data.push_back(number);
	}
	int pop()
	{
		data.pop_back();
	}
	bool isEmpty()
	{
		return data.empty();
	}
	void print()
	{
		cout << " Info from vector: ";
		for (auto i = data.begin(); i != data.end(); i++)
		{
			cout << *i<< " ";
		}
	}
};
