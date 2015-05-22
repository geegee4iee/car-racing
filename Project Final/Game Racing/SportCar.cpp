#include "SportCar.h"


CSportCar::CSportCar(void):CPlayerCar(3,5,15)
{
	this->CustomizeOutFit('_','^','o','|','Y');
}


CSportCar::~CSportCar(void)
{
}

std::string CSportCar::getCarType()
{
	return "Sport car";
}
