#include "VinSoi.h"

VinSoi::VinSoi():Produs()
{
	an = 0;
	tara = "necunoscut";
	tip = "necunoscut";
	culoare = "necunoscut";
}
VinSoi::VinSoi(const VinSoi& V):Produs(V)
{
	an = V.an;
	tara = V.tara;
	tip = V.tip;
	culoare = V.culoare;
}
VinSoi::~VinSoi()
{
	an = 0;
	tara = "necunoscut";
	tip = "necunoscut";
	culoare = "necunoscut";
}
VinSoi &VinSoi::operator=(const VinSoi&V)
{
	pret = V.pret;
	cant = V.cant;
	vandut = V.vandut;
	an = V.an;
	tara = V.tara;
	tip = V.tip;
	culoare = V.culoare;
	return *this;
}
istream &operator>>(istream &in, VinSoi&V)
{
	return V.read(in);
}
ostream &operator <<(ostream &out, VinSoi&V)
{
	return V.print(out);
}
VinSoi operator+(const VinSoi &V1, const VinSoi &V2)
{
	VinSoi rez = V1;
	rez.cant = V1.cant + V2.cant;
	return rez;
}
VinSoi operator-(const VinSoi&V1, const VinSoi &V2)
{
	VinSoi rez = V1;
	rez.cant = V1.cant - V2.cant;
	return rez;
}