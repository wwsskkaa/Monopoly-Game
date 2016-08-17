#include "ownableproperty.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

OwnableProperty::OwnableProperty(string name, int n):Square(name,true),buildingcost(n)
{
/*
TODO!!!!
*/
  buildingowner="";
    currentowner=NULL;
    mortgaged=false;
    AcBuilding = false;
}

OwnableProperty::~OwnableProperty(){}
/*
string OwnableProperty::getName()
{
	return name;
}

void OwnableProperty::setName(string n)
{
	name=n;
}
 */
Player* OwnableProperty::getcurrentowner()
{
	return currentowner;
}

    void OwnableProperty::setcurrentowner( Player* o)
{
	currentowner=o;
    if(o == NULL){
        buildingowner = "";
    }
    else{
	buildingowner=o->getName();
    }
}

     std::string OwnableProperty::getOwner()
{
	return buildingowner;
}

     void OwnableProperty::setOwner(std::string o)
{
	buildingowner=o;
}

    bool OwnableProperty::mortCondition()
{
	return mortgaged;
}

    void OwnableProperty::setMortgage(bool mortgageornot)
{
	mortgaged=mortgageornot;
}

    int OwnableProperty::getBuildCharge()
{
	return buildingcharge;
}

    void OwnableProperty::setBuildCharge(int ch)
{
	buildingcharge=ch;
}

    int OwnableProperty::getBuildCost()
{
	return buildingcost;
}

    void OwnableProperty::setBuildCost(int co)
{
	buildingcost=co;
}

    /*char OwnableProperty::getBuildingType()
{
	return buildingtype;
}
     */

//Player * OwnableProperty::getcurrentowner()
//{
//    return currentowner;
//}

//void OwnableProperty::setcurrentowner(Player * p){
//    currentowner = p;
//}
bool OwnableProperty::getAcBuilding(){
    return AcBuilding;
}
void OwnableProperty::setAcBuilding(bool b){
    AcBuilding = b;
}


