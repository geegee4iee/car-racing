#include "ItemRegenLife.h"


CItemRegenLife::CItemRegenLife(void):CItem(0,'L')
{
}


CItemRegenLife::~CItemRegenLife(void)
{
}

int CItemRegenLife::GetType()
{
	return 3;
}

char CItemRegenLife::GetSkin()
{
	return Skin;
}
