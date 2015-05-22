//Item x2 điểm đạt được

#pragma once
#include "Item.h"
class CItemBoostPoint:public CItem
{
public:

	virtual char GetSkin();

	virtual int GetType();

	CItemBoostPoint(void);

	~CItemBoostPoint(void);

};

