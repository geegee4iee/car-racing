#pragma once
#include "car.h"
#include <string>
class CPlayerCar :
	public CCar
{

protected:

	int Life;

	int PointMultiple;

	int Speed;

public:

	CPlayerCar(void);

	void CopyOutfit(CPlayerCar _anothercar);

	virtual string getCarType();

	int GetSpeed();

	int GetLife();

	int Multiple();

	void DecreaseLife(int _armor);

	bool LifeIsOver();

	void IncreaseLife(int _amount);

	CPlayerCar(int _life, int _pointmul,int _speed);

	~CPlayerCar(void);
};

