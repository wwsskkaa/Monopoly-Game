
#include "dctims.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

DcTims ::DcTims (string name): UnownableProperty(name)
{}

DcTims ::~DcTims ()
{}
void DcTims ::action(Player& player)
{
    /*if(player.getTimsLine()){
        cout << "Player "<<player.getName()<< "has to rest in Tims for "<< 3 - player.gettimeintimes() <<" turns" <<endl;
        player.settimeintims(player.gettimeintimes()+1);
    }
     else
     {
 	cout<<"WELCOME TO DC TIMS LINE!"<<endl;
     }
     */
    cout <<"Welcome to DC TIMS"<<endl;
}
