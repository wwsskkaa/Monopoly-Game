
#ifndef COOP_H
#define COOP_H
#include "unownableproperty.h"
#include <string>

class CoopFee : public UnownableProperty{
public:
CoopFee(std::string name);
~CoopFee();
void action(Player& p);
};

#endif
