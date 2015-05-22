#include "PlayerCar.h"


CPlayerCar::CPlayerCar(void)
{
}

CPlayerCar::CPlayerCar( int _life, int _pointmul,int _speed )
{
	Life=_life;
	PointMultiple=_pointmul;
	Speed=_speed;
}


CPlayerCar::~CPlayerCar(void)
{
}

int CPlayerCar::GetSpeed()
{
	return Speed;
}

int CPlayerCar::GetLife()
{
	return Life;
}

int CPlayerCar::Multiple()
{
	return PointMultiple;
}

void CPlayerCar::DecreaseLife( int _armor)
{
	Life-=_armor;
}

bool CPlayerCar::LifeIsOver()
{
	return (Life<=0);
}

void CPlayerCar::IncreaseLife( int _amount )
{
	Life+=_amount;
}


std::string CPlayerCar::getCarType()
{
	return "Unknown";
}

void CPlayerCar::CopyOutfit( CPlayerCar _anothercar )
{
	Trunk=_anothercar.Trunk;
	Hood=_anothercar.Hood;
	RoofCenter=_anothercar.RoofCenter;
	RoofSide=_anothercar.RoofSide;
	Wheel=_anothercar.Wheel;
}
