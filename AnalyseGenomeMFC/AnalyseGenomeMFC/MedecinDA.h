#pragma once

#include "Medecin.h"

class MedecinDA
{
public:
	virtual int write_medecin(Medecin medecin) = 0;
	virtual int read_medecin(Medecin &medecin, long id_in) = 0;
};

