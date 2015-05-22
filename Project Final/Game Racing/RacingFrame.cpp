#include "RacingFrame.h"


CRacingFrame::CRacingFrame(void)
{
	PlayerCar=NULL;
	Point=0;
}


CRacingFrame::~CRacingFrame(void)
{
	if (PlayerCar!=NULL)
	{
		delete PlayerCar;
		PlayerCar=NULL;
	}
	
}


void CRacingFrame::RunGame()
{
	system("CLS");
	CMapRacing::SetColor(1);
	cout<<"Choose car type to race:"<<endl;
	cout<<"1.Muscle car type"<<endl;
	cout<<"2.Sport car type"<<endl;
	cout<<"Your choice:";
	fflush(stdin);
	int choose;
	cin>>choose;
	while(choose!=1&&choose!=2){
		cout<<"Input Again:";
		cin>>choose;
	}
	if (choose==1)
	{
		PlayerCar=new CMuscleCar;
		
		if(AcceptChangeOutfit) PlayerCar->CopyOutfit(Temp_Player_Model);
	}
	if (choose==2)
	{
		PlayerCar=new CSportCar;
		if(AcceptChangeOutfit) PlayerCar->CopyOutfit(Temp_Player_Model);
	}
	/*EnemyCar[0].CustomizeOutFit('=','=','v','|','U');
	EnemyCar[1].CustomizeOutFit('=','=','x','|','M');
	EnemyCar[2].CustomizeOutFit('=','=','o','|','T');*/
	system("CLS");
	Map.RunMap(PlayerCar,EnemyCar,Point);
	Sleep(2000);
	system("CLS");
	CMapRacing::SetColor(0);
}



void CRacingFrame::CoreFrame()
{
	while(1){
	system("CLS");
	IntroScreen();
	cout<<"Input your choice:";
	int choice;
	cin>>choice;
	switch (choice)
	{

	case 1:
		{
		if(PlayerCar!=NULL) delete PlayerCar;
		PlayerCar=NULL;
		RunGame();
		system("CLS");
		char yes_no=' ';
		while(yes_no!='y'&&yes_no!='n'){
		fflush(stdin);
		cout<<"Do you want to save your record?(y/n):";
		cin>>yes_no;
		}
		
		if(yes_no=='y') {
			LoadRecord();
			string _Name;
			fflush(stdin);
			cout<<"Input your name:";
			getline(cin,_Name);
			CPlayer record_after_play(_Name,PlayerCar->getCarType(),Point);
			Player_Record.push_back(record_after_play);
			SortScore();
			SaveRecord();
		}
		if(yes_no=='n') {
			fflush(stdin);
			Sleep(500);
		}
		break;
		}
	case 2:
		{
			CMapRacing::SetColor(2);
		LoadRecord();
		ShowRecord();
		CMapRacing::SetColor(0);
		break;
		}
	case 3:
		{
			CMapRacing::SetColor(3);
		CustomCar();
		CMapRacing::SetColor(0);
		break;
		}
	case 4:
		break;
	default:
		{
		cout<<"Oopp! You got a wrong choice!";
		Sleep(500);
		break;
		}
	}
	if(choice==4) {
		system("CLS");
		cout<<"You was out of game";
		Sleep(500);
		break;
	}
	}

}

void CRacingFrame::LoadRecord()
{
	if(Player_Record.size()>0) Player_Record.resize(0);
	FileIn.open("Record.txt",ios_base::in);
	string temp;
	int temp_numb=0;
	getline(FileIn,temp);
	temp_numb=stoi(temp);
	for(int i=0;i<temp_numb;i++)
	{
		CPlayer temp_player_info;
		FileIn>>temp_player_info;
		bool Flag=true;
		for (unsigned i=0;i<Player_Record.size();i++)
		{
			if(!Player_Record[i].Different(temp_player_info)) Flag=false;
		}
		if(Flag)
			if(temp_player_info.getCarType()!="Unknown")
				Player_Record.push_back(temp_player_info);
	}
	FileIn.close();
}




void CRacingFrame::SaveRecord()
{
	FileOut.open("Record.txt",ios_base::out);
	FileOut<<Player_Record.size()<<endl;
	for (unsigned i=0;i<Player_Record.size();i++)
	{
		FileOut<<Player_Record[i];
	}
	FileOut.close();
}

void CRacingFrame::IntroScreen()
{
	CMapRacing::SetColor(1);
	for(int i=0;i<40;i++) cout<<"*";
	cout<<endl;
	cout<<"*";
	for (int i=0;i<14;i++) cout<<" ";
	cout<<"Racing Car";
	for(int i=0;i<14;i++) cout<<" ";
	cout<<"*"<<endl;
	for(int i=0;i<40;i++) cout<<"*";
	cout<<endl;
	CMapRacing::SetColor(1);
	cout<<"1.New game"<<endl;
	CMapRacing::SetColor(2);
	cout<<"2.See Record"<<endl;
	CMapRacing::SetColor(3);
	cout<<"3.Customize car"<<endl;
	CMapRacing::SetColor(4);
	cout<<"4.Exit game"<<endl;
	CMapRacing::SetColor(5);
	cout<<"Your last record:"<<Point<<" | Car Type:";
	if(PlayerCar==NULL) cout<<"Unknown"<<endl;
	else cout<<PlayerCar->getCarType()<<endl;
	CMapRacing::SetColor(0);
}

void CRacingFrame::CustomCar()
{
	system("CLS");
	cout<<"What is your custom car ?:"<<endl;
	cout<<"1.Enemy"<<endl;
	cout<<"2.Player"<<endl;
	fflush(stdin);
	int choose=0;
	while(choose!=1&&choose!=2){
		cout<<"Input your choice on overhead number:";
		cin>>choose;
	}
	if(choose==1){
		cout<<"There are three models of enemy car.\nThey set at same model at default."<<endl;
		cout<<"Model 1 - Model 2 - Model 3"<<endl;
		int choose2=0;
		while(choose2!=1&&choose2!=2&&choose2!=3){
			cout<<"Which model you want to choose?(number 1-3):";
			fflush(stdin);
			cin>>choose2;
		}
		if(choose2==1) EnemyCar[0].Input();
		if(choose2==2) EnemyCar[1].Input();
		if(choose2==3) EnemyCar[2].Input();
		Sleep(2000);
	}
	if(choose==2) {
		Temp_Player_Model.Input();
		AcceptChangeOutfit=true;
		Sleep(2000);
	}


}

void CRacingFrame::ShowRecord()
{
	system("CLS");
	for (unsigned i=0;i<Player_Record.size();i++)
	{
		if(i==0) CMapRacing::SetColor(1);
		cout<<i+1<<". ";
		Player_Record[i].OutputConsole();
		if(i==0) CMapRacing::SetColor(2);
		cout<<endl;
		
	}
	int press=0;
	while(press!=1){
	cout<<"If you want come back to Main Screen, press(1):";
	cin>>press;
	}
}

void CRacingFrame::SortScore()
{
	for (unsigned i=0;i<Player_Record.size()-1;i++)
		for(unsigned j=i+1;j<Player_Record.size();j++){
			if(Player_Record[i].getScore()<Player_Record[j].getScore()){
				CPlayer swap_temp=Player_Record[i];
				Player_Record[i]=Player_Record[j];
				Player_Record[j]=swap_temp;
			}
		}
}

bool CRacingFrame::AcceptChangeOutfit=false;


std::ifstream CRacingFrame::FileIn;

std::ofstream CRacingFrame::FileOut;

