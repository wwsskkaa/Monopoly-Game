#include "needleshall.h"
#include "player.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

NeedlesHall::NeedlesHall(string name): UnownableProperty(name)
{}

NeedlesHall::~NeedlesHall()
{}

void NeedlesHall::action(Player& player)
{
	cout<<player.getName()<<": You are currently in Needles Hall."<<endl;
	int r = rand() % 100;//returns a number from 0-99
	if(r==50)//1% chance
	{
	//quest all players for their rim cup amount, add them together
        cout<<"You win a roll up and rim cups"<<endl;
        player.setwincup(true);
        int c = player.getRimCups();
        player.setRimCups(c+1);
	}

	int p = rand() % 18;   // p in the range 0-17 
	int charge=0;
	if(p==0)
	{
		charge-=200;
	}
	else if(p>0&&p<=2)
	{
		charge-=100;
	}
	else if(p>2&&p<=5)
	{
		charge-=50;
	}
	else if(p>5&&p<=11)
	{
		charge=25;
	}
	else if(p>11&&p<=14)
	{
		charge=50;
	}
	else if(p>14&&p<=16)
	{
		charge=100;
	}
	else if(p==17)
	{
		charge=200;
	}
	player.changeSavings(charge);
	//ostringstream ss;
	//ss<<charge;
	cout<<"Player "<<player.getName()<<"'s savings "<<charge<<"."<<endl;
}

