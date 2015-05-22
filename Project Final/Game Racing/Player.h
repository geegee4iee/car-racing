#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#pragma once

class CPlayer
{

	string PlayerName;

	string CarType;

	int Score;

public:

	friend ofstream& operator<<(ofstream& _os,CPlayer& _player);

	friend ifstream& operator>>(ifstream& _is,CPlayer& _player);

	void OutputConsole();

	bool Different(CPlayer _another);

	void InputPlayerName(string _name);

	void InputCarType(string _cartype);

	void InputScore(int _score);

	int getScore();

	string getCarType();

	CPlayer(string _name,string _cartype,int _score);

	CPlayer(void);

	~CPlayer(void);

};

