#include "Car.h"


CCar::CCar(void)
{
	Trunk='=';
	Wheel='o';
	Hood='=';
	RoofSide='i';
	RoofCenter='H';
}

CCar::CCar( char _trunk,char _hood,char _wheel,char _sideroof,char _centroof )
{
	Trunk=_trunk;
	Wheel=_wheel;
	Hood=_hood;
	RoofSide=_sideroof;
	RoofCenter=_centroof;
}


CCar::~CCar(void)
{
}

char CCar::getTrunk()
{
	return Trunk;
}

char CCar::getHood()
{
	return Hood;
}

char CCar::getWheel()
{
	return Wheel;
}

char CCar::getSideRoof()
{
	return RoofSide;
}

char CCar::getCenterRoof()
{
	return RoofCenter;
}

void CCar::Input()
{
	cout << "Custom your Wheel:";
	cin>>Wheel;
	cout<<"Custom your Hood:";
	cin>>Hood;
	cout<<"Custom your Roof Side:";
	cin>>RoofSide;
	cout<<"Custom your Roof Center:";
	cin >>RoofCenter;
	cout <<"Custom your Trunk:";
	cin>>Trunk;
	cout <<"Your new car:"<<endl;
	cout <<Wheel<<Hood<<Wheel<<endl;
	cout <<RoofSide<<RoofCenter<<RoofSide<<endl;
	cout <<Wheel<<Trunk<<Wheel<<endl;
}
void CCar::CustomizeOutFit( char _trunk,char _hood,char _wheel,char _sideroof,char _centroof )
{
	Trunk=_trunk;
	Wheel=_wheel;
	Hood=_hood;
	RoofSide=_sideroof;
	RoofCenter=_centroof;
}

