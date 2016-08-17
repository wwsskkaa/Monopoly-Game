#include "gototims.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

GoToTims::GoToTims(string name): UnownableProperty(name)
{}

GoToTims::~GoToTims()
{}

void GoToTims::action(Player& player)
{
    cout << "Player "<<player.getName()<< "has to go to DC tims line and have a rest!" << endl;
    player.setTimsline(true);
    player.setLocation(10);
    player.setLineturn(0);
}
