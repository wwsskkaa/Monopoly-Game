
#ifndef NEEDLE_H
#define NEEDLE_H
#include "unownableproperty.h"
#include <string>

class NeedlesHall : public UnownableProperty{
public:
NeedlesHall(std::string name);
~NeedlesHall();
void action(Player& p);
};

#endif

