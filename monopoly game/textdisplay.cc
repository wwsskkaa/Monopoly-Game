#include <iostream>
#include <string>
#include <map>
#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay() {}
TextDisplay::~TextDisplay(){}

void TextDisplay::notifyRemove(string name)
{
	playerloc.erase(name);
}
void TextDisplay::drawBeginning()
{
cout<<"                          _______       "<<endl;
cout<<"                         /\\ o o o\\"<<endl;
cout<<"                        /o \\ o o o\\_______"<<endl;
cout<<"                       <    >------>    O /|"<<endl;
cout<<"                        \\ o/  O   /_____/o|"<<endl;
cout<<"                         \\/______/   O |oo|"<<endl;
cout<<"                                |   O   |o/"<<endl;
cout<<"                                |_O_____|/"<<endl;
cout<<"                                                               .---."<<endl;
cout<<"                                                              /  .  \\"<<endl;
cout<<"                                                             |\\_/|   |"<<endl;
cout<<"                                                             |   |  /|"<<endl;
cout<<"   ________________________________________________________________' |"<<endl;
cout<<" /  .-.                                                              |"<<endl;
cout<<"|  /   \\                                                             |"<<endl;
cout<<"| |\\_.  |            WELCOME TO BUILDING BUYER 7K!                   |"<<endl;
cout<<"|\\|  | /|                                                            |"<<endl;
cout<<"| `---' |                ALBERT LIU & SHUANG WU                      |"<<endl;
cout<<"|       |                                                            |"<<endl;
cout<<"|       |                                                           /"<<endl;
cout<<"|       |_________________________________________________________ /"<<endl;
cout<<"\\       |"<<endl;
cout<<" \\     /"<<endl;
cout<<"  \\__/"<<endl;
/*	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
	cout<<""<<endl;
	cout<<"                              .^^.    .^^,                   "<<endl;
	cout<<"                              |  |   /  /                   "<<endl;
	cout<<"                              |  |  /  /                   "<<endl;
	cout<<"                              |  | /  /                   "<<endl;
	cout<<"                              |   V  ;-._                    "<<endl;
	cout<<"                              |  ` _/  / ;                   "<<endl;
	cout<<"                              |  /` ) /  /                   "<<endl;
	cout<<"                              | /  /_/\\_/\\                   "<<endl;
	cout<<"                              |/  /      |                   "<<endl;
	cout<<"                              (  ' \\ '-  |                   "<<endl;
	cout<<"                               \\    `.  /                   "<<endl;
	cout<<"                                |      |                   "<<endl;
	cout<<"                                |      |                   "<<endl;
	cout<<"                            Welcome to BB7K!!                   "<<endl;
	cout<<""<<endl;
*///	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
}


void TextDisplay::drawEnding(string player)
{
cout<<endl<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
cout<<"$                _-----__-------__-========-________-============-__"<<endl;
cout<<"$              _(                                                      _)"<<endl;
cout<<"$           oo(          Congrats to the winner: "<<player<<" !           )_"<<endl;
cout<<"$          0  (_                    $GAME OVER$                    _)"<<endl;
cout<<"$        Oo     (_                                                _)"<<endl;
cout<<"$       o         '=-___-===-_______-========-_____________-===-----)'"<<endl;
cout<<"$     o0"<<endl;
cout<<"$    o ______          ______________   ___________      _______"<<endl;
cout<<"$  _()_||__|| ------   |   q64liu   |   |_________|   __||___||__"<<endl;
cout<<"$ (CS 246 15| |     |  |   s275wu   | __|______||_|  |____________|"<<endl;
cout<<"$/-OO----OO''-'OO--OO'='OO---------OO'='OO-------OO'= 'OO-------OO'\\"<<endl;
cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
}

void TextDisplay::drawdice(int n)
{
if(n==1)
{
cout<<"--------"<<endl;
cout<<"|      |"<<endl;
cout<<"|  $   |"<<endl;
cout<<"|      |"<<endl;
cout<<"--------"<<endl;
}
else if(n==2)
{
cout<<"--------"<<endl;
cout<<"|    $ |"<<endl;
cout<<"|      |"<<endl;
cout<<"| $    |"<<endl;
cout<<"--------"<<endl;
}
else if(n==3)
{
cout<<"--------"<<endl;
cout<<"|    $ |"<<endl;
cout<<"|  $   |"<<endl;
cout<<"|$     |"<<endl;
cout<<"--------"<<endl;
}
else if(n==4)
{
cout<<"--------"<<endl;
cout<<"| $  $ |"<<endl;
cout<<"|      |"<<endl;
cout<<"| $  $ |"<<endl;
cout<<"--------"<<endl;
}
else if(n==5)
{
cout<<"--------"<<endl;
cout<<"| $ $  |"<<endl;
cout<<"|  $   |"<<endl;
cout<<"| $ $  |"<<endl;
cout<<"--------"<<endl;
}
else if(n==6)
{
cout<<"--------"<<endl;
cout<<"| $  $ |"<<endl;
cout<<"| $  $ |"<<endl;
cout<<"| $  $ |"<<endl;
cout<<"--------"<<endl;
}
}

void TextDisplay::notify(string buildingname, int improve)
{
    improveprogress [buildingname]=improve;
}

void TextDisplay::notify(string playername, string currentloc)
{
    playerloc[playername] =currentloc;
}

string TextDisplay::printImprove(string buildingname)
{
	string result="";
	int amountimprove=improveprogress[buildingname];
	int space=7-amountimprove;
	for(int s=0;s<space;s++)
	{
		result+=" ";
	}
	for(int i=0;i<amountimprove;i++)
	{
		result+="I";
	}
	return result;
}

string TextDisplay::printPlayer(string playerlist)
{
	string result="";
	int space=7-playerlist.length();
	for(int i=0;i<space;i++)
	{
		result+=" ";
	}
	result+=playerlist;
	return result;
}

void TextDisplay::generateDraw()
{
    squareplayer.clear();
    for (map<string, string>::iterator it = playerloc.begin(); it != playerloc.end(); it++)
    {
	string loc=it->second;
	string playername=it->first;
        squareplayer[loc] += playername;
    }	
}
void TextDisplay::drawBoard()
{
	generateDraw();
/*
	map<string, string> squareplayer;
	for (map<string, string>::iterator i = playerloc.begin(); i != playerloc.end(); i++) {
        squareplayer[i->second] += i->first;
    }*/

	cout<<"_________________________________________________________________________________________"<<endl;
	cout<<"|Goose  |"<<printImprove("EV1")<<"|NEEDLES|"<<printImprove("EV2")<<"|"<<printImprove("EV3")<<"|V1     |"<<printImprove("PHYS")<<"|"<<printImprove("B1")<<"|CIF    |"<<printImprove("B2")<<"|GO TO  |"<<endl;
	cout<<"|Nesting|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |"<<endl;
	cout<<"|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |"<<endl;
	cout<<"|"<<printPlayer(squareplayer["GOOSENESTING"])<<"|";
    cout<<printPlayer(squareplayer["EV1"])<<"|"<<printPlayer(squareplayer["NEEDLESHALLUP"])<<"|";
	cout<<printPlayer(squareplayer["EV2"])<<"|"<<printPlayer(squareplayer["EV3"])<<"|";
    cout<<printPlayer(squareplayer["V1"])<<"|"<<printPlayer(squareplayer["PHYS"])<<"|";       
	cout<<printPlayer(squareplayer["B1"])<<"|"<<printPlayer(squareplayer["CIF"])<<"|";  
	cout<<printPlayer(squareplayer["B2"])<<"|"<<printPlayer(squareplayer["GOTOTIMS"])<<"|"<<endl;
	cout<<"|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|"<<endl;
    cout<<"|"<<printImprove("OPT")<<"|                                                                       |"<<printImprove("EIT")<<"|"<<endl;
	cout<<"|-------|                                                                       |-------|"<<endl;
	cout<<"|OPT    |                                                                       |EIT    |"<<endl;
    cout<<"|"<<printPlayer(squareplayer["OPT"])<<"|                                                                       |"<<printPlayer(squareplayer["EIT"])<<"|"<<endl;
	cout<<"|-------|                                                                       |-------|"<<endl;
    cout<<"|"<<printImprove("BMH")<<"|                                                                       |"<<printImprove("ESC")<<"|"<<endl;
	cout<<"|-------|                                                                       |-------|"<<endl;
	cout<<"|BMH    |                                                                       |ESC    |"<<endl;
    cout<<"|"<<printPlayer(squareplayer["BMH"])<<"|                                                                       |"<<printPlayer(squareplayer["ESC"])<<"|"<<endl;
	cout<<"|-------|                                                                       |-------|"<<endl;
	cout<<"|SLC    |                                                                       |SLC    |"<<endl;
	cout<<"|       |                                                                       |       |"<<endl;
	cout<<"|       |                                                                       |       |"<<endl;
    cout<<"|"<<printPlayer(squareplayer["SLCLEFT"])<<"|                                                                       |"<<printPlayer(squareplayer["SLCRIGHT"])<<"|"<<endl;
	cout<<"|-------|                                                                       |-------|"<<endl;
    cout<<"|"<<printImprove("LHI")<<"|                                                                       |"<<printImprove("C2")<<"|"<<endl;
	cout<<"|-------|                                                                       |-------|"<<endl;
	cout<<"|LHI    |                                                                       |C2     |"<<endl;
    cout<<"|"<<printPlayer(squareplayer["LHI"])<<"|               _________________________________________               |"<<printPlayer(squareplayer["C2"])<<"|"<<endl;
	cout<<"|-------|               |                                       |               |-------|"<<endl;
	cout<<"|UWP    |               |  $$$   $$$   $$$$$  $$$   $$$   $$$   |               |REV    |"<<endl;
	cout<<"|       |               |  $  $  $  $     $  $   $ $   $ $   $  |               |       |"<<endl;
	cout<<"|       |               |  $$$$  $$$$    $   $   $ $   $ $   $  |               |       |"<<endl;
	cout<<"|"<<printPlayer(squareplayer["UWP"])<<"|               |  $   $ $   $  $    $   $ $   $ $   $  |               |"<<printPlayer(squareplayer["REV"])<<"|"<<endl;
	cout<<"|_______|               |  $$$$  $$$$  $      $$$   $$$   $$$   |               |_______|"<<endl;
	cout<<"|"<<printImprove("CPH")<<"|               |_______________________________________|               |NEEDLES|"<<endl;
	cout<<"|-------|                                                                       |HALL   |"<<endl;
	cout<<"|CPH    |                                                                       |       |"<<endl;
    cout<<"|"<<printPlayer(squareplayer["CPH"])<<"|                                                                       |"<<printPlayer(squareplayer["NEEDLESHALLRIGHT"])<<"|"<<endl;
	cout<<"|-------|                                                                       |-------|"<<endl;
    cout<<"|"<<printImprove("DWE")<<"|                                                                       |"<<printImprove("MC")<<"|"<<endl;
	cout<<"|-------|                                                                       |-------|"<<endl;
	cout<<"|DWE    |                                                                       |MC     |"<<endl;
    cout<<"|"<<printPlayer(squareplayer["DWE"])<<"|                                                                       |"<<printPlayer(squareplayer["MC"])<<"|"<<endl;
	cout<<"|-------|                                                                       |-------|"<<endl;
	cout<<"|PAC    |                                                                       |COOP   |"<<endl;
	cout<<"|       |                                                                       |FEE    |"<<endl;
	cout<<"|       |                                                                       |       |"<<endl;
    cout<<"|"<<printPlayer(squareplayer["PAC"])<<"|                                                                       |"<<printPlayer(squareplayer["COOPFEE"])<<"|"<<endl;
	cout<<"|-------|                                                                       |-------|"<<endl;
    cout<<"|"<<printImprove("RCH")<<"|                                                                       |"<<printImprove("DC")<<"|"<<endl;
	cout<<"|-------|                                                                       |-------|"<<endl;
	cout<<"|RCH    |                                                                       |DC     |"<<endl;
    cout<<"|"<<printPlayer(squareplayer["RCH"])<<"|                                                                       |"<<printPlayer(squareplayer["DC"])<<"|"<<endl;
	cout<<"|_______|_______________________________________________________________________|_______|"<<endl;
	cout<<"|DC Tims|"<<printImprove("HH")<<"|"<<printImprove("PAS")<<"|NEEDLES|"<<printImprove("ECH")<<"|MKV    |TUITION|"<<printImprove("ML")<<"|SLC    |"<<printImprove("AL")<<"|COLLECT|"<<endl;
	cout<<"|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |"<<endl;
	cout<<"|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |"<<endl;
	cout<<"|"<<printPlayer(squareplayer["DCTIMSLINE"])<<"|";
    cout<<printPlayer(squareplayer["HH"])<<"|";
	cout<<printPlayer(squareplayer["PAS"])<<"|";
	cout<<printPlayer(squareplayer["NEEDLESHALLBOTTOM"])<<"|";
	cout<<printPlayer(squareplayer["ECH"])<<"|";
    cout<<printPlayer(squareplayer["MKV"])<<"|";
	cout<<printPlayer(squareplayer["TUITION"])<<"|";       
	cout<<printPlayer(squareplayer["ML"])<<"|";       
	cout<<printPlayer(squareplayer["SLC"])<<"|";  
	cout<<printPlayer(squareplayer["AL"])<<"|";       
	cout<<printPlayer(squareplayer["COLLECTOSAP"])<<"|"<<endl;
	cout<<"|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|"<<endl;

}

