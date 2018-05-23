#include "StocMagazinZi.h"

StocMagazinZi::StocMagazinZi()
{
	bani = 0;
	bunuriVandute = 0;
	nrJucarii = 0;
	nrSoiVin = 0;
	stoc = 0;
}
StocMagazinZi::StocMagazinZi(const StocMagazinZi&S)
{
	v = S.v;
	f1 = S.f1;
	f2 = S.f2;
	b1 = S.b1;
	b2 = S.b2;
	va = S.va;
	vr = S.vr;
	ca = S.ca;
	cr = S.cr;
	bani = S.bani;
	bunuriVandute = S.bunuriVandute;
	if (nrJucarii)
	{
		delete[]j;
		j = new Jucarie[S.nrJucarii + 3];
	}
	if (nrSoiVin)
	{
		delete[]vs;
		vs = new VinSoi[S.nrSoiVin + 3];
	}
	nrJucarii = S.nrJucarii;
	nrSoiVin = S.nrSoiVin;
	int i;
	for (i = 1; i <= nrJucarii; i++)
		j[i] = S.j[i];
	for (i = 1; i <= nrSoiVin; i++)
		vs[i] = S.vs[i];
	stoc = S.stoc;
}
StocMagazinZi::~StocMagazinZi()
{
	nrJucarii = 0;
	nrSoiVin = 0;
	bani = 0;
	delete []j;
	delete[]vs;
	bunuriVandute = 0;
}
StocMagazinZi &StocMagazinZi::operator=(const StocMagazinZi &S)
{
	v = S.v;
	f1 = S.f1;
	f2 = S.f2;
	b1 = S.b1;
	b2 = S.b2;
	va = S.va;
	vr = S.vr;
	ca = S.ca;
	cr = S.cr;
	bani = S.bani;
	bunuriVandute = S.bunuriVandute;
	if (nrJucarii)
	{
		delete[]j;
	}
	if (nrSoiVin)
	{
		delete[]vs;
	}
	j = new Jucarie[S.nrJucarii + 3];
	vs = new VinSoi[S.nrSoiVin + 3];
	nrJucarii = S.nrJucarii;
	nrSoiVin = S.nrSoiVin;
	int i;
	for (i = 1; i <= nrJucarii; i++)
		j[i] = S.j[i];
	for (i = 1; i <= nrSoiVin; i++)
		vs[i] = S.vs[i];
	stoc = S.stoc;
	return *this;
}
istream &operator >>(istream &in, StocMagazinZi&S)
{

	in >> S.v >> S.f1 >> S.f2 >> S.b1 >> S.b2 >> S.va >> S.vr >> S.ca >> S.cr;
	int i;
	if (S.nrSoiVin)
	{
		delete[]S.vs;
	}
	in >> S.nrSoiVin;
	S.vs = new VinSoi[S.nrSoiVin + 3];
	for (i = 1; i <= S.nrSoiVin; i++)
		in >> S.vs[i];
	if (S.nrJucarii)
	{
		delete[]S.j;
	}
	in >> S.nrJucarii;
	S.j = new Jucarie[S.nrJucarii + 3];
	for (i = 1; i <= S.nrJucarii; i++)
		in >> S.j[i];
	in>> S.bani >> S.bunuriVandute;
	return in;
}
ostream &operator <<(ostream &out, StocMagazinZi &S)
{
	out << S.v << S.f1 << S.f2 << S.b1 << S.b2 << S.va << S.vr << S.ca << S.cr;
	int i;
	for (i = 1; i <= S.nrSoiVin; i++)
		out << S.vs[i];
	for (i = 1; i <= S.nrJucarii; i++)
		out << S.j[i];
	out<<"Bani total:"<< S.bani <<"\nStocul zilei: "<<S.stoc<<"\nBunuri vandute: "<< S.bunuriVandute << "\n";
	return out;
}
void StocMagazinZi:: InchidereaZilei(ostream &out)
{
	stoc = 0;
	out << "\n\nINCHIDEREA ZILEI\n";
	out << "S-au vandut " << bunuriVandute << " bunuri dupa cum urmeaza:\n";	
	out << "Varza: " << v.vandut << " bucati\n";		stoc += (v.vandut*v.pret);
	out << "Bere blonda: " << b1.vandut << " doze\n";		stoc += (b1.vandut*b1.pret);
	out << "Bere bruna: " << b2.vandut << " doze\n";			stoc += (b2.vandut*b2.pret);
	out << "Faina de calitate I: " << f1.vandut << " kilograme\n";		stoc += (f1.vandut*f1.pret);
	out << "Faina de calitate II: " << f1.vandut << " kilograme \n";		stoc += (f2.vandut*f2.pret);
	out << "Vin rosu sec: " << vr.vandut << " litri\n";		stoc += (vr.vandut*vr.pret);
	out << "Vin alb sec: " << va.vandut << " litri\n";		stoc += (va.vandut*va.pret);
	out << "Cartofi albi: " << ca.vandut << " kilograme\n";		stoc += (ca.vandut*ca.pret);
	out << "Cartofi rosii: " << cr.vandut << " kilograme\n";		stoc += (cr.vandut*cr.pret);
	int i;
	for (i = 1; i <= nrSoiVin; i++)
	{
		out << "Vin " << vs[i].Tip() << ", din " << vs[i].Tara() << ", facut in anul " << vs[i].An() << ": " << vs[i].vandut << " sticle\n";
		stoc += (vs[i].vandut*vs[i].pret);
	}
	for (i = 1; i <= nrJucarii; i++)
	{
		out << j[i].Nume() << ": " << j[i].Vandut() << " bucati\n";
		stoc += (j[i].vandut*j[i].pret);
	}
	out << "In valoare de " << stoc << "\n";
}
int StocMagazinZi::CautaJucarie(string nume)
{
	int i;
	for (i = 1; i <= nrJucarii; i++)
	{
		if (j[i].Nume() == nume)
			return i;
		
	}
	return 0;
}
int StocMagazinZi::CautaVin(string culoare,string tip, int an, string tara)
{
	int i;
	for (i = 1; i <= nrSoiVin; i++)
	{
		if (vs[i].Tara() == tara && vs[i].An() == an && vs[i].Tip() == tip && vs[i].Culoare()==culoare)
			return i;	//potrivire perfecta
	}
	//potriviri partiale
	for (i = 1; i <= nrSoiVin; i++)
		if (vs[i].Tara() == tara && vs[i].An() == an && vs[i].Tip() == tip || vs[i].An() == an && vs[i].Tip() == tip && vs[i].Culoare() == culoare || vs[i].Tara() == tara && vs[i].An() == an && vs[i].Culoare() == culoare || vs[i].Tara() == tara &&vs[i].Tip() == tip && vs[i].Culoare() == culoare)
			return i;
	for (i = 1; i <= nrSoiVin; i++)
		if (vs[i].Culoare() == culoare && vs[i].Tara() == tara || vs[i].Culoare() == culoare && vs[i].An() == an || vs[i].Tip() == tip && vs[i].Culoare() == culoare || vs[i].Tara() == tara && vs[i].An() == an || vs[i].An() == an && vs[i].Tip() == tip || vs[i].Tara() == tara && vs[i].Tip() == tip)
			return i;
	for (i = 1; i <= nrSoiVin; i++)
		if (vs[i].Tara() == tara || vs[i].An() == an  || vs[i].Tip() == tip || vs[i].Culoare() == culoare)
			return i;
	return 0;
}
void StocMagazinZi::InitializareVandut()
{
	v.ModificaVandut1(0);
	b1.ModificaVandut1(0);
	b2.ModificaVandut1(0);
	f1.ModificaVandut1(0);
	f2.ModificaVandut1(0);
	ca.ModificaVandut1(0);
	cr.ModificaVandut1(0);
	va.ModificaVandut1(0);
	vr.ModificaVandut1(0);
	int i;
	cout << nrJucarii;
	for (i = 1; i <= nrJucarii; i++)
		j[i].ModificaVandut1(0);
	for (i = 1; i <= nrSoiVin; i++)
		vs[i].ModificaVandut1(0);
}