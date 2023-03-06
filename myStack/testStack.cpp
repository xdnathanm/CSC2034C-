#include <fstream>
#include<myStack.h>
#include <string.h>
#include < stdio.h>
#define _CRT_SECURE_NO_DEPRECIATE


// the function to read in the text file
char& readFile();
void parse(char*);

int main()
{
	string arithmatic = " ";
	myStack newStack;
	char* pLine;
	char hold;
	char getValue[] = " ";
	char& fileLine = readFile();
	hold = fileLine;
	
	int size = arithmatic.size();
	cout << arithmatic;
	char* cArray = getValue;
	strcpy(cArray, arithmatic.c_str());
	parse(cArray );
	return 0;
}
void parse(char* getValues )
{
	string hold = strtok(getValues, " ");
	
	
	myStack newstack;
	
}
char& readFile()

{
	string getsize;
	char null ='null';
	char& line = null;
	int count = 0;
	char* pLine;
	
	//line = getValue;
	ifstream inFile;
	inFile.open("rpnArithmetic.txt");
	while (inFile.good())
	{
		inFile >> getsize;
	}
	count = getsize.size();
	char getValue[] = " ";
	while (inFile.good())
	{
		if (inFile.is_open())
		{
			inFile.get(line);
			cout << line;
		}
		else
		{
			cout << "Error: file is not open";
		}
	}
	//std:: getline(inFile, arithmatic," ");
	inFile.close();
	return line;


}