#include <fstream>
#include <vector>
#include "Car.h"
#include "MapRacing.h"
#include "Item.h"
#include "ItemBoostAura.h"
#include "ItemBoostPoint.h"
#include "ItemRegenLife.h"
#include "MuscleCar.h"
#include "SportCar.h"
#include "EnemyCar.h"
#include "Player.h"
#include <conio.h>


/* Khung chính của game để chứa các thành phần map,car,point,vv người chơi thao tác với menu
lựa chọn */


using namespace std;
#pragma once
class CRacingFrame
{

	static bool AcceptChangeOutfit;

	vector<CPlayer> Player_Record;

	int Point;

	CEnemyCar EnemyCar[3];

	CPlayerCar Temp_Player_Model;

	CPlayerCar *PlayerCar;

	CMapRacing Map;

public:

	//Biến đọc file
	static ifstream FileIn;

	//Biến ghi file
	static ofstream FileOut;

	//Lưu điểm của người chơi
	void SaveRecord();

	//In ra điểm của người chơi
	void ShowRecord();

	//Lấy dữ liệu điểm
	void LoadRecord();

	//Khung chính của game
	void CoreFrame();

	//Chạy game
	void RunGame();

	//Màn hình menu
	void IntroScreen();

	//Chỉnh sửa ngoại hình của xe
	void CustomCar();

	//Sắp xếp điểm
	void SortScore();

	CRacingFrame(void);

	~CRacingFrame(void);

};

