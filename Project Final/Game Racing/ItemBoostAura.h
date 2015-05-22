//Item tạo vòng bảo vệ giúp xe người chơi không bị tổn hại

#pragma once
#include "item.h"
class CItemBoostAura :
	public CItem
{
public:

	virtual char GetSkin();

	virtual int GetType();

	CItemBoostAura(void);

	~CItemBoostAura(void);
};

