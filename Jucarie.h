#pragma once
#include "Produs.h"
#include <string>
class Jucarie :
	public Produs<int>
{
	friend class StocMagazinZi;;
public:
	Jucarie();
	Jucarie(const Jucarie &);
	virtual ~Jucarie();
	istream &read(istream &in)
	{
		in >> pret >> cant >> nume;
		return in;
	}
	ostream &print(ostream &out)
	{
		out << nume << " costa " << pret << ".\nSunt " << cant << " jucarii.\n";
		return out;
	}
	Jucarie &operator=(const Jucarie &);
	friend istream &operator>> (istream &, Jucarie &);
	friend ostream &operator<<(ostream &, Jucarie&);
	friend Jucarie operator+(const Jucarie &, const Jucarie&);
	friend Jucarie operator-(const Jucarie &, const Jucarie&);
	string Nume()
	{
		return nume;
	}
protected:
	string nume;
};

