#include "ItemBoostPoint.h"


CItemBoostPoint::CItemBoostPoint(void):CItem(70,'X')
{
}


CItemBoostPoint::~CItemBoostPoint(void)
{
}

char CItemBoostPoint::GetSkin()
{
	return Skin;
}

int CItemBoostPoint::GetType()
{
	return 2;
}
