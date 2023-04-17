#include <fstream>
#include <myStack.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#define _CRT_SECURE_NO_DEPRECIATE


// the function to read in the text file
//	returns a string copy of the text file. 
string readFile();
// The function parse takes in a pointer to a char array 
//	which holds the line from the text file to be parsed  it will also preform the RPN calculation. 
//	returns void.
void parse(char*);

int main()
{

	size_t size{};					// used to find the length of the line to be parsed
	string fString = readFile();	// File string that holds the string obtained from the txt file.
	string& arithmatic = fString;	// stores the string into a refferance so that it can be manupulated seperataly but not lost

	char cArray[157];				// creates a character array to store the file string on so that it can be parsed.
	// loops while the string is not empty
	while (!arithmatic.empty())
	{
		strcpy(cArray, arithmatic.c_str());   // coppies the string to the char array so strtok can be used.

		strtok(cArray, "\n");					// tokenizes the char array so that it can become the first line of the string. Although the command has a return value it is not needed here.
		cout << "Expression " << cArray << " evaluates to: ";   // prints the desired format.
		size = arithmatic.find_first_of("\n");					// gets the size of the line so it can be erased from the string.
		arithmatic.erase(0, size + 1);							// erases the line ( the size + 1 is so the \n character is erased aswell.

		parse(cArray);											// calls the parse function, the char array is passed in. 
	}

	cout << endl;
	return 0;
}

// the function parse
// is passed the pointer to a character array that holds the line from the main string that will be parsed and evaluated.
void parse(char* cArray)
{
	myStack nStack;						// creates an instance of the myStack class.
	string getValues;
	string parse = cArray;
	char* pLine[35]{};
	char* hold = NULL;
	const char* delim = " ";
	char iHold;
	hold = strtok(cArray, delim);
	int i = 0; // itirator
	int num1 = 0, num2 = 0; // values for the evaluation of the RPN

	while (parse != "\n")
	{
		if (hold != 0)		// check to make sure that hold is not 0 breaking the xstring class in visual studio.( kept underlining in green and making me mad >:{)
		{
			getValues = hold;		// stores the char pointer hold into a string 
		}
		pLine[i] = hold;		// stores the char pointer hold into a local char pointer array
		iHold = getValues[0];	// stores the first value into iHold to check if it is an it only need the first value since the chars that will be invalid will only take up 1 value.

		//getValues = iHold;
		if (isdigit(iHold) && hold != 0)      // checks if the charachter in iHold is a digit or not.
		{
			nStack.push(stoi(pLine[i]));  // if it is a digit converts it using StoI and pushes it to the myStack vector
		}
		else {
			if (getValues == "+")            // the big if statement that is used to evaluate the expressions starting with the '+' opperator
			{
				if (nStack.getSize() == 2)   // checks if there are 2 numbers pushed to the stack so that it knows how many numbers to pop
				{
					num2 = nStack.pop();
					num1 = nStack.pop();
					num1 += num2;

				}
				else
				{
					num2 = nStack.pop();
					num1 += num2;


				}
			}
			else if (getValues == "-")
			{
				if (nStack.getSize() == 2)
				{
					num2 = nStack.pop();
					num1 = nStack.pop();
					num1 -= num2;
				}
				else
				{
					num2 = nStack.pop();
					num1 -= num2;

				}
			}
			else if (getValues == "/")
			{
				if (nStack.getSize() == 2)
				{
					num2 = nStack.pop();
					num1 = nStack.pop();
					num1 /= num2;
				}
				else
				{
					num2 = nStack.pop();
					num1 /= num2;

				}
			}
			else if (getValues == "*")
			{
				if (nStack.getSize() == 2)
				{
					num1 = nStack.pop();
					num2 = nStack.pop();
					num1 *= num2;
				}
				else
				{
					num2 = nStack.pop();
					num1 *= num2;

				}
			}
		}
		hold = strtok(nullptr, delim);  // gets the next character to be evaluated
		i++;							//	itirates the array
		if (hold == NULL)				// the end of line end condition.
		{
			parse = "\n";
			cout << num1 << " \n";
		}
	}
}
string readFile()
{
	string fString; // file string that will store the string line from the text file.
	string fTotal = fString;// file total will combine the strings and be returned so the whole file is copied
	ifstream inFile;


	inFile.open("rpnArithmetic.txt"); // opens the txt file.

	// checks if the file is good.
	if (inFile.good())
	{
		// loops while the file is not at the end.
		while (!inFile.eof())
		{
			// double check to see if the fie is open.
			if (inFile.is_open())
			{
				// getline is passed the file and a string coppies the line in the textfile to the string until a "\n" is found then returns, the string is then added to 
				// fTotal to store the string since it will be over written as the loop continues.
				getline(inFile, fString); // gets the ling from the file and stores it in a string.
				fTotal += fString + "\n";   // adds the 2 strings and a new line to make it look the same as the txt file.

			}
			else
			{
				cout << "Error: file is not open";
			}
		}
	}
	inFile.close(); // closes the file.
	return fTotal; // returns the string from the file.
}
