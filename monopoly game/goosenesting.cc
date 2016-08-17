
#include "goosenesting.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

GooseNesting ::GooseNesting(string name): UnownableProperty(name)
{}

GooseNesting ::~GooseNesting ()
{}

void GooseNesting ::action(Player& player)
{
//	cout << player.getName()<< ": You just got attacked by a flock of nesting geese!" << endl;
//	cout << "I told you to stay out of them!"<<endl;
#ifdef BONUS
    if(player.getName() == "BONNIE"){
        cout<<"BONNIE, you just attack all the geese in campus!!"<<endl;
	cout<<"I told them to stay away from you!"<<endl;
    }
    else{
cout<<"        (\\  }\\   (\\  }\\   (\\  }\\        "<<endl;
cout<<"       (  \\_('= (  \\_('= (  \\_('=        "<<endl;
cout<<"       (__(=_)  (__(=_)  (__(=_)          "<<endl;
cout<<"          -''=      -''=      -''=           "<<endl;
        cout << player.getName()<< ": You just got attacked by a flock of nesting geese!" << endl;
        cout << "I told you to stay out of them!"<<endl;
    }
#endif
#ifndef BONUS
    cout<<"        (\\  }\\   (\\  }\\   (\\  }\\        "<<endl;
    cout<<"       (  \\_('= (  \\_('= (  \\_('=        "<<endl;
    cout<<"       (__(=_)  (__(=_)  (__(=_)          "<<endl;
    cout<<"          -''=      -''=      -''=           "<<endl;
    cout << player.getName()<< ": You just got attacked by a flock of nesting geese!" << endl;
    cout << "I told you to stay out of them!"<<endl;
#endif
}
