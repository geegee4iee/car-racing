#include "Player.h"


CPlayer::CPlayer(void)
{
	PlayerName="Unkhown";
	Score=0;
	CarType="Unknown";
}

CPlayer::CPlayer( string _name,string _cartype,int _score )
{
	PlayerName=_name;
	CarType=_cartype;
	Score=_score;
}


CPlayer::~CPlayer(void)
{
}

void CPlayer::InputPlayerName( string _name )
{
	PlayerName=_name;
}

void CPlayer::InputCarType( string _cartype )
{
	CarType=_cartype;
}

void CPlayer::InputScore( int _score )
{
	Score=_score;
}

bool CPlayer::Different( CPlayer _another )
{
	if(PlayerName!=_another.PlayerName) return true;
	else if(CarType!=_another.CarType) return true;
	else if(Score!=_another.Score) return true;
	else return false;
}

int CPlayer::getScore()
{
	return Score;
}

std::string CPlayer::getCarType()
{
	return CarType;
}

void CPlayer::OutputConsole()
{
	cout<<PlayerName<<",";
	cout<<CarType<<",";
	cout<<Score<<endl;
}


ifstream& operator>>(ifstream& _is,CPlayer& _player){
	getline(_is,_player.PlayerName,',');
	getline(_is,_player.CarType,',');
	string temp_get_score;
	getline(_is,temp_get_score);
	_player.Score=stoi(temp_get_score);
	return _is;
}
//ostream& operator<<(ostream& _os,CPlayer& _player){
//	_os<<_player.PlayerName<<" "<<_player.CarType<<" "<<_player.Score<<endl;
//	return _os;
//}
ofstream& operator<<(ofstream& _os,CPlayer& _player){
	_os<<_player.PlayerName<<",";
	_os<<_player.CarType<<",";
	_os<<_player.Score<<endl;
	return _os;
}
