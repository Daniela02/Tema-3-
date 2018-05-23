#pragma once
#include <iostream>

using namespace std;
template <class C>
class Produs
{
	friend class StocMagazinZi;
public:
	virtual istream &read(istream&) = 0;
	virtual ostream &print(ostream&) = 0;
	double Pret()
	{
		return pret;
	}
	C Cantitate()
	{
		return cant;
	}
	int Vandut()
	{
		return vandut;
	}
	void ModificaPret(double val)
	{
		pret = val;
	}
	void ModificaCant(C val)
	{
		cant = val;
	}
	void ModificaVandut(int val)
	{
		vandut += val;
	}
	void ModificaVandut1(int val)
	{
		vandut = val;
	}
protected:
	double pret=0;
	C cant;
	int vandut=0;
};

