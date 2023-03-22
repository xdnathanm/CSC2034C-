#ifndef SETS_H
#define SETS_H
#include <vector>


class Set
{

	private:
		int size;
		std::vector<int> set;
public:
	Set();
	~Set();
	Set& operator +=(Set nSet);		 // the += overload operator
	Set& operator -=(Set nSet);		 // the -= overload operator
	friend Set operator*(Set nSet);	 // the * overload operator
	friend Set operator +(Set nSet); // the + overload operator
	friend Set operator -(Set nSet); // the - overload operator
	void print(Set nSet);
};
#endif