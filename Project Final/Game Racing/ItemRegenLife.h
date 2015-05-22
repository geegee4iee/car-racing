//Item giúp hồi phục 1 life cho người chơi

#pragma once
#include "item.h"
class CItemRegenLife :
	public CItem
{
public:

	virtual int GetType();

	virtual char GetSkin();

	CItemRegenLife(void);

	~CItemRegenLife(void);
};

