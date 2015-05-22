#pragma once
#include "playercar.h"
class CMuscleCar :
	public CPlayerCar
{
public:

	virtual string getCarType();

	CMuscleCar(void);

	~CMuscleCar(void);
};

