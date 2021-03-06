#pragma once
class MaladieDADatabase
{
public:
	MaladieDADatabase();
	~MaladieDADatabase();
};

#pragma once

#include <iostream>
#include <string>
#include "MaladieDA.h"
#include "sqlite3.h"

using namespace std;

class MaladieDADatabase : public MaladieDA
{
private:
	sqlite3 *database;

public:
	MaladieDADatabase();
	~MaladieDADatabase();

	void set_database(sqlite3 *database_in);


	int write_maladie(Maladie maladie);
	int read_maladie(Maladie &maladie, long id_in);
};
