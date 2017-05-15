#pragma once
#include <string>

using namespace std;

class Utilisateur
{
public:

	//Constructeur
	Utilisateur(string nom, string prenom, string email, string mdp);

	// geteurs et seteurs

	long getId() const;

	string getNom() const;

	string getPrenom() const;

	string getMail() const;

	string getMdp() const;

	int getStatut() const;

	void setNom(string n);

	void setPrenom(string p);

	void setMail(string m);

	void setMdp(string mdp);

	void setStatut(int statut);

	virtual ~Utilisateur();

private:

	static long Id_;
	long id;
	string nom;
	string prenom;
	string mail;
	string mdp;
	int statut;

};

