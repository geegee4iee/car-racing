#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <cstdlib>
#include <iomanip>
#include <time.h>
//Own Header
#include "Car.h"
#include "Item.h"
#include "ItemBoostAura.h"
#include "ItemBoostPoint.h"
#include "ItemRegenLife.h"
#include "MuscleCar.h"
#include "SportCar.h"
#include "EnemyCar.h"
#include "Coord.h"

using namespace std;
#pragma once
class CMapRacing
{
	char MapBoard[25][25];
public:
	
	CMapRacing(void);
	~CMapRacing(void);

	//Set màu trên màn hình
	static inline void SetColor(const int& state);

	//In đường đua
	void PrintMap(
		int _point,
		int _state_item,
		int _time,
		CItem* _controller,
		CPlayerCar* _playercar,
		CCoord _pos_player
		);

	//Trả con trỏ về đầu dòng
	static inline void RefreshScreen();

	//Chạy đường đua
	void RunMap(CPlayerCar* playercar , CEnemyCar enemycar[],int& _point);

	//Điều chỉnh trạng thái vạch giữa
	void SetStateMap(int state);

	//Thêm xe vào đường đua
	void AddCar(CCar car,int posX,int posY);

	//Thêm vật phẩm hỗ trợ vào đường đua
	void AddItem(CItem* _item,int posX,int posY);

	//Điều khiển vị trí của xe người chơi
	void ControllerPosCar(int Direc,int& PosX,int& PosY,CCar car);

	//Kiểm tra đụng độ
	bool CheckCollision(const int& posx_player,const int& posy_player,const int& posx_enemy,const int& posy_enemy);

	//Kiểm tra ăn vật phẩm
	bool CheckEatItem(const int& posx_player,const int& posy_player,const int& posx_item,const int& posy_item);

	//Vẽ đụng độ
	void DrawCollision(int posX,int posY);

	//Làm map intro
	void PrintMapIntro();

	//Vẽ map đơn giản
	void PrintMapSimple();

	//Xóa xe
	void ClearCar(int posX,int posY);

};

