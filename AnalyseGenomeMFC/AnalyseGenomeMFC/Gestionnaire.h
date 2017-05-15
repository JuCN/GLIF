#pragma once
#include "Utilisateur.h"
#include "Maladie.h"
#include "Dictionnaire.h"
class Gestionnaire : public Utilisateur
{
public:
	Gestionnaire(string nom, string prenom, string email, string mdp, long idDico);

	long getIdDico() const;

	bool AjouterMaladie(string nom, string description, string genes);

	bool ModifierMaladie(string genes, int pos);

	bool SupprimerMaladie(int pos);

	virtual ~Gestionnaire();

private:
	long idDico;
};

