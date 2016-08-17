#ifndef SQUARE_H
#define SQUARE_H
//#include "board.h"
#include "player.h"
#include <string>
class Board;

class Square{
std::string name;
bool ownableornot;
//Board* gb;
//protected:
    //std::string name;
public:
Square(std::string name,bool own);
virtual ~Square()=0;
std::string getName();
void setName(const std::string n);
//void setBoard(Board* b);
void setOwnable(const int o);
bool getOwnable();

virtual Player* getcurrentowner()=0;
virtual void setcurrentowner( Player* o)=0;
virtual std::string getOwner()=0;
virtual void setOwner(std::string)=0;
virtual bool mortCondition()=0;
virtual void setMortgage(bool mortgageornot)=0;
virtual int getBuildCharge()=0;
virtual void setBuildCharge(const int ch)=0;
virtual int getBuildCost()=0;
virtual void setBuildCost(const int co)=0;
virtual void mortgage(Player & owner)=0; 
virtual void unmortgage(Player &owner)=0; 
virtual void purchase(Player & owner)=0;
virtual bool getAcBuilding()=0;
virtual void setAcBuilding(bool)=0;
virtual void action(Player& p)=0;

virtual std::string getMonoBlock()=0;
virtual void setMonoBlock(std::string mb)=0;
virtual int getPurchaseCost()=0;
virtual void setPurchaseCost(int pc)=0;
virtual int getImprovement()=0;
virtual void setImprovement(int im)=0;
virtual int getImproveCost()=0;
virtual void setImproveCost(int ic)=0;
virtual void improve(Player &p)=0;
virtual void sellimprove(Player& p)=0;
};

#endif
