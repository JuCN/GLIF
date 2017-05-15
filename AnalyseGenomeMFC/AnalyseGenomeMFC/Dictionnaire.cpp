#include "stdafx.h"
#include "Dictionnaire.h"


int Dictionnaire::Id_ = 0;

Dictionnaire::Dictionnaire()
{

}


Dictionnaire::~Dictionnaire()
{
}

Maladie Dictionnaire::getMaladie(int nMaladie)
{
	Maladie m;
	m = maladies.at(nMaladie);
	return m;
}

vector<Maladie> Dictionnaire::getAllMaladies()
{
	return maladies;
}

bool Dictionnaire::AjouterMaladie(Maladie m)
{
	bool res = false;
	maladies.push_back(m);
	/*
	* Code SQLite qui influera res
	*
	*/
	res = true; //Pour le moment
	return res;
}

bool Dictionnaire::ModifierMaladie(string genes, int pos)
{
	bool res = false;
	maladies.at(pos).chargerGenome(genes);
	/*
	* Code SQLite qui influera res
	*/
	res = true; // Pour le moment
	return res;
}

bool Dictionnaire::SupprimerMaladie(int pos)
{
	bool res = false;
	maladies.erase(maladies.begin() + pos);
	/*
	* Code SQLite qui influera res
	*/
	res = true; // Pour le moment
	return res;
}
