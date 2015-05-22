#include "Item.h"


CItem::CItem(void)
{
	Time=0;
	Skin='?';
}

CItem::CItem( int _time,char _skin )
{
	Time=_time;
	Skin=_skin;
}


CItem::~CItem(void)
{
}

char CItem::GetSkin()
{
	return Skin;
}

int CItem::GetType()
{
	return 0;
}

int CItem::GetTime()
{
	return Time;
}
