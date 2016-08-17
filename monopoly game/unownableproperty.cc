#include "unownableproperty.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

     UnownableProperty::UnownableProperty(string name):Square(name,false){}
     UnownableProperty::~UnownableProperty(){}
    //string UnownableProperty::getName(){return propertyname;}
    //void  UnownableProperty::setName(string o){propertyname=o;}
Player* UnownableProperty::getcurrentowner(){return NULL;}
void UnownableProperty::setcurrentowner( Player* o){}
string UnownableProperty::getOwner(){return "";}
void UnownableProperty::setOwner(std::string){}
bool UnownableProperty::mortCondition(){return false;}
void UnownableProperty::setMortgage(bool mortgageornot){}
int UnownableProperty::getBuildCharge(){return 0;}
void UnownableProperty::setBuildCharge(const int ch){}
int UnownableProperty::getBuildCost(){return 0;}
void UnownableProperty::setBuildCost(const int co){}
void UnownableProperty::mortgage(Player & owner){}
void UnownableProperty::unmortgage(Player &owner){}
void UnownableProperty::purchase(Player & owner){}
bool UnownableProperty::getAcBuilding(){return false;}
void UnownableProperty::setAcBuilding(bool){}
string UnownableProperty::getMonoBlock(){return "";}
    void UnownableProperty::setMonoBlock(string mb){}
    int  UnownableProperty::getPurchaseCost(){return 0;}
    void  UnownableProperty::setPurchaseCost(int pc){}
 int  UnownableProperty::getImprovement(){return 0;}
void  UnownableProperty::setImprovement(int im){}
    int  UnownableProperty::getImproveCost(){return 0;}
    void  UnownableProperty::setImproveCost(int ic){}
    void UnownableProperty::improve(Player &p){}
void UnownableProperty::sellimprove(Player& p){}

