#pragma once
#include "Produs.h"
#include <iostream>
using namespace std;
class Varza :
	public Produs<int>
{
public:
	Varza();
	Varza(const Varza &);
	virtual ~Varza();
	istream &read(istream &in)
	{
		in >> pret >> cant;
		return in;
	}
	ostream &print(ostream &out)
	{
		out<<"Pretul verzei pe bucata este " << pret << ". \nSunt " << cant << " bucati\n";
		return out;
	}
	friend istream &operator >> (istream &, Varza&);
	friend ostream &operator <<(ostream &, Varza&);
	Varza &operator =(const Varza &);
	friend Varza operator +(const Varza &, const Varza &);
	friend Varza operator -(const Varza &, const Varza &);
};

