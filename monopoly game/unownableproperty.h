#ifndef UNOWNABLE_H
#define UNOWNABLE_H
#include "square.h"
#include "player.h"
#include <string>
//class Square;
class UnownableProperty: public Square{
 protected:
    std::string propertyname; 

  public:
    UnownableProperty(std::string name);
    virtual ~UnownableProperty();
    //char getName() const;
    //void setName(const std::string o);
Player* getcurrentowner();
void setcurrentowner( Player* o);
std::string getOwner();
void setOwner(std::string);
bool mortCondition();
void setMortgage(bool mortgageornot);
int getBuildCharge();
void setBuildCharge(const int ch);
int getBuildCost();
void setBuildCost(const int co);
char getBuildingType();
void mortgage(Player & owner);
void unmortgage(Player &owner);
void purchase(Player & owner);
bool getAcBuilding();
void setAcBuilding(bool);

    std::string getMonoBlock();
    void setMonoBlock(std::string mb);
    int getPurchaseCost();
    void setPurchaseCost(int pc);
 int getImprovement();
void setImprovement(int im);
    int getImproveCost();
    void setImproveCost(int ic);
    void improve(Player &p);
void sellimprove(Player& p);

};

#endif
