
#ifndef TUITION_H
#define TUITION_H
#include "unownableproperty.h"
#include <string>

class Tuition : public UnownableProperty{
public:
Tuition(std::string name);
~Tuition();
void action(Player& p);
};

#endif

