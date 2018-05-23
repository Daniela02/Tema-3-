#include "Faina.h"

Faina::Faina():Produs()
{
	cal = 0;
}
Faina::Faina(const Faina &F):Produs(F)
{
	cal = F.cal;
}
Faina::~Faina()
{
	cal = 0;
}
Faina &Faina::operator=(const Faina&F)
{
	pret = F.pret;
	cant = F.cant;
	vandut = F.vandut;
	cal = F.cal;
	return *this;
}
istream &operator >>(istream &in, Faina &F)
{
	return F.read(in);
}
ostream &operator <<(ostream &out, Faina &F)
{
	return F.print(out);
}
Faina operator+(const Faina &F1, const Faina &F2)
{
	Faina rez;
	rez = F1;
	rez.cant=F1.cant + F2.cant;
	return rez;
}
Faina operator-(const Faina &F1, const Faina &F2)
{
	Faina rez;
	rez = F1;
	rez.cant = F1.cant - F2.cant;
	return rez;
}