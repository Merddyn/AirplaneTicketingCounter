#include "Plane.h"
#include "ReadString.h"
#include <string.h>
#include <iostream>
//#include <stdlib.h>


char * PlaneNames[] = {
						"Alfa",
						"Bravo"
};

Plane GetPlane()
{
	char * PlaneName;
	Plane WhichPlane;

	PlaneName = ReadString(); // get back a dynamic string of characters from ReadString
	

	for (WhichPlane = PlaneAlfa; WhichPlane < NumPlanes; WhichPlane = (Plane)(WhichPlane + 1))
	{
		if (_strcmpi(PlaneName, PlaneNames[WhichPlane]) == 0) // find which command we just read
		{
			delete[] PlaneName; // need to make sure we clean up dynamic memory
			return WhichPlane;
		}
		else;
	}
	delete[] PlaneName;
	return InvalidPlane;
	// find which command we just read
}

void FlyPlane(Plane WhichPlane, PlaneInfo & Plane, PlaneInfo & Lounge) //TODO Write FlyPlane method
{
	do
		{
		std::cout << "Plane ";
		if (WhichPlane == PlaneAlfa)
		{
			std::cout << "Alfa";
		}
		else if (WhichPlane == PlaneBravo)
		{
			std::cout << "Bravo";
		}
			std::cout << " leaving with the following parties: " << std::endl;
			for (int i = 0; i < Plane.NumParties; i++) // print the names of all parties on the plane.
			{
				std::cout << Plane.Parties[i].Name << " party of " << Plane.Parties[i].Size << std::endl;
			}
			for (int i = 0; i < Plane.NumParties; i++) // delete each of the names
			{
				delete [] Plane.Parties[i].Name;
			}
			delete [] Plane.Parties;
			Plane.NumEmptySeats = Plane.NumSeats; // reset number of empty seats and number of parties
			Plane.NumParties = 0;
			Plane.Parties = new Party[Plane.NumSeats];
	
		// TODO move the people in lounge to the plane
			for (int i = 0; i < Lounge.NumParties; i++)
			{
				if (Lounge.Parties[i].WhichPlane == WhichPlane)
				{
					if (Plane.NumEmptySeats >= Lounge.Parties[i].Size)
					{
						std::cout << "Moving party " << Lounge.Parties[i].Name << " size " << Lounge.Parties[i].Size << " from the lounge to the plane." << std::endl;
						Plane.Parties[Plane.NumParties] = Lounge.Parties[i];
						Plane.NumParties++;
						Plane.NumEmptySeats -= Lounge.Parties[i].Size;
						Lounge.NumEmptySeats += Lounge.Parties[i].Size;
						for (int j = i; j < Lounge.NumParties; j++)
						{
							Party TempParty;
							TempParty = Lounge.Parties[j];
							Lounge.Parties[j] = Lounge.Parties[j + 1];
							Lounge.Parties[j + 1] = TempParty;
						}
						Lounge.NumParties--;
						i--;
					}
				}
			}
			std::cout << "There are " << Plane.NumEmptySeats << " seats left. " << std::endl;
		} while (Plane.NumEmptySeats < 1);
	
}
