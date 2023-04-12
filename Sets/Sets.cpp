<<<<<<< HEAD
#include <Sets.h>
=======
#include <Sets.h>

// default constructor
set :: set()
{
	 vector < int> setList;
}
// deconstructor
set::~set()
{
	setList.clear();
}
// addes an element to a set
void set::operator+=(int element)
{
	
	setList.push_back(element);


}
// removes an element from a set
void set::operator-=( set& nSet)
{
	
	nSet.setList.pop_back();
	
}

void set::print()  // prints the sets
{
	cout << " elements from set: ";
	for (auto i = setList.begin(); i != setList.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

set operator*(const set& nSet1, const set& nSet2)  // intersection set command
{
	
	set intersect;  // creates the return value for intersect
	
	//iterators 
	int j = 0;
	int l = 0;
	
	
 	for (auto i = nSet1.setList.begin(); i != nSet1.setList.end(); i++)			// loop for first arguemnt
	{
		for (auto k = nSet2.setList.begin(); k != nSet2.setList.end(); k++)		// loop for second argument 
		{
			if (nSet1.setList.at(j) == nSet2.setList.at(l))                     // check if the values at the current locations are equal
			{
				
				intersect.setList.push_back(nSet2.setList.at(l));				// stores the value in the return set
				
			}
			j++;
		}
		j = 0;																	// resets iterator for inner loop
		l++;
	}
	return intersect;
}

set operator+( const set& nSet1, const set& nSet2 )   // union set command
{
	set unions; // creates the return set

	int j = 0;	// iterators
	int l = 0;

	int sI = 0;  // used to store the location in the second argument set. 
	bool same = false;
	for (auto i = nSet1.setList.begin(); i != nSet1.setList.end(); i++)	// first argument loop
	{
		for (auto k = nSet2.setList.begin(); k != nSet2.setList.end(); k++) // second argument loop
		{
			if (nSet1.setList.at(l) == nSet2.setList.at(j))   // check if the value in set one at a specified location is the same as a value in set2
			{
				same = true;								// sets bool check to true
				sI = j;										// saves location for the same value in set2
			}
			j++;
		}
		if (same)	// only stores the value from set2 at a SI location
		{
			
			unions.setList.push_back(nSet2.setList.at(sI));	
			same = false;
		}
		else // stores both the values from set1 and set2
		{
			unions.setList.push_back(nSet1.setList.at(l));
			unions.setList.push_back(nSet2.setList.at(l));

		};
		j = 0;
		l++;
		
	}
	
	
	return unions;
}

set operator-(const set& nSet1, const set& nSet2)  // differance set command
{
	set differance; // return set
	int j = 0; // ittirators
	int l = 0;
	
	bool same = false;  // bool used for check when the numbers are the same
	for (auto i = nSet1.setList.begin(); i != nSet1.setList.end(); i++) // loops through the first argument
	{
		for (auto k = nSet2.setList.begin(); k != nSet2.setList.end(); k++) // loops through the second arguemnt
		{
			if (nSet1.setList.at(l) == nSet2.setList.at(j)) // checks to see if the numbers are the same so they are excluded
			{
				same = true;
				
			}
			j++;
		}
		if (!same)
		{

			differance.setList.push_back(nSet1.setList.at(l)); // if the numbers are not the same they stored in the return set
			same = false;
		}
		same = false;	// resets same to be false for the next numbers
		j = 0;			// resets the iterator for the second argument
		l++;

	}

	return differance;
}
>>>>>>> 52990af7f3589bc5373b5eb9f41890f0e85c77bc
