//***************************************************
//******* template Class test file ******************
//***************************************************
#include "myStack.cpp"
#include <fstream>
 

int main()
{
	// creation of various myStack classes with different types.
	myStack <int> stackI;
	myStack <char> stackC;
	myStack <float> stackF;

	// storing ints into the stackI class
	stackI.push(10);
	stackI.push(20);
	stackI.push(30);
	stackI.push(40);
	stackI.print();
	// storing characters into the stackC class
	stackC.push('k');
	stackC.push('c');
	stackC.push('a');
	stackC.push('t');
	stackC.push('s');
	stackC.print();
	// storing floats into the stackF class
	stackF.push(10.01f);
	stackF.push(20.02f);
	stackF.push(30.03f);
	stackF.push(40.04f);
	stackF.print();

	// opens the file where the data will be stored
	ofstream myFile;
	myFile.open("myStacks.txt");
	// checks to make sure the file is open then writes the data stored in the stackI class to the file.
	if (myFile.is_open())
	{
		while (!stackI.isEmpty())
		{
			myFile << stackI.pop() << " ";

		}
		myFile << "\n";
	}
	else
	{
		cout << endl << " File Not Open! ";
	}
	// checks to make sure the file is open then writes the data stored in the stackC class to the file.
	if (myFile.is_open())
	{
		while (!stackC.isEmpty())
		{
			myFile << stackC.pop() << " ";

		}
		myFile << "\n";

	}
	else
	{
		cout << endl << " File Not Open! ";
	}
	// checks to make sure the file is open then writes the data stored in the stackF class to the file.
	if (myFile.is_open())
	{
		while (!stackF.isEmpty())
		{
			myFile << stackF.pop() << " ";

		}
		//myFile << "\n";
		cout << endl << "Data stored in myStacks.txt file. ";
	}
	else
	{
		cout << endl << " File Not Open! ";
	}
	// closes the file
	myFile.close();
	std::cout << endl;
	return 0;
	// end of program. 
}