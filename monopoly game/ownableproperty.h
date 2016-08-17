#ifndef OWNABLE_H
#define OWNABLE_H
#include <string>
#include "square.h"
#include "player.h"
//class Square;

class OwnableProperty:public Square{
  protected:
    std::string buildingowner;
    int buildingcost;
    int buildingcharge;
     Player* currentowner;
    bool mortgaged;//true for mortgaged, false otherwise
    bool AcBuilding;

  public:
    OwnableProperty(std::string name,int n);
    virtual ~OwnableProperty();
     Player* getcurrentowner();
    void setcurrentowner( Player* o);
     std::string getOwner();
     void setOwner(std::string);
    bool mortCondition() ;
    void setMortgage(bool mortgageornot);
    int getBuildCharge();
    void setBuildCharge(const int ch);
    int getBuildCost();
    void setBuildCost(const int co);
    bool getAcBuilding();
    void setAcBuilding(bool);
};

#endif
