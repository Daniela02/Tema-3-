#pragma once
#include "Produs.h"
class Faina :
	public Produs<double>
{
	friend class StocMagazinZi;
public:
	Faina();
	Faina(const Faina&);
	virtual ~Faina();
	istream &read (istream &in)
	{
		in >> pret >> cant >> cal;
		return in;
	}
	ostream &print(ostream &out)
	{
		out << "Faina de calitate " << cal << " costa " << pret << " pe kilogram.\n";
		out << "Sunt " << cant << " kilograme.\n";
		return out;
	}
	Faina &operator=(const Faina&);
	friend istream &operator >>(istream &, Faina &);
	friend ostream &operator <<(ostream &, Faina &);
	friend Faina operator+(const Faina &, const Faina &);
	friend Faina operator-(const Faina &, const Faina &);
	int Calitate()
	{
		return cal;
	}
	void ModificaCal(int val)
	{
		cal = val;
	}
protected:
	int cal;
};

