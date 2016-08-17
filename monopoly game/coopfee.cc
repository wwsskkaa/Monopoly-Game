#include "coopfee.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

CoopFee ::CoopFee  (string name): UnownableProperty(name)
{}

CoopFee ::~CoopFee ()
{}

void CoopFee ::action(Player& player)
{
    #ifdef BONUS
    if(player.getName() == "BONNIE"){
        cout<<"BONNIE, PLEASE reveice a $1500 cheque. Please don't reject!!"<<endl;
        player.changeSavings(1500);
    }
    else{
    cout << "Player "<<player.getName()<< "has to pay $150 coop fee!" << endl;
    if(player.getSavings() < 150){
        cout <<player.getName()<<", you don't have $150"<<endl;
        cout <<"You can declear 'bankrupt' or get some money to pay it"<<endl;
    }
    player.changeSavings(-150);
    }
#endif
#ifndef BONUS
    
    cout << "Player "<<player.getName()<< "has to pay $150 coop fee!" << endl;
    if(player.getSavings() < 150){
        cout <<player.getName()<<", you don't have $150"<<endl;
        cout <<"You can declear 'bankrupt' or get some money to pay it"<<endl;
    }
    player.changeSavings(-150);
#endif
}
