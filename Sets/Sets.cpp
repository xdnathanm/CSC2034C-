#include <Sets.h>


set :: set()
{
	 vector < int> setList;
}

set::~set()
{
	setList.clear();
}

void set::operator+=(int element)
{
	// TODO: insert return statement here
	setList.push_back(element);


}

void set::operator-=( set& nSet)
{
	// TODO: insert return statement here
	nSet.setList.pop_back();
	
}

void set::print()
{
	cout << " elements from set: ";
	for (auto i = setList.begin(); i != setList.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

set operator*(const set& nSet1, const set& nSet2)
{
	
	set intersect;
	
	//iterators 
	int j = 0;
	int l = 0;
	auto i = nSet1.setList.begin();
	
 	for (i; i != nSet1.setList.end(); i++)
	{
		for (auto k = nSet2.setList.begin(); k != nSet2.setList.end(); k++)
		{
			if (nSet1.setList.at(j) == nSet2.setList.at(l))                        // vector out of range error.
			{
				
				intersect.setList.push_back(nSet2.setList.at(l));
				
			}
			j++;
		}
		j = 0;
		l++;
	}
	return intersect;
}

set operator+( const set& nSet1, const set& nSet2 )
{
	set unions;
	int j = 0;
	int l = 0;
	int sI = 0;
	bool same = false;
	for (auto i = nSet1.setList.begin(); i != nSet1.setList.end(); i++)
	{
		for (auto k = nSet2.setList.begin(); k != nSet2.setList.end(); k++)
		{
			if (nSet1.setList.at(l) == nSet2.setList.at(j))
			{
				same = true;
				sI = j;
			}
			j++;
		}
		if (same)
		{
			
			unions.setList.push_back(nSet2.setList.at(sI));
			same = false;
		}
		else
		{
			unions.setList.push_back(nSet1.setList.at(l));
			unions.setList.push_back(nSet2.setList.at(l));

		};
		j = 0;
		l++;
		
	}
	
	
	return unions;
}

set operator-(const set& nSet1, const set& nSet2)
{
	set differance;
	int j = 0;
	int l = 0;
	int sI = 0;
	bool same = false;
	for (auto i = nSet1.setList.begin(); i != nSet1.setList.end(); i++)
	{
		for (auto k = nSet2.setList.begin(); k != nSet2.setList.end(); k++)
		{
			if (nSet1.setList.at(l) == nSet2.setList.at(j))
			{
				same = true;
				sI = j;
			}
			j++;
		}
		if (!same)
		{

			differance.setList.push_back(nSet1.setList.at(l));
			same = false;
		}
		same = false;
		j = 0;
		l++;

	}

	return differance;
}
