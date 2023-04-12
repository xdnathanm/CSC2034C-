<<<<<<< HEAD
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
=======
#ifndef SETS_H
#define SETS_H
#include <iostream>
#include <vector>
using namespace std;

class set
{

	private:
		
		std:: vector<int> setList;
public:
	//constructors/destriuctors
	set();
	~set();
	
	//member functions
	void operator +=(int element);		 // the += overload operator void?
	void operator -=( set& nSet);		 // the -= overload operator
	void print();
	
	//friend functions
	friend set operator*(const set& nSet, const set& nSet2);	 // the * overload operator ( intersection between 2 sets)
	friend set operator +(const set& nSet, const set& nSet2); // the + overload operator ( union between 2 sets)
	friend set operator -(const set& nSet, const set& nSet2); // the - overload operator ( differance between 2 sets)
	
};
>>>>>>> 52990af7f3589bc5373b5eb9f41890f0e85c77bc
#endif