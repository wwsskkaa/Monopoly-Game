
#ifndef GOTOTIM_H
#define GOTOTIM_H
#include "unownableproperty.h"
#include <string>

class GoToTims : public UnownableProperty{
public:
GoToTims(std::string name);
~GoToTims();
void action(Player& p);
};

#endif
