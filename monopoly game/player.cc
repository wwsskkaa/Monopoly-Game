#include "player.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


Player::Player(string name,char namechar,int rimcupsowned,int savings,int location,bool intimsline,int lineturn,Board *b)
{
	this->name=name;
	this->namechar=namechar;
	this->location=location;
	this->intimsline=intimsline;
	this->bankrupt=false;
	this->lineturn=lineturn;
	this->savings=savings;
	this->totalworth=savings;
	this->rimcupsowned=rimcupsowned;
	this->residencesowned=0;
	this->gymsowned=0;
	this->gb=b;
	this->currentsquare=NULL;	
    this->oweamount = 0;
   this->intimsline = intimsline;
    wincup = false;
}
Player::~Player(){
}


bool Player::getwincup(){
    return wincup;
}
void Player::setwincup(bool b){
    wincup = b;
}
int Player::getOweAmount(){
    return oweamount;
}

void Player::setOweAmount(int i){
    oweamount = i;
}

/*


First checks if change is negative or positive
if negative: need to check for bankruptcy
if positive: directly set to savings+change;
*/
void Player::changeSavings(const int change)
{
	int remain=savings+change;
    setTotalWorth(totalworth + change);
	if(change<0)
	{
		if(remain<0)
		{
			bankrupt=true;
			//cout<<"Player "<<name<<" BANKRUPT! "<<endl;
            oweamount = -remain;
            savings = 0;
		}
		else
		{
			savings=remain;
		}
	}
	else
	{
		savings=remain;
	}
}
bool Player::getTimsLine()const
{
    return intimsline;

}
void Player::setTimsline(const bool t)
{
    intimsline=t;
}
Square * Player::getcurrentsquare(){
    return currentsquare;
}
void Player::setcurrentsquare(Square * sq){
    currentsquare = sq;
}

string Player::getName()const
{
	return name;
}
void Player::setName(const string n)
{
	name=n;
}
char Player::getCharName()const
{
	return namechar;
}
void Player::setCharName(const char n)
{
	namechar=n;
}

void Player::setSavings(const int s)
{
	savings=s;
}

int Player::getSavings()const
{
	return savings;
}

void Player::setTotalWorth(const int t)
{
	totalworth=t;
}

int Player::getTotalWorth() const
{
	return totalworth;
}

void Player::setLocation(const int l)
{
	location=l;
}

int Player::getLocation() const
{
	return location;
}

void Player::setBankrupt(const bool b)
{
	bankrupt=b;
}

int Player::getRimCups()const
{
	return rimcupsowned;
}

void Player::setRimCups(const int c)
{
	rimcupsowned=c;
}

int Player::getResiamount()const
{
	return residencesowned;
}

void Player::setResiamount(const int r)
{
	residencesowned=r;
}

int Player::getGymamount()const
{
	return gymsowned;
}

void Player::setGymamount(const int g)
{
	gymsowned=g;
}

int Player::getLineturn()const
{
    return lineturn;
}

void Player::setLineturn(const int l)
{
    lineturn=l;
}
