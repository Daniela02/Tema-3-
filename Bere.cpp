#include "Bere.h"

Bere::Bere():Produs()
{
	tip = "necunoscut";
}
Bere::Bere(const Bere&B):Produs(B)
{
	tip = B.tip;
}
Bere::~Bere()
{
	tip = "necunoscut";
}
Bere &Bere::operator =(const Bere &B)
{
	pret = B.pret;
	cant = B.cant;
	vandut = B.vandut;
	tip = B.tip;
	return *this;
}
istream &operator >>(istream &in, Bere &B)
{
	return B.read(in);
}
ostream &operator<<(ostream &out, Bere&B)
{
	return B.print(out);
}
Bere operator+(const Bere &B1, const Bere &B2)
{
	Bere rez = B1;
	rez.cant = B1.cant + B2.cant;
	return rez;
}
Bere operator-(const Bere &B1, const Bere &B2)
{
	Bere rez = B1;
	rez.cant = B1.cant - B2.cant;
	return rez;
}