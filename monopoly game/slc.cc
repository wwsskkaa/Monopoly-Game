#include "slc.h"
#include "player.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

Slc::Slc(string name): UnownableProperty(name)
{}

Slc::~Slc()
{}

void Slc::action(Player& currentplayer)
{
        cout<<currentplayer.getName()<<": You are currently in SLC."<<endl;
int r = rand() % 100;//returns a number from 0-99
if(r==50)//1% chance
{
    cout<<"You win a roll up and rim cups"<<endl;
    currentplayer.setwincup(true);
    int c = currentplayer.getRimCups();
    currentplayer.setRimCups(c+1);
}

int ploc=currentplayer.getLocation();

int p = rand() % 24;   // p in the range 0-23 
if(p==0)
{
	ploc = 10;
	cout<<"Player "<<currentplayer.getName()<<" moved to DC Tims Line."<<endl;
    currentplayer.setwincup(false);
}
else if(p==1)
{
    ploc = 0;
	cout<<"Player "<<currentplayer.getName()<<" advanced to collect OSAP."<<endl;
    currentplayer.setwincup(false);
}
else if(p>1&&p<=4)
{
	ploc-=3;
	cout<<"Player "<<currentplayer.getName()<<" stepped back 3 times."<<endl;
    currentplayer.setwincup(false);
}
else if(p>4&&p<=8)
{
	ploc-=2;
	cout<<"Player "<<currentplayer.getName()<<" stepped back 2 times."<<endl;
    currentplayer.setwincup(false);
}
else if(p>8&&p<=12)
{
	ploc--;
	cout<<"Player "<<currentplayer.getName()<<" stepped back 1 time."<<endl;
    currentplayer.setwincup(false);
}
else if(p>12&&p<=15)
{
	ploc++;
	cout<<"Player "<<currentplayer.getName()<<" stepped forward 1 time."<<endl;
    currentplayer.setwincup(false);
}
else if(p>15&&p<=19)
{
	ploc+=2;
	cout<<"Player "<<currentplayer.getName()<<" stepped forward 2 times."<<endl;
    currentplayer.setwincup(false);
}
else //19<p<=23
{
	ploc+=3;
	cout<<"Player "<<currentplayer.getName()<<" stepped forward 3 times."<<endl;
    currentplayer.setwincup(false);
}
if(ploc<0)
{
	ploc+=40;//handling going back on the SLCBOTTOM
}

currentplayer.setLocation(ploc);
}

