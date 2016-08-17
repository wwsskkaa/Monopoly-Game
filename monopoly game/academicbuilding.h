#ifndef ACADEMIC_H
#define ACADEMIC_H
#include "ownableproperty.h"
#include <string>

class AcademicBuilding : public OwnableProperty{
    std::string MonoBlock;
        int tuition[6];
    int purchasecost;
    int improvecost;
    int improvelevel;

  public:
	AcademicBuilding(std::string s1,std::string s2, int i1,int i2,int i3,int i4,int i5,int i6,int i7,int i8);
    ~AcademicBuilding();
    std::string getMonoBlock();
    void setMonoBlock(std::string mb);
    int getPurchaseCost();
    void setPurchaseCost(int pc);
 int getImprovement();
void setImprovement(int im);
    int getImproveCost();
    void setImproveCost(int ic);
    int pay();
    void improve(Player &p);
    void action(Player &owner,Player &passer);
    void purchase(Player &owner);
void sellimprove(Player& p);
void action(Player & rent);
void unmortgage(Player & owner);
void mortgage(Player & owner);
};

#endif

