#include <iostream>

using namespace std;


#include <memory.h>
#include "ReadString.h"

void SkipSpaces()
{
	char c;
	while (isspace(c = cin.get()));
	cin.putback(c); //Puts back on keyboard a character we don't want to read now.
					//only guaranteed to work once until you do another read.
}

char * ReadString()
{
	const int FirstGuess(50);
	char c;
	char * pLine;
	int NumCharsEntered;
	int SlotsInLine;
	char * pTempLine;

	NumCharsEntered = 0;
	pLine = new char[(SlotsInLine = FirstGuess) +1];
	SkipSpaces();
	while (!isspace(c = cin.get())) // isspace acts as a tab, or a space, or an enter key
	{
		pLine[NumCharsEntered++] = c; // Adds 1 to NumCharsEntered after putting c in that slot
		if (NumCharsEntered >= SlotsInLine)
		{
			pTempLine = new char[(SlotsInLine += FirstGuess) + 1];
			memcpy(pTempLine, pLine, NumCharsEntered); // Used to copy the contents of the second array into the first 
			// array, up to a max of the third argument.
			delete[] pLine; // no longer need the original array I had read into
			pLine = pTempLine; // Copies the address of pTempLine into pLine.
		}
	}
	pLine[NumCharsEntered] = '\0'; // when complete, put an end of string mark in the line.
	return pLine;
}