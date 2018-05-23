#include "VinVarsat.h"

VinVarsat::VinVarsat():Produs()
{
	tip = "necunoscut";
}
VinVarsat::VinVarsat(const VinVarsat&V):Produs(V)
{
	tip = V.tip;
}
VinVarsat::~VinVarsat()
{
	tip = "necunoscut";
}
VinVarsat &VinVarsat:: operator=(const VinVarsat&V)
{
	pret = V.pret;
	cant = V.cant;
	vandut = V.vandut;
	tip = V.tip;
	return *this;
}
istream &operator>>(istream &in, VinVarsat&V)
{
	return V.read(in);
}
ostream &operator <<(ostream &out, VinVarsat&V)
{
	return V.print(out);
}
VinVarsat operator+(const VinVarsat &V1, const VinVarsat &V2)
{
	VinVarsat rez = V1;
	rez.cant = V1.cant + V2.cant;
	return rez;
}
VinVarsat operator-(const VinVarsat&V1, const VinVarsat &V2)
{
	VinVarsat rez = V1;
	rez.cant = V1.cant - V2.cant;
	return rez;
}