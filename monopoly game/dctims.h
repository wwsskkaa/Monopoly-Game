
#ifndef DCTIM_H
#define DCTIM_H
#include "unownableproperty.h"
#include <string>

class DcTims : public UnownableProperty{
public:
    DcTims (std::string name);
    ~DcTims ();
void action(Player& p);
};

#endif

