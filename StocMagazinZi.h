#pragma once
#include "Produs.h"
#include "Varza.h"
#include "Faina.h"
#include "Bere.h"
#include "VinSoi.h"
#include "VinVarsat.h"
#include "Cartofi.h"
#include "Jucarie.h"
#include <string>
class StocMagazinZi
{
public:
	Varza v;
	Faina f1, f2;
	Bere b1, b2;	//b1 blonda, b2 bruna
	VinVarsat va, vr;
	VinSoi *vs;
	Cartofi ca, cr;
	Jucarie *j;
	//stocul se modifica o singura data la sfarsitul zilei
	double bani; //total
	double stoc; //dupa o zi
	int bunuriVandute;
	int nrSoiVin;
	int nrJucarii;
	StocMagazinZi();
	StocMagazinZi(const StocMagazinZi&);
	virtual ~StocMagazinZi();
	StocMagazinZi &operator=(const StocMagazinZi &);
	friend istream &operator >>(istream &, StocMagazinZi&);
	friend ostream &operator <<(ostream &, StocMagazinZi &);
	void InchidereaZilei(ostream &);
	int CautaJucarie(string );
	int CautaVin(string,string, int, string);
	void InitializareVandut();
};

