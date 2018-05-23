#include <iostream>
#include <fstream>
#include "Produs.h"
#include "Varza.h"
#include "Faina.h"
#include "Bere.h"
#include "VinSoi.h"
#include "VinVarsat.h"
#include "Cartofi.h"
#include "Jucarie.h"
#include "StocMagazinZi.h"
#include "Oferta.h"
#include <string>

using namespace std;
ifstream f("IN.txt");
ifstream c("client.txt");
ofstream g("OUT.txt");
StocMagazinZi *S;
int n; //nr de zile
int nc; //nr clienti pe o zi
void initializare(Oferta &O, const StocMagazinZi &S)
{
	O.v.ModificaCant(0);
	O.b1.ModificaCant(0);
	O.b2.ModificaCant(0);
	O.f1.ModificaCant(0);
	O.f2.ModificaCant(0);
	O.ca.ModificaCant(0);
	O.cr.ModificaCant(0);
	O.va.ModificaCant(0);
	O.vr.ModificaCant(0);
	if (O.nrJucarii)
	{
		delete[]O.j;
	}
	if (O.nrSoiVin)
	{
		delete[]O.vs;
	}
	O.t = 0;
	O.nrJucarii = 0;
	O.nrSoiVin = 0;
	O.j = new Jucarie[S.nrJucarii + 3];
	O.vs = new VinSoi[S.nrSoiVin + 3];
}
void oferta(int i, Oferta &O)
{
	string raspuns;
	cin >> raspuns;
	if (raspuns == "da")
	{
		//schimb bani-bunuri
		S[i].v.ModificaCant(S[i].v.Cantitate() - O.v.Cantitate());
		S[i].v.ModificaVandut(O.v.Cantitate());
		S[i].b1.ModificaCant(S[i].b1.Cantitate() - O.b1.Cantitate());
		S[i].b1.ModificaVandut(O.b1.Cantitate());
		S[i].b2.ModificaCant(S[i].b2.Cantitate() - O.b2.Cantitate());
		S[i].b2.ModificaVandut(O.b2.Cantitate());
		S[i].f1.ModificaCant(S[i].f1.Cantitate() - O.f1.Cantitate());
		S[i].f1.ModificaVandut(O.f1.Cantitate());
		S[i].f2.ModificaCant(S[i].f2.Cantitate() - O.f2.Cantitate());
		S[i].f2.ModificaVandut(O.f2.Cantitate());
		S[i].ca.ModificaCant(S[i].ca.Cantitate() - O.ca.Cantitate());
		S[i].ca.ModificaVandut(O.ca.Cantitate());
		S[i].cr.ModificaCant(S[i].cr.Cantitate() - O.cr.Cantitate());
		S[i].cr.ModificaVandut(O.cr.Cantitate());
		S[i].va.ModificaCant(S[i].va.Cantitate() - O.va.Cantitate());
		S[i].va.ModificaVandut(O.va.Cantitate());
		S[i].vr.ModificaCant(S[i].vr.Cantitate() - O.vr.Cantitate());
		S[i].vr.ModificaVandut(O.vr.Cantitate());
		int r, poz;
		for (r = 1; r <= O.nrJucarii; r++)
		{

			poz = S[i].CautaJucarie(O.j[r].Nume());
			S[i].j[poz].ModificaCant(S[i].j[poz].Cantitate() - O.j[r].Cantitate());
			S[i].j[poz].ModificaVandut(O.j[r].Cantitate());
		}
		for (r = 1; r <= O.nrSoiVin; r++)
		{
			poz = S[i].CautaVin(O.vs[r].Culoare(), O.vs[r].Tip(), O.vs[r].An(), O.vs[r].Tara());
			S[i].vs[poz].ModificaCant(S[i].vs[poz].Cantitate() - O.vs[r].Cantitate());
			S[i].vs[poz].ModificaVandut(O.vs[r].Cantitate());
		}
		S[i].bani += O.t;
	}
	else
		cout << "nu s-a efectuat schimbul\n";
}
int main()
{
	string zi, rand,  urmC="urmatorul client", urmZi="urmatoare zi";
	f >> n;
	int i=1;
	Oferta O;
	S = new StocMagazinZi[n + 3];
	f >> S[1];
	g << S[1];
	initializare(O, S[1]);
	while (getline(c,rand) && i<=n)
	{
		if (rand != urmC && rand != urmZi)
		{
			string *cuv = new string[10];
			int k, lr = rand.size(), l=1;
			for (k = 0; k <= lr; k++)
			{
				if (rand[k] != ' ')
					cuv[l].push_back(rand[k]);
				else
					l++;//nr de cuvinte de pe fiecare rand
			}

			if (cuv[1] == "varza")
			{
				int cant = atoi(cuv[2].c_str());
				if (cant > S[i].v.Cantitate())
					cant = S[i].v.Cantitate();
				O.t += (S[i].v.Pret()*cant);
				O.v.ModificaCant(O.v.Cantitate() + cant);
				O.v.ModificaPret(S[i].v.Pret());
			}
			else
				if (cuv[1] == "bere")
				{
					int cant;
					if (cuv[2] == "blonda")
					{
						cant = atoi(cuv[3].c_str());
						if (cant > S[i].b1.Cantitate())
							cant = S[i].b1.Cantitate();
						O.t += (S[i].b1.Pret()*cant);
						O.b1.ModificaCant(O.b1.Cantitate() + cant);
						O.b1.ModificaPret(S[i].b1.Pret());
						O.b1.ModificaTip("blonda");
					}
					else
						if(cuv[2]== "bruna")
						{
							cant = atoi(cuv[3].c_str());
							if (cant > S[i].b2.Cantitate())
								cant = S[i].b2.Cantitate();
							O.t += (S[i].b2.Pret()*cant);
							O.b2.ModificaCant(O.b2.Cantitate() + cant);
							O.b2.ModificaPret(S[i].b2.Pret());
							O.b2.ModificaTip("bruna");
						}
						else
							if (S[i].b1.Pret() < S[i].b2.Pret())
							{
								cant = atoi(cuv[2].c_str());
								if (cant > S[i].b1.Cantitate())
									cant = S[i].b1.Cantitate();
								O.t += (S[i].b1.Pret()*cant);
								O.b1.ModificaCant(O.b1.Cantitate() + cant);
								O.b1.ModificaPret(S[i].b1.Pret());
								O.b1.ModificaTip("blonda");
							}
							else
							{
								cant = atoi(cuv[2].c_str());
								if (cant > S[i].b2.Cantitate())
									cant = S[i].b2.Cantitate();
								O.t += (S[i].b2.Pret()*cant);
								O.b2.ModificaCant(O.b2.Cantitate() + cant);
								O.b2.ModificaPret(S[i].b2.Pret());
								O.b2.ModificaTip("bruna");
							}
				}
				else
					if (cuv[1] == "cartofi")
					{
						double cant;
						if (cuv[2] == "albi")
						{
							cant = atof(cuv[3].c_str());
							if (cant > S[i].ca.Cantitate())
								cant = S[i].ca.Cantitate();
							O.t += (S[i].ca.Pret()*cant);
							O.ca.ModificaCant(O.ca.Cantitate() + cant);
							O.ca.ModificaPret(S[i].ca.Pret());
							O.ca.ModificaTip("albi");
						}
						else
							if(cuv[2]=="rosii")
							{
								cant = atof(cuv[3].c_str());
								if (cant > S[i].cr.Cantitate())
									cant = S[i].cr.Cantitate();
								O.t += (S[i].cr.Pret()*cant);
								O.cr.ModificaCant(O.cr.Cantitate() + cant);
								O.cr.ModificaPret(S[i].cr.Pret());
								O.cr.ModificaTip("rosii");
							}
							else
								if (S[i].ca.Pret() < S[i].cr.Pret())
								{
									cant = atof(cuv[2].c_str());
									if (cant > S[i].ca.Cantitate())
										cant = S[i].ca.Cantitate();
									O.t += (S[i].ca.Pret()*cant);
									O.ca.ModificaCant(O.ca.Cantitate() + cant);
									O.ca.ModificaPret(S[i].ca.Pret());
									O.ca.ModificaTip("albi");
								}
								else
								{
									cant = atof(cuv[2].c_str());
									if (cant > S[i].cr.Cantitate())
										cant = S[i].cr.Cantitate();
									O.t += (S[i].cr.Pret()*cant);
									O.cr.ModificaCant(O.cr.Cantitate() + cant);
									O.cr.ModificaPret(S[i].cr.Pret());
									O.cr.ModificaTip("rosii");
								}
					}
					else
						if (cuv[1] == "faina")
						{
							double cant;
							if (cuv[2] == "I")
							{
								cant = atof(cuv[3].c_str());
								if (cant > S[i].f1.Cantitate())
									cant = S[i].f1.Cantitate();
								O.t += (S[i].f1.Pret()*cant);
								O.f1.ModificaCant(O.f1.Cantitate() + cant);
								O.f1.ModificaPret(S[i].f1.Pret());
								O.f1.ModificaCal(1);
							}
							else
								if (cuv[2] == "II")
								{
									cant = atof(cuv[3].c_str());
									if (cant > S[i].f2.Cantitate())
										cant = S[i].f2.Cantitate();
									O.t += (S[i].f2.Pret()*cant);
									O.f2.ModificaCant(O.f2.Cantitate() + cant);
									O.f2.ModificaPret(S[i].f2.Pret());
									O.f2.ModificaCal(2);
								}
								else
									if (S[i].f1.Pret() < S[i].f2.Pret())
									{
										cant = atof(cuv[2].c_str());
										if (cant > S[i].f1.Cantitate())
											cant = S[i].f1.Cantitate();
										O.t += (S[i].f1.Pret()*cant);
										O.f1.ModificaCant(O.f1.Cantitate() + cant);
										O.f1.ModificaPret(S[i].f1.Pret());
										O.f1.ModificaCal(1);
									}
									else
									{
										cant = atof(cuv[3].c_str());
										if (cant > S[i].f2.Cantitate())
											cant = S[i].f2.Cantitate();
										O.t += (S[i].f2.Pret()*cant);
										O.f2.ModificaCant(O.f2.Cantitate() + cant);
										O.f2.ModificaPret(S[i].f2.Pret());
										O.f2.ModificaCal(2);
									}
						}
						else
							if (cuv[1]=="vin")
							{
								if (cuv[l] == "sticla" || cuv[l] == "sticle")
								{
									if (l > 2 && cuv[2] == "rosu")
									{
										if (l > 3 && cuv[3] == "dulce" )
										{
											if (l > 4 && cuv[4][0] >= 'a'&& cuv[4][0] <= 'z')
											{
												int an;
												an = atoi(cuv[5].c_str());
												if (an > 1800)
												{
													int cant;
													cant = atoi(cuv[6].c_str());
													int poz = S[i].CautaVin("rosu", "dulce", an, cuv[4]);
													if (cant > S[i].vs[poz].Cantitate())
														cant = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*cant);
													int p=O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + cant);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
												else
												{
													//an este cantitatea
													int poz= S[i].CautaVin("rosu", "dulce", 0, cuv[4]);
													if (an > S[i].vs[poz].Cantitate())
														an = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*an);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + an);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
											}
											else
											{
												int an;
												an = atoi(cuv[4].c_str());
												if (an > 1800)
												{
													int cant;
													cant = atoi(cuv[5].c_str());
													int poz = S[i].CautaVin("rosu", "dulce", an, "necunoscut");
													if (cant > S[i].vs[poz].Cantitate())
														cant = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*cant);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + cant);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
												else
												{
													//an este cantitatea
													int poz = S[i].CautaVin("rosu", "dulce", 0, "necunoscut");
													if (an > S[i].vs[poz].Cantitate())
														an = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*an);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + an);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
											}
										}
										else  //sec
										{
											if (l > 4 && cuv[4][0] >= 'a'&& cuv[4][0] <= 'z')
											{
												int an;
												an = atoi(cuv[5].c_str());
												if (an > 1800)
												{
													int cant;
													cant = atoi(cuv[6].c_str());
													int poz = S[i].CautaVin("rosu", "sec", an, cuv[4]);
													if (cant > S[i].vs[poz].Cantitate())
														cant = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*cant);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + cant);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
												else
												{
													//an este cantitatea
													int poz = S[i].CautaVin("rosu", "sec", 0, cuv[4]);
													if (an > S[i].vs[poz].Cantitate())
														an = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*an);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + an);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
											}
											else
											{
												int an;
												an = atoi(cuv[4].c_str());
												if (an > 1800)
												{
													int cant;
													cant = atoi(cuv[5].c_str());
													int poz = S[i].CautaVin("rosu", "sec", an, "necunoscut");
													if (cant > S[i].vs[poz].Cantitate())
														cant = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*cant);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + cant);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
												else
												{
													//an este cantitatea
													int poz = S[i].CautaVin("rosu", "sec", 0, "necunoscut");
													if (an > S[i].vs[poz].Cantitate())
														an = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*an);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + an);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
											}
										}
									}
									else //alb
									{
										if (l > 3 && cuv[3] == "dulce")
										{
											if (l > 4 && cuv[4][0] >= 'a'&& cuv[4][0] <= 'z')
											{
												int an;
												an = atoi(cuv[5].c_str());
												if (an > 1800)
												{
													int cant;
													cant = atoi(cuv[6].c_str());
													int poz = S[i].CautaVin("alb", "dulce", an, cuv[4]);
													if (cant > S[i].vs[poz].Cantitate())
														cant = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*cant);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + cant);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
												else
												{
													//an este cantitatea
													int poz = S[i].CautaVin("alb", "dulce", 0, cuv[4]);
													if (an > S[i].vs[poz].Cantitate())
														an = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*an);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + an);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
											}
											else
											{
												int an;
												an = atoi(cuv[4].c_str());
												if (an > 1800)
												{
													int cant;
													cant = atoi(cuv[5].c_str());
													int poz = S[i].CautaVin("alb", "dulce", an, "necunoscut");
													if (cant > S[i].vs[poz].Cantitate())
														cant = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*cant);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + cant);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
												else
												{
													//an este cantitatea
													int poz = S[i].CautaVin("alb", "dulce", 0, "necunoscut");
													if (an > S[i].vs[poz].Cantitate())
														an = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*an);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + an);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
											}
										}
										else  //sec
										{
											if (l > 4 && cuv[4][0] >= 'a'&& cuv[4][0] <= 'z')
											{
												int an;
												an = atoi(cuv[5].c_str());
												if (an > 1800)
												{
													int cant;
													cant = atoi(cuv[6].c_str());
													int poz = S[i].CautaVin("alb", "sec", an, cuv[4]);
													if (cant > S[i].vs[poz].Cantitate())
														cant = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*cant);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + an);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
												else
												{
													//an este cantitatea
													int poz = S[i].CautaVin("alb", "sec", 0, cuv[4]);
													if (an > S[i].vs[poz].Cantitate())
														an = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*an);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + an);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
											}
											else
											{
												int an;
												an = atoi(cuv[4].c_str());
												if (an > 1800)
												{
													int cant;
													cant = atoi(cuv[5].c_str());
													int poz = S[i].CautaVin("alb", "sec", an, "necunoscut");
													if (cant > S[i].vs[poz].Cantitate())
														cant = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*cant);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate() + cant);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
												else
												{
													//an este cantitatea
													int poz = S[i].CautaVin("alb", "sec", 0, "necunoscut");
													if (an > S[i].vs[poz].Cantitate())
														an = S[i].vs[poz].Cantitate();
													O.t += (S[i].vs[poz].Pret()*an);
													int p = O.pushVinSoi(S[i].vs[poz]);
													O.vs[p].ModificaCant(O.vs[p].Cantitate()+an);
													O.vs[p].ModificaPret(S[i].vs[p].Pret());
												}
											}
										}
									}

								}
								else //vin varsat
								{
									if (cuv[2] == "rosu")
									{
										double cant = atof(cuv[3].c_str());
										if (cant > S[i].vr.Cantitate())
											cant = S[i].vr.Cantitate();
										O.t += (S[i].vr.Pret()*cant);
										O.vr.ModificaCant(O.vr.Cantitate() + cant);
										O.vr.ModificaPret(S[i].vr.Pret());
										O.vr.ModificaTip("rosu");
									}
									else
										if (cuv[2] == "alb")
										{
											double cant = atof(cuv[3].c_str());
											if (cant > S[i].va.Cantitate())
												cant = S[i].va.Cantitate();
											O.t += (S[i].va.Pret()*cant);
											O.va.ModificaCant(O.va.Cantitate() + cant);
											O.va.ModificaPret(S[i].va.Pret());
											O.va.ModificaTip("alb");
										}
										else
											if (S[i].vr.Pret() < S[i].va.Pret())
											{
												double cant = atof(cuv[2].c_str());
												if (cant > S[i].vr.Cantitate())
													cant = S[i].vr.Cantitate();
												O.t += (S[i].vr.Pret()*cant);
												O.vr.ModificaCant(O.vr.Cantitate() + cant);
												O.vr.ModificaPret(S[i].vr.Pret());
												O.vr.ModificaTip("rosu");
											}
											else
											{
												double cant = atof(cuv[2].c_str());
												if (cant > S[i].va.Cantitate())
													cant = S[i].va.Cantitate();
												O.t += (S[i].va.Pret()*cant);
												O.va.ModificaCant(O.va.Cantitate() + cant);
												O.va.ModificaPret(S[i].va.Pret());
												O.va.ModificaTip("alb");
											}
								}
							}
							else
							{
								int poz = S[i].CautaJucarie(cuv[1]);
								if (poz)
								{
									int cant = atoi(cuv[2].c_str());
									if (cant > S[i].j[poz].Cantitate())
										cant = S[i].j[poz].Cantitate();
									O.t += (S[i].j[poz].Pret()*cant);
									int p = O.pushJucarie(S[i].j[poz]); 
									O.j[p].ModificaCant(O.j[p].Cantitate()+cant);
									O.j[p].ModificaPret(S[i].j[p].Pret());
								}
							}
						
		}
		else
		{
			cout << O << "\n";
			oferta(i, O);
			initializare(O, S[1]);
			if (rand == urmZi)
			{
				S[i].InchidereaZilei(g);
				S[i + 1] = S[i];	//initializare stoc
				i++;
				S[i].InitializareVandut();
			}
		}
	}
	cout << O << "\n";
	oferta(i, O);
	S[i].InchidereaZilei(g);
	int op;
	cin >> op;
	f.close();
	g.close();
	c.close();
	delete[]S;
	return 0;
}