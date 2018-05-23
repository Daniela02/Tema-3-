#include "Cartofi.h"

Cartofi::Cartofi():Produs()
{
	tip = "necunoscut";
}
Cartofi::Cartofi(const Cartofi&C):Produs(C)
{
	tip = C.tip;
}
Cartofi::~Cartofi()
{
	tip = "necunoscut";
}
Cartofi &Cartofi::operator=(const Cartofi&C)
{
	pret = C.pret;
	cant = C.cant;
	vandut = C.vandut;
	tip = C.tip;
	return *this;
}
istream &operator>>(istream &in, Cartofi &C)
{
	return C.read(in);
}
ostream &operator<<(ostream&out, Cartofi &C)
{
	return C.print(out);
}
Cartofi operator +(const Cartofi &C1, const Cartofi &C2)
{
	Cartofi rez = C1;
	rez.cant = C1.cant + C2.cant;
	return rez;
}
Cartofi operator-(const Cartofi&C1, const Cartofi &C2)
{
	Cartofi rez = C1;
	rez.cant = C1.cant - C2.cant;
	return rez;
}