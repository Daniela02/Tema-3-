#include "Oferta.h"

Oferta::Oferta()
{
	t = 0;
	nrJucarii = 0;
	nrSoiVin = 0;
}
Oferta::Oferta(const Oferta &S)
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
	t = S.t;
}
Oferta::~Oferta()
{
	nrJucarii = 0;
	nrSoiVin = 0;
	delete[]j;
	delete[]vs;
	t = 0;
}
ostream &operator <<(ostream &out, Oferta&S)
{
	out << "Cea mai buna oferta este:\n";
	int i;
	if (S.v.Cantitate())
		out << S.v;
	if (S.f1.Cantitate())
		out << S.f1;
	if (S.f2.Cantitate())
		out << S.f2;
	if (S.b1.Cantitate())
		out << S.b1;
	if (S.b2.Cantitate())
		out << S.b2;
	if (S.va.Cantitate())
		out << S.va;
	if (S.vr.Cantitate())
		out << S.vr;
	if (S.ca.Cantitate())
		out << S.ca;
	if(S.cr.Cantitate())
		out<< S.cr;
	for (i = 1; i <= S.nrSoiVin; i++)
		out << S.vs[i];
	for (i = 1; i <= S.nrJucarii; i++)
		out << S.j[i];
	out << "Cost total:" << S.t << "\n";
	return out;
}
int Oferta::CautaVin(VinSoi &V)
{
	int i;
	for (i = 1; i <= nrSoiVin; i++)
	{
		if (vs[i].Tara() == V.Tara() && vs[i].An() == V.An() && vs[i].Tip() == V.Tip() && vs[i].Culoare() == V.Culoare())
			return i;	//potrivire perfecta
	}
	//potriviri partiale
	for (i = 1; i <= nrSoiVin; i++)
		if (vs[i].Tara() == V.Tara() && vs[i].An() == V.An() && vs[i].Tip() == V.Tip() || vs[i].An() == V.An() && vs[i].Tip() == V.Tip() && vs[i].Culoare() == V.Culoare() || vs[i].Tara() == V.Tara() && vs[i].An() == V.An() && vs[i].Culoare() == V.Culoare() || vs[i].Tara() == V.Tara() && vs[i].Tip() == V.Tip() && vs[i].Culoare() == V.Culoare())
			return i;
	for (i = 1; i <= nrSoiVin; i++)
		if (vs[i].Culoare() == V.Culoare() && vs[i].Tara() == V.Tara() || vs[i].Culoare() == V.Culoare() && vs[i].An() == V.An() || vs[i].Tip() == V.Tip() && vs[i].Culoare() == V.Culoare() || vs[i].Tara() == V.Tara() && vs[i].An() == V.An() || vs[i].An() == V.An() && vs[i].Tip() == V.Tip() || vs[i].Tara() == V.Tara() && vs[i].Tip() == V.Tip())
			return i;
	for (i = 1; i <= nrSoiVin; i++)
		if (vs[i].Tara() == V.Tara() || vs[i].An() == V.An() || vs[i].Tip() == V.Tip() || vs[i].Culoare() == V.Culoare())
			return i;
	return 0;
}
int Oferta::CautaJucarie(Jucarie &J)
{
	int i;
	for (i = 1; i <= nrJucarii; i++)
		if (j[i].Nume() == J.Nume())
			return i;
	return 0;
}