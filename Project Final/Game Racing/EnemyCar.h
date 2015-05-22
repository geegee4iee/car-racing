#pragma once
#include "car.h"
class CEnemyCar :
	public CCar
{
	int Armor;

public:

	CEnemyCar(int _armor);

	int GetArmor();

	CEnemyCar(void);

	~CEnemyCar(void);

};

