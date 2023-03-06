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
	myStack newStack;
	char* pLine;
	char hold;
	
	fString = readFile();
	string& arithmatic = fString;
	
	int size = arithmatic.size();
	cout << arithmatic;
//	char* cArray = getValue;
	//strcpy(cArray, arithmatic.c_str());
	//..parse(cArray );
	return 0;
}
void parse(char* getValues )
{
	string hold = strtok(getValues, " ");
	
	
	myStack newstack;
	
}
string readFile()
{
	string fString = "/0 "; // file string
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