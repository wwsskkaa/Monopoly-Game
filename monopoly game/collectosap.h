
#ifndef OSAP_H
#define OSAP_H
#include "unownableproperty.h"
#include <string>

class CollectOsap : public UnownableProperty{
public:
CollectOsap (std::string name);
~CollectOsap ();
void action(Player& p);
};

#endif
