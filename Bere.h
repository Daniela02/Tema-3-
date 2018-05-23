#pragma once
#include "Produs.h"
#include <string>
class Bere :
	public Produs <int>
{
	friend class StocMagazinZi;
public:
	Bere();
	Bere(const Bere &);
	virtual ~Bere();
	istream &read(istream &in)
	{
		in >> pret >> cant >> tip;
		return in;
	}
	ostream &print(ostream &out)
	{
		out << "Berea "<< tip <<" costa " << pret << " doza.\n" << "Sunt " << cant << " doze.\n";
		return out;
	}
	Bere &operator =(const Bere&);
	friend istream &operator >>(istream &, Bere &);
	friend ostream &operator<<(ostream &, Bere&);
	friend Bere operator+(const Bere&, const Bere&);
	friend Bere operator-(const Bere&, const Bere&);
	string Tip()
	{
		return tip;
	}
	void ModificaTip(string val)	
	{
		tip = val;
	}
protected:
	string tip;
};

