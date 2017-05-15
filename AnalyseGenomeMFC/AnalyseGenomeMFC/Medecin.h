#pragma once
#include "Patient.h"
#include "Utilisateur.h"
#include <vector>
class Medecin : public Utilisateur
{
public:

	//Constructeur
	Medecin(string nom, string prenom, string email, string mdp);

	//Destructeur
	virtual ~Medecin();

	//Méthodes
	void AjouterPatient(long id);

	void SupprimerPatient(long id);

	vector<long> getPatients() const;

private:

	vector<long> patients;

};

