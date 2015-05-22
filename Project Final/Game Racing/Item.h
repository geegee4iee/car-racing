#pragma once

/* Class xây dựng hệ thống item hỗ trợ trong game */

class CItem
{
protected:

	int Time;

	char Skin;

public:

	CItem(void);

	CItem(int _time,char _skin);

	virtual char GetSkin();

	virtual int GetType();

	virtual int GetTime();

	~CItem(void);
};

