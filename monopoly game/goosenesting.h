#ifndef GOOSE_H
#define GOOSE_H
#include "unownableproperty.h"
#include <string>

class GooseNesting : public UnownableProperty{
public:
GooseNesting(std::string name);
~GooseNesting();
void action(Player& p);
};

#endif


