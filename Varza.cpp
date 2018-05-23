#include "Varza.h"



Varza::Varza():Produs(){}
Varza::Varza(const Varza &V):Produs(V){}
Varza::~Varza(){}
Varza &Varza::operator=(const Varza &V)
{
	pret = V.pret;
	cant = V.cant;
	vandut = V.vandut;
	return *this;
}
istream &operator >> (istream &in, Varza&V)
{
	return V.read(in);
}
ostream &operator <<(ostream &out, Varza&V)
{
	return V.print(out);
}
Varza operator +(const Varza &V1, const Varza &V2)
{
	Varza rez;
	rez = V1;
	rez.cant = V1.cant + V2.cant;
	return rez;
}
Varza operator -(const Varza &V1, const Varza &V2)
{
	Varza rez;
	rez = V1;
	rez.cant = V1.cant - V2.cant;
	return rez;
}