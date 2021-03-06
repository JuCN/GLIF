#include "stdafx.h"
#include "MedecinDADatabase.h"

MedecinDADatabase::MedecinDADatabase()
{
}

MedecinDADatabase::~MedecinDADatabase()
{
}

void MedecinDADatabase::set_database(sqlite3 *database_in)
{
	database = database_in;
}

int MedecinDADatabase::write_medecin(Medecin medecin)
{
	int code;
	char *error;
	string sqlInsertStr = "INSERT INTO Medecin VALUES('"
		+ to_string(medecin.getId()) + "', '"
		+ medecin.getNom() + "', '"
		+ medecin.getPrenom() + "', '"
		+ medecin.getMail()+ ", "+ medecin.getMdp()+ "');";

	const char *sqlInsert = sqlInsertStr.c_str();

	code = sqlite3_exec(database, sqlInsert, NULL, NULL, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 statement (write_medecin): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}

	return code;
}

int MedecinDADatabase::read_medecin(Medecin &Medecin, long id_in)
{
	int code;
	char *error;

	string sqlSelectStr = "SELECT * FROM Medecin WHERE id = '" + to_string(id_in) + "';";

	const char *sqlSelect = sqlSelectStr.c_str();

	char **results = NULL;
	int rows, columns;

	code = sqlite3_get_table(database, sqlSelect, &results, &rows, &columns, &error);

	if (code != 0)
	{
		cerr << "Error executing SQLite3 query (read_Medecin): " << sqlite3_errmsg(database) << endl;
		sqlite3_free(error);
	}
	else
	{
		Medecin.set_id(stol(results[0 + columns]));
		Medecin.setNom(results[1 + columns]);
		Medecin.setPrenom(results[2 + columns]);
		Medecin.setMail(results[3 + columns]);
		Medecin.setMdp(results[4 + columns]);
	}

	sqlite3_free_table(results);

	return code;
}
