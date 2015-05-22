#pragma once
#include "playercar.h"
class CSportCar :
	public CPlayerCar
{
public:

	virtual string getCarType();

	CSportCar(void);

	~CSportCar(void);
};

