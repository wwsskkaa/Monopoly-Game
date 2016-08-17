#ifndef GYM_H
#define GYM_H
#include "player.h"
#include "ownableproperty.h"
#include <string>
//class OwnableProperty;
class Gym : public OwnableProperty{

  public:
    Gym(std::string name):OwnableProperty(name,150){}
    ~Gym();
    void action(Player &owner);
void mortgage(Player & owner);
void unmortgage(Player & owner);
void purchase(Player & owner);


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
