#pragma once
#include "Produs.h"
#include <string>

class Cartofi :
	public Produs<double>
{
public:
	Cartofi();
	Cartofi(const Cartofi&);
	virtual ~Cartofi();
	istream &read(istream &in)
	{
		in >> pret >> cant >> tip;
		return in;
	}
	ostream &print(ostream &out)
	{
		out << "Kilogramul de cartofi " << tip << " costa " << pret << ".\nSunt " << cant << " kilograme.\n";
		return out;
	}
	Cartofi &operator=(const Cartofi&);
	friend istream &operator>>(istream &, Cartofi &);
	friend ostream &operator<<(ostream&, Cartofi&);
	friend Cartofi operator +(const Cartofi &, const Cartofi &);
	friend Cartofi operator-(const Cartofi&, const Cartofi &);
	string Tip()
	{
		return tip;
	}
	void ModificaTip(string val)
	{
		tip=val;
	}
protected:
	string tip;
};

