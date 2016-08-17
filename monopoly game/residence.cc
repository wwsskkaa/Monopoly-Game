#include "residence.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

Residence::Residence(string name):OwnableProperty(name,200){
}

Residence::~Residence()
{}

void Residence::action(Player &rent){
    if(&rent == currentowner){
        cout <<"Fell free to be on your property"<<endl;
    }
    else if(mortgaged){
        cout<<"No need to pay for a mortgaged property!"<<endl;
        }
    else if(currentowner != &rent){
	int pp = 25*currentowner->getResiamount();
	if(currentowner->getResiamount() == 3){
		pp = 100;
	}
	if(currentowner->getResiamount() == 4){
		pp = 200;
	}
        cout<<"Player "<<rent.getName()<<" should pay rent to "<<currentowner->getName()<<" "<<pp<<endl;
        rent.changeSavings(pp);
        currentowner->changeSavings(pp);
        }
    else{
        cout<<"Enjoy the time in Residence!"<<endl;
        }
}

void Residence::mortgage(Player & owner){
    if(buildingowner != owner.getName()){
        cout << "You cannot mortgage other's property!"<<endl;
    }else if(mortgaged){
        cout << "You cannot mortgage a mortgaged property!"<<endl;
    }else{
        cout << "You have mortgaged "<<getName()<<endl;
        mortgaged = true;
        int tw = owner.getTotalWorth();
        owner.changeSavings(buildingcost / 2);
        owner.setTotalWorth(tw);
        int r = owner.getResiamount();
        owner.setResiamount(r - 1);
        
    }
}

void Residence::unmortgage(Player & owner){
    if(buildingowner != owner.getName()){
        cout << "You cannot unmortgage other's property!"<<endl;
    }else if(!mortgaged){
        cout << "You cannot unmortgage a unmortgaged property!"<<endl;
    }else {
        cout << "You have unmortgaged "<<getName()<<endl;
        mortgaged = false;
        int tw = owner.getTotalWorth();
        int unmortgagefee = (buildingcost  * 0.6);
        owner.setTotalWorth(tw - 0.1 * buildingcost);
        owner.changeSavings(-unmortgagefee);
        int r = owner.getResiamount();
        owner.setResiamount(r + 1);
    }
}
void Residence::purchase(Player & owner){
        currentowner = &owner;
        owner.changeSavings(-getBuildCost());
        cout<<owner.getName()<<" purchases "<<getName()<<endl;
        cout <<"It costs "<<getBuildCost()<<endl;
        int r = owner.getResiamount();
        owner.setResiamount(r+ 1);
        buildingowner = owner.getName();
}

string Residence::getMonoBlock(){return "";}
    void Residence::setMonoBlock(string mb){}
    int  Residence::getPurchaseCost(){return 0;}
    void  Residence::setPurchaseCost(int pc){}
 int  Residence::getImprovement(){return 0;}
void  Residence::setImprovement(int im){}
    int Residence::getImproveCost(){return 0;}
    void  Residence::setImproveCost(int ic){}
    void  Residence::improve(Player &p){}
void Residence::sellimprove(Player& p){}

