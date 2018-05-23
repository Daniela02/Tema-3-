#pragma once
#include "Produs.h"
#include "Varza.h"
#include "Faina.h"
#include "Bere.h"
#include "VinSoi.h"
#include "VinVarsat.h"
#include "Cartofi.h"
#include "Jucarie.h"
#include "StocMagazinZi.h"
#include <string>

class Oferta
{
public:
	Varza v;
	Faina f1, f2;
	Bere b1, b2;	//b1 blonda, b2 bruna
	VinVarsat va, vr;
	VinSoi *vs;
	Cartofi ca, cr;
	Jucarie *j;
	int nrJucarii, nrSoiVin;
	double t;
	Oferta();
	Oferta(const Oferta &);
	virtual ~Oferta();
	friend ostream &operator <<(ostream &, Oferta&);
	int CautaVin(VinSoi &);
	int CautaJucarie(Jucarie &);
	int pushVinSoi(VinSoi &V)
	{
		int i = CautaVin(V);
		if (i)
			vs[i] = vs[i] + V;
		else
		{
			nrSoiVin++;
			vs[nrSoiVin] = V;
			i = nrSoiVin;
		}
		vs[i].ModificaCant(0);
		return i;
	}
	int pushJucarie(Jucarie &J)
	{
		int i = CautaJucarie(J);
		if (i)
			j[i] = j[i] + J;
		else
		{
			nrJucarii++;
			j[nrJucarii] = J;
			i = nrJucarii;
		}
		j[i].ModificaCant(0);
		return i;
	}
};

