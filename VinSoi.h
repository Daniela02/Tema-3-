#pragma once
#include "Produs.h"
#include <string>
class VinSoi :
	public Produs<int>
{
	friend class StocMagazinZi;
public:
	VinSoi();
	VinSoi(const VinSoi&);
	virtual ~VinSoi();
	istream &read(istream &in)
	{
		in >> pret >> cant >> an >> tara >> tip >> culoare;
		return in;
	}
	ostream &print(ostream &out)
	{
		out << "Vinul la sticla, " << culoare << ", "<<tip<<", din anul " << an << ", tara de origine " << tara << " este la pretul de " << pret << " sticla.\n";
		out << "Sunt " << cant << " sticle.\n";
		return out;
	}
	VinSoi &operator=(const VinSoi&);
	friend istream &operator>>(istream &, VinSoi&);
	friend ostream &operator <<(ostream &, VinSoi&);
	friend VinSoi operator+(const VinSoi &, const VinSoi &);
	friend VinSoi operator-(const VinSoi&, const VinSoi &);
	int An()
	{
		return an;
	}
	string Tara()
	{
		return tara;
	}
	string Tip()
	{
		return tip;
	}
	string Culoare()
	{
		return culoare;
	}
	/*void ModificaAn(int val)
	{
		an = val;
	}
	void ModificaTara(string val)
	{
		tara = val;
	}
	void ModificaTip(string val)
	{
		tip = val;
	}*/
protected:
	int an;
	string tara;
	string tip;
	string culoare;
};

