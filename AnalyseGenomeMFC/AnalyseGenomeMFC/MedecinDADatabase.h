#pragma once
class MedecinDADatabase
{
public:
	MedecinDADatabase();
	~MedecinDADatabase();
};

#pragma once

#include <iostream>
#include <string>
#include "MedecinDA.h"
#include "sqlite3.h"

using namespace std;

class MedecinDADatabase : public MedecinDA
{
private:
	sqlite3 *database;

public:
	MedecinDADatabase();
	~MedecinDADatabase();

	void set_database(sqlite3 *database_in);


	int write_medecin(Medecin medecin);
	int read_medecin(Medecin &medecin, long id_in);
};