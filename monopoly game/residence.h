
#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "ownableproperty.h"
#include "player.h"
#include <string>

class Residence : public OwnableProperty{
public:
    Residence (std::string name);
    ~Residence ();
    void action(Player &rent);
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

