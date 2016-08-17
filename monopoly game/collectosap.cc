#include "collectosap.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

CollectOsap ::CollectOsap (string name): UnownableProperty(name)
{}

CollectOsap ::~CollectOsap ()
{}

void CollectOsap ::action(Player& player)
{

    cout << "Player "<<player.getName()<< " receive a $200 cheque by landing on COLLECT OSAP!" << endl;
    player.changeSavings(200);
#ifdef BONUS
    cout << "Player "<<player.getName()<< " receive a extra $200 cheque by landing on COLLECT OSAP IN BONUS MODE!" << endl;
    player.changeSavings(200);
#endif
}

