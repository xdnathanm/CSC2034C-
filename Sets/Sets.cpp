#include <Sets.h>


set :: set()
{
	 vector < int> setList;
}

set::~set()
{
	setList.clear();
}

set& set::operator+=(int element)
{
	// TODO: insert return statement here
	setList.push_back(element);


}

set& set::operator-=( set& nSet)
{
	// TODO: insert return statement here
	nSet.setList.pop_back();
	return nSet;
}

void set::print(set nSet)
{
	cout << " elements from set: ";
	for (auto i = setList.begin(); i != setList.end(); i++)
	{
		cout << *i << " ";
	}
}

set operator*(const set& nSet1, const set& nSet2)
{
	
	set intersect;
	
	//iterators 
	int j = 0;

	for (auto i = nSet1.setList.begin(); i != nSet1.setList.end(); i++)
	{
		for (auto k = nSet2.setList.begin(); k != nSet2.setList.end(); k++)
		{
			if (nSet1.setList.at(*i) == nSet2.setList.at(*k))
			{
				
				intersect.setList.push_back(nSet2.setList.at(*k));
				
			}
			
		}
	}
	return intersect;
}

set operator+( set& nSet1, const set& nSet2 )
{
	
	
	
	return set();
}

set operator-(const set& nSet)
{
	return set();
}
