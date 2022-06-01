#ifndef PLANE_H
#define PLANE_H



enum Plane { InvalidPlane = -1, PlaneAlfa, PlaneBravo, NumPlanes };

struct Party
{
	char * Name;
	Plane WhichPlane;
	int Size;
};


struct PlaneInfo
{
	int NumSeats;
	int NumEmptySeats;
	int NumParties;
	Party * Parties;
};


Plane GetPlane();
void FlyPlane(Plane, PlaneInfo &, PlaneInfo &);

#endif PLANE_H