#pragma once
#include "Produs.h"
#include <string>
class VinVarsat :
	public Produs<double>
{
public:
	VinVarsat();
	VinVarsat(const VinVarsat&);
	virtual ~VinVarsat();
	istream &read(istream &in)
	{
		in >> pret >> cant >> tip;
		return in;
	}
	ostream &print(ostream &out)
	{
		out << "Vinul varsat, " << tip << " este la pretul de " << pret << " pe litru.\n";
		out << "Sunt " << cant << " litri.\n";
		return out;
	}
	VinVarsat &operator=(const VinVarsat&);
	friend istream &operator>>(istream &, VinVarsat&);
	friend ostream &operator <<(ostream &, VinVarsat&);
	friend VinVarsat operator+(const VinVarsat &, const VinVarsat &);
	friend VinVarsat operator-(const VinVarsat&, const VinVarsat &);
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

