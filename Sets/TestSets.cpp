#include <Sets.h>
#define _CRT_SECURE_NO_DEPRECIATE
#include <iostream>

int main()
{
	std:: cout << std::endl;
	set set1 , set2, set3;  // creates an instance of the 3 sets that will be used
	int choice = 0;         // used for a better UI
	char input;				// used for a better UI

	set1 += 1;				// filling the sets with random numbers with atlest 2 the same
	set1 += 5;
	set1 += 4;
	set1 += 7;
	set1 += 8;
	set1 += 10;

	set2 += 6;
	set2 += 3;
	set2 += 4;
	set2 += 7;
	set2 += 9;
	set2 += 6;
						// removes the last two numbers
	set1 -= set1;
	set2 -= set2;

	set1.print();
	set2.print();

	std:: cout << std ::endl << "would you like to run a set Command? (y/n)" << std ::endl;
	std::cin >> input; 
	while (input != 'n')		// used to loop through so the set commands can be used more than once without having to relaunch the cod
	{
		std:: cout << std ::endl << std :: endl << " 1) intersection, 2) union, 3) difference " << std ::endl;

		std ::cin >> choice;
		switch (choice)
		{
		case 1:                 //intersection
			set3 = set1 * set2;
			set3.print();
			break;
		case 2:                 // union
			set3 = set1 + set2;
			set3.print();
			break;
		case 3:                //  difference
			set3 = set1 - set2;
			set3.print();
			set3 = set2 - set1;
			set3.print();
			break;
		default:
			break;
		}
		std ::cout << endl << " Would you like to run another command" << endl;
		std ::cin >> input;
		input = tolower(input);
	}


	set1.~set();
	set2.~set();
	set3.~set();
	cout << endl;
	return 0;
}