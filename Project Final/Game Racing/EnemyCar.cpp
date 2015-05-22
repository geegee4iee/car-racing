#include "EnemyCar.h"


CEnemyCar::CEnemyCar(void)
{
	Armor=2;
}

CEnemyCar::CEnemyCar( int _armor )
{
	Armor=_armor;
}


CEnemyCar::~CEnemyCar(void)
{
}

int CEnemyCar::GetArmor()
{
	return Armor;
}




