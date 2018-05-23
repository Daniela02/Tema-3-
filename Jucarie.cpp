#include "Jucarie.h"

Jucarie::Jucarie():Produs()
{
	nume = "necunoscut";
}
Jucarie::Jucarie(const Jucarie &J):Produs(J)
{
	nume = J.nume;
}
Jucarie::~Jucarie()
{
	nume = "necunoscut";
}
Jucarie &Jucarie::operator=(const Jucarie &J)
{
	pret = J.pret;
	cant = J.cant;
	vandut = J.vandut;
	nume = J.nume;
	return *this;
}
istream &operator>> (istream &in, Jucarie &J)
{
	return J.read(in);
}
ostream &operator<<(ostream &out, Jucarie&J)
{
	return J.print(out);
}
Jucarie operator+(const Jucarie &J1, const Jucarie&J2)
{
	Jucarie rez = J1;
	rez.cant = J1.cant + J2.cant;
	return rez;
}
Jucarie operator-(const Jucarie &J1, const Jucarie&J2)
{
	Jucarie rez = J1;
	rez.cant = J1.cant - J2.cant;
	return rez;
}