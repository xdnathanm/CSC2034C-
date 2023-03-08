
#include <myStack.h>

using namespace std;



// the constructor
// create an instence of myStack




	myStack :: myStack()
	{
		vector <int> data = { 0 };
	}
	// the destructor
	myStack :: ~myStack()
	{
		 data.clear();
	}


	void myStack :: push(int number)
	{
		data.push_back(number);
	}
	int myStack:: pop()
	{
		int rValue = data.back();
		data.pop_back();
		return  rValue;
		
	}
	bool myStack :: isEmpty()
	{
		return data.empty();
	}
	void myStack:: print()
	{
		cout << " Info from vector: ";
		for (auto i = data.begin(); i != data.end(); i++)
		{
			cout << *i<< " ";
		}
	}
	int myStack::getSize()
	{
		return data.size();
	}

