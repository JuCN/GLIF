#include "stdafx.h"
#include "Utilisateur.h"


long Utilisateur::Id_ = 0;

Utilisateur::Utilisateur(string nom, string prenom, string email, string mdp)
{
	this->id = Id_++;
	this->nom = nom;
	this->prenom = prenom;
	this->mail = email;
	this->mdp = mdp;
	this->statut = 0;
}

long Utilisateur::getId() const
{
	return id;
}
string Utilisateur::getNom() const
{
	return nom;
}

string Utilisateur::getPrenom() const
{
	return prenom;
}

string Utilisateur::getMail() const
{
	return mail;
}

string Utilisateur::getMdp() const
{
	return mdp;
}

int Utilisateur::getStatut() const
{
	return statut;
}

void Utilisateur::setNom(string n)
{
	nom = n;
}

void Utilisateur::setPrenom(string p)
{
	prenom = p;
}

void Utilisateur::setMail(string m)
{
	mail = m;
}

void Utilisateur::setMdp(string mdp)
{
	this->mdp = mdp;
}

void Utilisateur::setStatut(int statut) {
	this->statut = statut;
}

Utilisateur::~Utilisateur()
{
}
