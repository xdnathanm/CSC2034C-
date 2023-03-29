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
	set& operator +=(int element);		 // the += overload operator
	set& operator -=( set& nSet);		 // the -= overload operator
	void print(set nSet);
	
	//friend functions
	friend set operator*(const set& nSet, const set& nSet2);	 // the * overload operator
	friend set operator +(set& nSet, const set& nSet2); // the + overload operator
	friend set operator -(const set& nSet); // the - overload operator
	
};
#endif