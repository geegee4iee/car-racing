#include <iostream>
using namespace std;
#pragma once

//Class chứa thông tin về xe của game

class CCar
{
protected:

	char Trunk;

	char RoofCenter;

	char RoofSide;

	char Hood;

	char Wheel;

public:

	CCar(char _trunk,char _hood,char _wheel,char _sideroof,char _centroof);

	void CustomizeOutFit(char _trunk,char _hood,char _wheel,char _sideroof,char _centroof);

	void Input();

	char getTrunk();

	char getHood();

	char getWheel();

	char getSideRoof();

	char getCenterRoof();

	CCar(void);

	~CCar(void);
};

