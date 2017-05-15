#include "stdafx.h"
#include "Medecin.h"



Medecin::Medecin(string nom, string prenom, string email, string mdp) : Utilisateur(nom, prenom, email, mdp)
{

}


Medecin::~Medecin()
{
}

void Medecin::AjouterPatient(long id)
{
	patients.push_back(id);
}

void Medecin::SupprimerPatient(long id) {
	int i = 0;
	for (long index : patients) {
		if (index == id) {
			patients.erase(patients.begin() + i);
			break;
		}
		i++;
	}
}

vector<long> Medecin::getPatients() const
{
	return patients;
}
