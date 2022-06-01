/*
*********************************************************************************
*	Description: Create a program to run an airline ticket counter.				*
*	Class: COSC 1436.S01														*
*	Author: Merddyn Sheeley														*
*	Date:  December 6, 2017														*
*********************************************************************************
*/



#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>

using namespace std;

#include "Plane.h"
#include "Commands.h"
#include "ReadFunctions.h"
#include "ReadString.h"

void main()
{
	Party ArrivingParty;
	PlaneInfo Alfa;
	PlaneInfo Bravo;
	PlaneInfo Lounge;
	bool AlfaInitialized = false;
	bool BravoInitialized = false;
	bool LoungeInitialized = false;
	bool StillRunning = true;

	// initialize the planes and the lounge
	do
	{ 
	cout << "> ";
	// get a command
	// depending on which command, we may read in different information
	switch (GetCmd())
	{
		//Remember that Alfa, Bravo, and Lounge commands must be done before any other commands, and
		//they cannot be done more than once in the program.
	case CmdAlfa:
	{
		if (AlfaInitialized)
		{
			cout << "Error: Alfa has already been declared." << endl;
				cin.clear(); // clear up any error conditions
				cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
			break;
		}
		// get the size (number of seats on plane)
		Alfa.NumSeats = ReadInteger(); //could check here to make sure they don't enter 0 for number of seats
		if (Alfa.NumSeats <= 0)
		{
			cout << "Error: Size of plane cannot be less than 1." << endl;
			break;
		}
		cout << "Plane Alfa has " << Alfa.NumSeats << " seats." << endl;
		Alfa.NumEmptySeats = Alfa.NumSeats;
		Alfa.NumParties = 0;
		Alfa.Parties = new Party[Alfa.NumSeats];
		AlfaInitialized = true;
		break;
	}
	case CmdBravo:
	{
		if (BravoInitialized)
		{
			cout << "Error: Bravo has already been declared." << endl;
				cin.clear(); // clear up any error conditions
				cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
			break;
		}
		Bravo.NumSeats = ReadInteger(); //could check here to make sure they don't enter 0 for number of seats
		if (Bravo.NumSeats <= 0)
		{
			cout << "Error: Size of plane cannot be less than 1." << endl;
			break;
		}
		cout << "Plane Bravo has " << Bravo.NumSeats << " seats." << endl;
		Bravo.NumEmptySeats = Bravo.NumSeats;
		Bravo.NumParties = 0;
		Bravo.Parties = new Party[Bravo.NumSeats];
		BravoInitialized = true;
		break;
	}
	case CmdLounge:
	{
		if (LoungeInitialized)
		{
			cout << "Error: Lounge has already been declared." << endl;
				cin.clear(); // clear up any error conditions
				cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
			break;
		}
		Lounge.NumSeats = ReadInteger(); //could check here to make sure they don't enter 0 for number of seats
		if (Lounge.NumSeats <= 0)
		{
			cout << "Error: Size of Lounge cannot be less than 1." << endl;
			break;
		}
		cout << "The lounge has " << Lounge.NumSeats << " seats." << endl;
		Lounge.NumEmptySeats = Lounge.NumSeats;
		Lounge.NumParties = 0;
		Lounge.Parties = new Party[Lounge.NumSeats];
		LoungeInitialized = true;
		break;
	}
	case CmdFly:
	{
		if (!AlfaInitialized)
		{
			cout << "Error: Alfa must be initialized first." << endl;
				cin.clear(); // clear up any error conditions
				cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
			break;
		}
		if (!BravoInitialized)
		{
			cout << "Error: Bravo must be initialized first." << endl;
				cin.clear(); // clear up any error conditions
				cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
			break;
		}
		if (!LoungeInitialized)
		{
			cout << "Error: The lounge must be initialized first." << endl;
				cin.clear(); // clear up any error conditions
				cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
			break;
		}

		switch (Plane WhichPlane = GetPlane())
		{
		case PlaneAlfa:
		case PlaneBravo:
			cout << WhichPlane << endl;
			if (!AlfaInitialized)
			{
				cout << "Error: Alfa must be initialized first." << endl;
					cin.clear(); // clear up any error conditions
					cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
				break;
			}
			if (!BravoInitialized)
			{
				cout << "Error: Bravo must be initialized first." << endl;
					cin.clear(); // clear up any error conditions
					cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
				break;
			}
			if (!LoungeInitialized)
			{
				cout << "Error: The lounge must be initialized first." << endl;
					cin.clear(); // clear up any error conditions
					cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
				break;
			}
			// TODO Call FlyPlane(...);
			if (WhichPlane == PlaneAlfa)
			{
				FlyPlane(WhichPlane, Alfa, Lounge);
			}
			else if (WhichPlane == PlaneBravo)
			{
				FlyPlane(WhichPlane, Bravo, Lounge);
			}
			break;
		case InvalidPlane:
			cout << "Error: Invalid Plane entered." << endl;
				cin.clear(); // clear up any error conditions
				cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
			//information is not correct
			break;
		default:
			cout << "Internal error 203, please contact customer support" << endl;
			system("pause");
			exit(0);
		}
		break;
	}
	case CmdArrive:
	{
		if (!AlfaInitialized)
		{
			cout << "Error: Alfa must be initialized first." << endl;
				cin.clear(); // clear up any error conditions
				cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
			break;
		}
		if (!BravoInitialized)
		{
			cout << "Error: Bravo must be initialized first." << endl;
				cin.clear(); // clear up any error conditions
				cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
			break;
		}
		if (!LoungeInitialized)
		{
			cout << "Error: The lounge must be initialized first." << endl;
				cin.clear(); // clear up any error conditions
				cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
			break;
		}


		ArrivingParty.WhichPlane = GetPlane(); //Get which plane we want on.
		ArrivingParty.Name = ReadString(); //Get party name
		ArrivingParty.Size = ReadInteger(); // get size of party
		
		cout << "You entered Plane " << ArrivingParty.WhichPlane << " Name " << ArrivingParty.Name << " Size " << ArrivingParty.Size << endl;
		switch (ArrivingParty.WhichPlane)
		{
		case PlaneAlfa: // TODO Write code for arriving party.
		
			if (ArrivingParty.Size > Alfa.NumSeats) // can the party ever fit on the plane
			{
				//		no, turn party away
				cout << "Unfortunately, the party can never fit on Plane Alfa. Please inform the customer of this." << endl;
				break;
			}
				// else, they could possibly fit

			if (ArrivingParty.Size > Alfa.NumEmptySeats)	// are there enough empty seats now?
			{
				if (ArrivingParty.Size > Lounge.NumEmptySeats) // party does not fit now. can they fit in the lounge?
				{
					// no, turn party away.
					cout << "Unfortunately, there is not enough room on plane Alfa, nor in the lounge." << endl;
					cout << "Please direct " << ArrivingParty.Name << " to try again on a different day." << endl;
					break;
				}
				// yes, put them into the lounge
				// TODO Move party into lounge.
				cout << "Please direct " << ArrivingParty.Name << " to the lounge. They will fly at the next opportunity." << endl;
				Lounge.Parties[Lounge.NumParties] = ArrivingParty;
				Lounge.NumParties++;
				Lounge.NumEmptySeats = (Lounge.NumEmptySeats - ArrivingParty.Size);
				cout << "There are " << Lounge.NumEmptySeats << " seats left in the lounge." << endl;
				break;
			}

			// yes, put party on plane
			cout << "Please direct the party onto plane Alfa." << endl;
			// TODO Put party on plane.
			Alfa.Parties[Alfa.NumParties] = ArrivingParty;
			Alfa.NumParties++;
			Alfa.NumEmptySeats = (Alfa.NumEmptySeats - ArrivingParty.Size);
			cout << "There are " << Alfa.NumEmptySeats << " seats left on Alfa." << endl;
			
			if (Alfa.NumEmptySeats == 0) // is the plane full?
			{
				FlyPlane(ArrivingParty.WhichPlane, Alfa, Lounge); // yes, fly plane.
			}
			// else plane is not full, so nothing else to do now.
			
			break;
		case PlaneBravo:

			if (ArrivingParty.Size > Bravo.NumSeats) // can the party ever fit on the plane
			{
				//		no, turn party away
				cout << "Unfortunately, the party can never fit on Plane Bravo. Please inform the customer of this." << endl;
				break;
			}
			// else, they could possibly fit

			if (ArrivingParty.Size > Bravo.NumEmptySeats)	// are there enough empty seats now?
			{
				if (ArrivingParty.Size > Lounge.NumEmptySeats) // party does not fit now. can they fit in the lounge?
				{
					// no, turn party away.
					cout << "Unfortunately, there is not enough room on plane Bravo, nor in the lounge." << endl;
					cout << "Please direct " << ArrivingParty.Name << " to try again on a different day." << endl;
					break;
				}
				// yes, put them into the lounge
				// TODO Move party into lounge.
				cout << "Please direct " << ArrivingParty.Name << " to the lounge. They will fly at the next opportunity." << endl;
				Lounge.Parties[Lounge.NumParties] = ArrivingParty;
				Lounge.NumParties++;
				Lounge.NumEmptySeats = (Lounge.NumEmptySeats - ArrivingParty.Size);
				cout << "There are " << Lounge.NumEmptySeats << " seats left in the lounge." << endl;
				break;
			}

			// yes, put party on plane
			cout << "Please direct the party onto plane Bravo." << endl;
			// TODO Put party on plane.
			Bravo.Parties[Bravo.NumParties] = ArrivingParty;
			Bravo.NumParties++;
			Bravo.NumEmptySeats = (Bravo.NumEmptySeats - ArrivingParty.Size);
			cout << "There are " << Bravo.NumEmptySeats << " seats left on Bravo." << endl;

			if (Bravo.NumEmptySeats == 0) // is the plane full?
			{
				FlyPlane(ArrivingParty.WhichPlane, Bravo, Lounge); // yes, fly plane.
			}
			// else plane is not full, so nothing else to do now.

			break;
		case InvalidPlane:
		//information is not correct
			cout << "Error: Invalid plane entered. Please try again." << endl;
				cin.clear(); // clear up any error conditions
				cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
			break;
		default:
			cout << "Internal error 202, please contact customer support" << endl;
			system("pause");
			exit(0);
		}
		break;
	}
		
	case CmdShutdown: // Write Shutdown code
	{

		if ((!AlfaInitialized) && (!BravoInitialized) && (!LoungeInitialized))
		{
			cout << "Error: Nothing was not initialized." << endl;
			system("pause");
			exit(0);
			break;
		}
		else if ((!AlfaInitialized) || (!BravoInitialized) || (!LoungeInitialized))
		{
			if (AlfaInitialized)
			{
				delete [] Alfa.Parties;
			}
			if (BravoInitialized)
			{
				delete [] Bravo.Parties;
			}
			if (LoungeInitialized)
			{
				delete [] Lounge.Parties;
			}
			_CrtDumpMemoryLeaks();
			system("pause");
			exit(0);
			break;
		}
		else
		{
			while (Alfa.NumParties > 0)
			{
				FlyPlane(PlaneAlfa, Alfa, Lounge);
			}
			//do same loop for Bravo
			while (Bravo.NumParties > 0)
			{
				FlyPlane(PlaneBravo, Bravo, Lounge);
			}

			// TODO make sure we clean up the dynamic array holding parties for each plane and the lounge
			cout << "All passengers have been flown to their destination. Good night!" << endl;
			StillRunning = false;
			delete [] Alfa.Parties;
			delete [] Bravo.Parties;
			delete [] Lounge.Parties;
			_CrtDumpMemoryLeaks();
			break;
		}
	}
	case InvalidCmd:
	{
		cout << "Invalid command, please re-enter" << endl;
			cin.clear(); // clear up any error conditions
			cin.ignore(10000, '\n'); //skip the next 10000 characters, until the \n (line feed)
		break;
	}
	default:
		cout << "Internal error 101, please contact customer support" << endl;
		system("pause");
		exit(0);
	}
	
	} while (StillRunning);
	system("pause");
}