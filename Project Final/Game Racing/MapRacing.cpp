#include "MapRacing.h"
#include <assert.h>

CMapRacing::CMapRacing(void)
{
	for(int i=0; i < 20; i++)
	{
		for(int j=0; j < 20; j++)
		{
			MapBoard[i][j]=' ';
		}
	}
}


CMapRacing::~CMapRacing(void)
{
}



void CMapRacing::PrintMap(
	int _point,
	int _state_item,
	int _time,
	CItem* _controller,
	CPlayerCar* _playercar,
	CCoord _pos_player
	)
{
	SetColor(1);
	for(int i=0; i < 20; i++) 
	{
		for(int j=0; j < 20; j++) 
		{

				if(i==_pos_player.pos_x)
				{
					if (j==_pos_player.pos_y
						||j==_pos_player.pos_y+1
						||j==_pos_player.pos_y-1
						)
						SetColor(5);
					

				}else if (i==_pos_player.pos_x+1)
				{
					if (j==_pos_player.pos_y
						||j==_pos_player.pos_y+1
						||j==_pos_player.pos_y-1
						)
					SetColor(5);
				}else if(i==_pos_player.pos_x-1)
				{
					if (j==_pos_player.pos_y
						||j==_pos_player.pos_y+1
						||j==_pos_player.pos_y-1
						)
						SetColor(5);
					

				}
			cout << MapBoard[i][j];

			SetColor(1);

			if(j >= 19){

				if(i==0){
					SetColor(4);
					cout <<"\tPoint:"<<_point;
					SetColor(1);
				}

				if(i==2){
					SetColor(3);
					cout<<"\tItem status:";
					if(_state_item==0||_state_item==3) cout<<" No effect\t\t";
					if(_state_item==1) {
						cout<<"      Aura";
						if(_time>=10) cout <<" "<<_time<<"/"<<_controller->GetTime();
						else cout <<"  "<<_time<<"/"<<_controller->GetTime();
					}

					if(_state_item==2) {
						cout<<"  Multi x2";
						if(_time>=10) cout <<" "<<_time<<"/"<<_controller->GetTime();
						else cout <<"  "<<_time<<"/"<<_controller->GetTime();
					}
					SetColor(1);
				}

				if(i==4){
					SetColor(3);
					cout<<"\tSpeed of car:";
					if(_playercar->GetSpeed()<30) cout<<300-_playercar->GetSpeed();
					else cout<<300-(2*_playercar->GetSpeed());
					cout<<" Km/h";
					SetColor(1);
				}

				if(i==6) {
					SetColor(4);
					cout<<" Item 'L':The Recovery: adds 1 life";
					SetColor(1);
				}

				if(i==7) {
					SetColor(4);
					cout<<" Item 'O':The Immune Aura: in 80 frames";
					SetColor(1);
				}

				if(i==8) {
					SetColor(4);
					cout<<" Item 'X':The Multi-x2 point: in 70 frames";
					SetColor(1);
				}

				if(i==10){
					SetColor(4);
					cout<<"\tYour current multiple ->X";
					if(_state_item==2) cout<<_playercar->Multiple()*2;
					else cout<<_playercar->Multiple();
					SetColor(1);
				}
				cout << endl;

			}
			
		}
	}

	SetColor(2);
}

void CMapRacing::RefreshScreen()
{
	/*HANDLE hOut;*/
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void CMapRacing::RunMap(CPlayerCar *playercar,CEnemyCar enemycar[],int& _point)
{
	//Khởi tạo biến giữ ITEMS
	CItem** game_item=new CItem*[3];

	game_item[0]=new CItemBoostAura;
	game_item[1]=new CItemBoostPoint;
	game_item[2]=new CItemRegenLife;


	CItem *game_item_controller=NULL; //Biến điều khiển Item xuất hiện


	int state_item=0; //Biến giữ status của item



	game_item_controller=game_item[rand()%3]; //Random

	int RootLife=playercar->GetLife(); //HP Gốc
	int point=0; //Biến lưu điểm người chơi
	srand(time(0));
	int state=0;

	//Vị trí khởi tạo của vật phẩm hỗ trợ
	CCoord pos_item(0,rand()%15+2);

	//Vị trí mặc định của xe người chơi
	CCoord pos_player(16,9);

	//Vị trí khởi tạo của xe đối thủ
	CCoord pos_enemy1(1,rand()%15+2);
	CCoord pos_enemy2(1,rand()%15+2);
	CCoord pos_enemy3(1,rand()%15+2);
	//Khởi tạo 3 xe

	int step=0;
	//Sử dụng biến step để xác định thời điểm xe enemy xuất hiện

	int step_item=1;
	int step_item_state=rand()%30+100;
	//Sử dụng biến step_item để xác định thời điểm item xuất hiện và
	//biến step_item_state để giữ mốc step_item

	AddCar(*playercar,pos_player.pos_x,pos_player.pos_y);
	//Tạo xe người chơi đầu tiên
	AddCar(enemycar[0],pos_enemy1.pos_x,pos_enemy1.pos_y);
	//Tạo 1 xe enemy xuất ra đầu tiên

	int Time_Item_Out=0;

	PrintMapIntro();
	Sleep(100);


	while(1){


	if(state_item==1||state_item==2) Time_Item_Out++;
	if(step_item!=(step_item_state)) step_item++;
	if(step!=8) step++;

	Sleep(playercar->GetSpeed());
	SetStateMap(state);
	AddCar(*playercar,pos_player.pos_x,pos_player.pos_y);

	if(pos_enemy1.pos_x>=20) {
		pos_enemy1.pos_x=1;
		pos_enemy1.pos_y=rand()%15+2;
		point+=playercar->Multiple();
		if (state_item==2) point+=playercar->Multiple();
	}

	if(pos_enemy2.pos_x>=20) {
		pos_enemy2.pos_x=1;
		pos_enemy2.pos_y=rand()%15+2;
		point+=playercar->Multiple();
		if (state_item==2) point+=playercar->Multiple();
	}

	if(pos_enemy3.pos_x>=20) {
		pos_enemy3.pos_x=1;
		pos_enemy3.pos_y=rand()%15+2;
		point+=playercar->Multiple();
		if (state_item==2) point+=playercar->Multiple();
	}

	if(pos_item.pos_x>=20){
		pos_item.pos_x=1;
		pos_item.pos_y=rand()%15+2;
		step_item=0;
		step_item_state=rand()%30+100;
		game_item_controller=game_item[rand()%3];
	}


	
	if(state_item!=1){
	if (CheckCollision(pos_player.pos_x,pos_player.pos_y,pos_enemy1.pos_x,pos_enemy1.pos_y)) {
		DrawCollision(pos_player.pos_x,pos_player.pos_y);
		DrawCollision(pos_enemy1.pos_x,pos_enemy1.pos_y);
		playercar->DecreaseLife(enemycar[0].GetArmor());
	}

	if(CheckCollision(pos_player.pos_x,pos_player.pos_y,pos_enemy2.pos_x,pos_enemy2.pos_y)){
		DrawCollision(pos_player.pos_x,pos_player.pos_y);
		DrawCollision(pos_enemy2.pos_x,pos_enemy2.pos_y);
		playercar->DecreaseLife(enemycar[1].GetArmor());
	}

	if (CheckCollision(pos_player.pos_x,pos_player.pos_y,pos_enemy3.pos_x,pos_enemy3.pos_y)){
		DrawCollision(pos_player.pos_x,pos_player.pos_y);
		DrawCollision(pos_enemy3.pos_x,pos_enemy3.pos_y);
		playercar->DecreaseLife(enemycar[2].GetArmor());
	}
	}
	if(playercar->LifeIsOver()) break;

	if(CheckEatItem(pos_player.pos_x,pos_player.pos_y,pos_item.pos_x,pos_item.pos_y)){
		state_item=game_item_controller->GetType();
		if (state_item==3)
		{
			state_item=0;
			if(playercar->GetLife()<RootLife) playercar->IncreaseLife(1);
			game_item_controller=game_item[rand()%3];
		}
		
		step_item=0;
		step_item_state=rand()%30+100;
		pos_item.pos_x=1;
		pos_item.pos_y=rand()%15+2;
		
	}
	if(state_item==1)
		if (Time_Item_Out>game_item[0]->GetTime())
		{
			Time_Item_Out=0;
			state_item=0;
			step_item=0;
			step_item_state=rand()%30+100;
			pos_item.pos_x=1;
			pos_item.pos_y=rand()%15+2;
			game_item_controller=game_item[rand()%3];
		}
	if(state_item==2)
		if (Time_Item_Out>game_item[1]->GetTime())
		{
			Time_Item_Out=0;
			state_item=0;
			step_item=0;
			step_item_state=rand()%30+100;
			pos_item.pos_x=1;
			pos_item.pos_y=rand()%15+2;
			game_item_controller=game_item[rand()%3];
		}

	AddCar(enemycar[0],pos_enemy1.pos_x++,pos_enemy1.pos_y);
	if(step==8) AddCar(enemycar[1],pos_enemy2.pos_x++,pos_enemy2.pos_y);
	if(step>=4) AddCar(enemycar[2],pos_enemy3.pos_x++,pos_enemy3.pos_y);

	if(step_item==step_item_state){
		while(1){
			if (CheckEatItem(pos_enemy1.pos_x,pos_enemy1.pos_y,pos_item.pos_x,pos_item.pos_y)) 
				pos_item.pos_y=rand()%15+2;
			else if (CheckEatItem(pos_enemy2.pos_x,pos_enemy2.pos_y,pos_item.pos_x,pos_item.pos_y)) 
				pos_item.pos_y=rand()%15+2;
			else if (CheckEatItem(pos_enemy3.pos_x,pos_enemy3.pos_y,pos_item.pos_x,pos_item.pos_y)) 
				pos_item.pos_y=rand()%15+2;
			else {
				AddItem(game_item_controller,pos_item.pos_x++,pos_item.pos_y);
				break;
			}
		}
	}
	
	
	if(GetAsyncKeyState(VK_LEFT)){
		ControllerPosCar(4,pos_player.pos_x,pos_player.pos_y,*playercar);
	}
	if(GetAsyncKeyState(VK_RIGHT)){
		ControllerPosCar(6,pos_player.pos_x,pos_player.pos_y,*playercar);
	}
	if(GetAsyncKeyState(VK_DOWN)){
		ControllerPosCar(2,pos_player.pos_x,pos_player.pos_y,*playercar);
	}
	if(GetAsyncKeyState(VK_UP)){
		ControllerPosCar(8,pos_player.pos_x,pos_player.pos_y,*playercar);
	}
	

	

	PrintMap(
		point,
		state_item,
		Time_Item_Out,
		game_item_controller,
		playercar,
		pos_player
		);
	RefreshScreen();
	SetStateMap(state+1);
	if(state_item!=1){
	if (CheckCollision(pos_player.pos_x,pos_player.pos_y,pos_enemy1.pos_x,pos_enemy1.pos_y)) {
		DrawCollision(pos_player.pos_x,pos_player.pos_y);
		DrawCollision(pos_enemy1.pos_x,pos_enemy1.pos_y);
		playercar->DecreaseLife(enemycar[0].GetArmor());
	}
	if(CheckCollision(pos_player.pos_x,pos_player.pos_y,pos_enemy2.pos_x,pos_enemy2.pos_y)){
		DrawCollision(pos_player.pos_x,pos_player.pos_y);
		DrawCollision(pos_enemy2.pos_x,pos_enemy2.pos_y);
		playercar->DecreaseLife(enemycar[1].GetArmor());
	}
	if (CheckCollision(pos_player.pos_x,pos_player.pos_y,pos_enemy3.pos_x,pos_enemy3.pos_y)){
		DrawCollision(pos_player.pos_x,pos_player.pos_y);
		DrawCollision(pos_enemy3.pos_x,pos_enemy3.pos_y);
		playercar->DecreaseLife(enemycar[2].GetArmor());
	}
	}
	if(playercar->LifeIsOver()) break;
	

	AddCar(*playercar,pos_player.pos_x,pos_player.pos_y);
	AddCar(enemycar[0],pos_enemy1.pos_x++,pos_enemy1.pos_y);
	if(step==8) AddCar(enemycar[1],pos_enemy2.pos_x++,pos_enemy2.pos_y);
	if(step>=4) AddCar(enemycar[2],pos_enemy3.pos_x++,pos_enemy3.pos_y);

	if(step_item==step_item_state){
		while(1){
			if (CheckEatItem(pos_enemy1.pos_x,pos_enemy1.pos_y,pos_item.pos_x,pos_item.pos_y)) 
				pos_item.pos_y=rand()%15+2;
			else if (CheckEatItem(pos_enemy2.pos_x,pos_enemy2.pos_y,pos_item.pos_x,pos_item.pos_y)) 
				pos_item.pos_y=rand()%15+2;
			else if (CheckEatItem(pos_enemy3.pos_x,pos_enemy3.pos_y,pos_item.pos_x,pos_item.pos_y)) 
				pos_item.pos_y=rand()%15+2;
			else {
				AddItem(game_item_controller,pos_item.pos_x++,pos_item.pos_y);
				break;
			}
		}
	}
	
	

	if(GetAsyncKeyState(VK_LEFT)){
		ControllerPosCar(4,pos_player.pos_x,pos_player.pos_y,*playercar);
	}
	if(GetAsyncKeyState(VK_RIGHT)){
		ControllerPosCar(6,pos_player.pos_x,pos_player.pos_y,*playercar);
	}
	if(GetAsyncKeyState(VK_DOWN)){
		ControllerPosCar(2,pos_player.pos_x,pos_player.pos_y,*playercar);
	}
	if(GetAsyncKeyState(VK_UP)){
		ControllerPosCar(8,pos_player.pos_x,pos_player.pos_y,*playercar);
	}

	Sleep(playercar->GetSpeed());

	PrintMap(
		point,
		state_item,
		Time_Item_Out,
		game_item_controller,
		playercar,
		pos_player
		);
	//Tạo biến tạm để chứa số lượng máu còn lại của người chơi
	SetColor(4);
	int temp=playercar->GetLife();
	cout<<"Health:";
	for (int i=0;i<RootLife;i++)
	{
		if (temp-->0) wcout<<L"Ü";
		else cout<<" ";
		
	}
	cout<<" "<<(playercar->GetLife())<<"/"<<RootLife<<endl;
	SetColor(1);
	RefreshScreen();
	}
	system("CLS");
	_point=point;
	PrintMap(
		point,
		state_item,
		Time_Item_Out,
		game_item_controller,
		playercar,
		pos_player
	);
	RefreshScreen();
	SetColor(1);
	cout<<"\n\n\n\n\n\n\n\n\n|    Game over"<<endl;
	SetColor(0);
	delete []game_item;
	delete game_item_controller;
}


void CMapRacing::SetStateMap(int state)
{
	for(int i=0; i < 20; i++)
	{
		for(int j=0; j < 20; j++)
		{
			if (i%2==state%2)
			{
				MapBoard[i][0] = '|'; //Cột 0
				MapBoard[i][18] = '|'; //Cột cuối cùng
				MapBoard[i][9]='|';
				MapBoard[i][j] = ' '; //Khoảng trắng
			}
			else
			{
				MapBoard[i][0] = '|'; //Cột 0
				MapBoard[i][18] = '|'; //Cột cuối cùng
				MapBoard[i][9]=' ';
				MapBoard[i][j] = ' '; //Khoảng trắng
			}
		}
	}
}

void CMapRacing::AddCar(CCar car,int posX,int posY )
{
	MapBoard[posX][posY] = car.getCenterRoof();
	MapBoard[posX][posY+1] = car.getSideRoof();
	MapBoard[posX][posY-1] = MapBoard[posX][posY+1];
	MapBoard[posX-1][posY]=car.getHood();
	MapBoard[posX+1][posY]=car.getTrunk();
	MapBoard[posX+1][posY-1] = car.getWheel();
	MapBoard[posX+1][posY+1] = MapBoard[posX+1][posY-1];
	MapBoard[posX-1][posY-1] = MapBoard[posX+1][posY-1];
	MapBoard[posX-1][posY+1] = MapBoard[posX+1][posY-1];
	//char Shadow='.';
	//MapBoard[posX+2][posY]=Shadow;
	//MapBoard[posX+2][posY+1]=Shadow;
	//MapBoard[posX+2][posY+2]=Shadow;
	//MapBoard[posX][posY+2]=Shadow;
	//MapBoard[posX+1][posY+2]=Shadow;
}

void CMapRacing::ClearCar( int posX,int posY )
{
	char clearspace=' ';
	MapBoard[posX][posY] = clearspace;
	MapBoard[posX][posY+1] = clearspace;
	MapBoard[posX][posY-1] = clearspace;
	MapBoard[posX-1][posY]=clearspace;
	MapBoard[posX+1][posY]=clearspace;
	MapBoard[posX+1][posY-1] = clearspace;
	MapBoard[posX+1][posY+1] = clearspace;
	MapBoard[posX-1][posY-1] = clearspace;
	MapBoard[posX-1][posY+1] = clearspace;
}



void CMapRacing::ControllerPosCar( int Direc,int& PosX,int& PosY ,CCar car)
{
	if(Direc==4){
		if (PosY==2)
		{
			return;
		}
		ClearCar(PosX,PosY);
		AddCar(car,PosX,--PosY);
	}
	if(Direc==6){
		if (PosY==16)
		{
			return;
		}
		ClearCar(PosX,PosY);
		AddCar(car,PosX,++PosY);
	}
	if(Direc==2){
		if (PosX==18)
		{
			return;
		}
		ClearCar(PosX,PosY);
		AddCar(car,++PosX,PosY);
	}
	if(Direc==8){
		if (PosX==1)
		{
			return;
		}
		ClearCar(PosX,PosY);
		AddCar(car,--PosX,PosY);
	}
}

bool CMapRacing::CheckCollision(const int& posx_player,const int& posy_player,const int& posx_enemy,const int& posy_enemy )
{
	int Top_X_Player=posx_player-1;
	int Left_Y_Player=posy_player-1;
	int Right_Y_Player=posy_player+1;
	int Bot_X_Player=posx_player+1;

	int Top_X_Enemy=posx_enemy-1;
	int Left_Y_Enemy=posy_enemy-1;
	int Right_Y_Enemy=posy_enemy+1;
	int Bot_X_Enemy=posx_enemy+1;

	if (Top_X_Player==posx_enemy){
		if (posy_player==Right_Y_Enemy) return true;
		else if(posy_player==Left_Y_Enemy) return true;
		else if(posy_player==posy_enemy) return true;
		else if(Left_Y_Player==Right_Y_Enemy) return true;
		else if(Right_Y_Player==Left_Y_Enemy) return true;
		}
	if(Bot_X_Player==Top_X_Enemy){
		if (posy_player==Right_Y_Enemy) return true;
		else if(Left_Y_Player==Right_Y_Enemy) return true;
		else if(Right_Y_Player==Left_Y_Enemy) return true;
		else if(posy_player==posy_enemy) return true;
		else if(Left_Y_Player==posy_enemy) return true;
		else if(Right_Y_Player==posy_enemy) return true;
	}
	return false;
	//else if (Top_X_Player==Top_X_Enemy){
	//	if (posy_player==Right_Y_Enemy) return true;
	//	else if(posy_player==Left_Y_Enemy) return true;
	//	else if(posy_player==posy_enemy) return true;
	//	else if(Left_Y_Player==Right_Y_Enemy) return true;
	//	else if(Right_Y_Player==Left_Y_Enemy) return true;
	//}
	
}


void CMapRacing::AddItem( CItem* _item,int posX,int posY )
{
	assert(posX<=20);
	MapBoard[posX][posY]=_item->GetSkin();
}





void CMapRacing::DrawCollision( int posX,int posY )
{
	char clearspace='@';
	MapBoard[posX+2][posY-2] = clearspace;
	MapBoard[posX+2][posY+2] = clearspace;
	MapBoard[posX-2][posY-2] = clearspace;
	MapBoard[posX-2][posY+2] = clearspace;
	MapBoard[posX+2][posY] = clearspace;
	MapBoard[posX-2][posY] = clearspace;
	MapBoard[posX][posY+2] = clearspace;
	MapBoard[posX][posY-2] = clearspace;

}

bool CMapRacing::CheckEatItem(const  int& posx_player,const int& posy_player,const int& posx_item,const int& posy_item )
{
	int Top_X_Player=posx_player-1;
	int Left_Y_Player=posy_player-1;
	int Right_Y_Player=posy_player+1;
	int Bot_X_Player=posx_player+1;
	if (Top_X_Player==posx_item)
	{
		if(Left_Y_Player==posy_item) return true;
		if(Right_Y_Player==posy_item) return true;
		if(posy_player==posy_item) return true;
	}
	if(posx_player==posx_item){
		if(Left_Y_Player==posy_item) return true;
		if(Right_Y_Player==posy_item) return true;
		if(posy_player==posy_item) return true;
	}
	if(Bot_X_Player==posx_item){
		if(Left_Y_Player==posy_item) return true;
		if(Right_Y_Player==posy_item) return true;
		if(posy_player==posy_item) return true;
	}
	return false;
}

void CMapRacing::PrintMapIntro()
{
	for(int i=3;i>=0;i--)
	{
		SetStateMap(i%2);
		if(i==3) MapBoard[9][9]='3';
		if(i==2) MapBoard[9][9]='2';
		if(i==1) MapBoard[9][9]='1';
		if (i==0)
		{
			MapBoard[9][7]='R';
			MapBoard[9][8]='e';
			MapBoard[9][9]='a';
			MapBoard[9][10]='d';
			MapBoard[9][11]='y';
		}
		SetColor(i);
		PrintMapSimple();
		RefreshScreen();
		Sleep(1000);
	}
	SetColor(1);
}

void CMapRacing::PrintMapSimple()
{
	for(int i=0; i < 20; i++) 
	{
		for(int j=0; j < 20; j++) 
		{
			cout << MapBoard[i][j];
			if(j >= 19) cout << endl;
		}
	}
}

void CMapRacing::SetColor(const  int& state )
{
	/*HANDLE hOut;*/
	HANDLE hOut;
	hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if(state==1) SetConsoleTextAttribute( hOut, 0x0C );//Red
	if(state==0) SetConsoleTextAttribute( hOut, 0x07 );//White
	if(state==2) SetConsoleTextAttribute( hOut, 0x02 );
	if(state==3) SetConsoleTextAttribute( hOut, 0x06 );
	if(state==4) SetConsoleTextAttribute( hOut, 0x0A );
	if(state==5) SetConsoleTextAttribute( hOut, 0x0B );
}

