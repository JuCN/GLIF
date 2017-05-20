#pragma once

#include "Maladie.h"

class MaladieDA
{
public:
	virtual int write_maladie(Maladie maladie) = 0;
	virtual int read_maladie(Maladie &maladie, long id_in) = 0;
};