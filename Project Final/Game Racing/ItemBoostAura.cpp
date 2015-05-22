#include "ItemBoostAura.h"


CItemBoostAura::CItemBoostAura(void):CItem(80,'O')
{

}


CItemBoostAura::~CItemBoostAura(void)
{
}

char CItemBoostAura::GetSkin()
{
	return Skin;
}

int CItemBoostAura::GetType()
{
	return 1;
}
