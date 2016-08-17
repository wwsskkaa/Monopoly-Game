
#ifndef SLC_H
#define SLC_H
#include "unownableproperty.h"
#include <string>
#include <iostream>

class Slc : public UnownableProperty{
public:
   Slc(std::string name);
   ~Slc();
void action(Player& p);
};

#endif
