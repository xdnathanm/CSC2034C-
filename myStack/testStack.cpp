#include <fstream>
#include <myStack.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>
#define _CRT_SECURE_NO_DEPRECIATE


// the function to read in the text file
string readFile();
void parse(char*);

int main()
{
	string fString;
	string* pString;
	
	size_t size {};
	int stringS = 0;
	char* pLine;
	char hold [] = " ";
	
	fString = readFile();
	
	string& arithmatic = fString;
	//pString = fString;
	//newStack.push(stoi(arithmatic, &size));
	stringS = fString.capacity();
	
	cout << arithmatic;
	char cArray[157];
	strcpy(cArray, arithmatic.c_str());
	parse(cArray);


	cout << endl;
	return 0;
}
void parse(char* cArray)
{
	myStack nStack;
	string getValues = cArray;
	char* pLine  [158] {};
	char* hold;
	const char* delim = " ";
	hold = strtok(cArray, delim);
	int i=0;
	int number;
	while (hold)
	{
		pLine[i] = hold;
		// try using pLine insted of hold in the if statment
		if (hold != "+" /* && hold != "-" && hold != "*" && hold != "/"*/)
		{
			nStack.push(stoi(hold));
		}
		hold = strtok(nullptr, delim);
		i++;
	}

	i = 0;
	
	//number = stoi(pLine[i]);
	//nStack.push(stoi(pLine[i]));
	
	
}
string readFile()
{
	string fString; // file string
	string fTotal = fString;// file total
	ifstream inFile;
	
	inFile.open("rpnArithmetic.txt");
	while (inFile.good())
	{
		while (!inFile.eof())
		{
			if (inFile.is_open())
			{
				// getline is passed the file and a string coppies the line in the textfile to the string until a "\n" is found then returns, the string is then added to 
				// fTotal to store the string since it will be over written as the loop continues.
				getline(inFile, fString);
				fTotal += fString + "\n";

			}
			else
			{
				cout << "Error: file is not open";
			}
		}
	}
	/*cout << endl;
	cout << "******************************************************";
	cout << "\n";
	cout << fString;
	cout << " \n" << " * ********************" << "\n";
	cout << fTotal; */
	
	inFile.close();
	return fTotal;


}
