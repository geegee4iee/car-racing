#include "MuscleCar.h"


CMuscleCar::CMuscleCar(void):CPlayerCar(5,2,20)
{
	this->CustomizeOutFit('X','=','o',':','V');
}


CMuscleCar::~CMuscleCar(void)
{
}

std::string CMuscleCar::getCarType()
{
	return "Muscle car";
}
