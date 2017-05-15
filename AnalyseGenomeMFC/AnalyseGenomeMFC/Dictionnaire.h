#pragma once
#include <vector>
#include "Maladie.h"
using namespace std;



class Dictionnaire
{
public:


	Dictionnaire();
	~Dictionnaire();

	Maladie getMaladie(int nMaladie);

	vector<Maladie> getAllMaladies();

	bool AjouterMaladie(Maladie m);

	bool ModifierMaladie(string genes, int pos);

	bool SupprimerMaladie(int pos);


protected:
	static int Id_;
	int id;
	vector<Maladie> maladies;
};

