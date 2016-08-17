#include "gym.h"
#include "player.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;
//Gym::Gym(std::string owner,int cost,int charge,bool mort,char type):OwnableProperty(owner,cost,charge,mort,type){}

Gym::~Gym()
{}


void Gym::action(Player &rent){
    if(currentowner == & rent){
        cout<<"Feel free to be on your property!"<<endl;
    }
     else if(mortgaged){
        cout<<"No need to pay for a mortgaged property!"<<endl;
        }
        else if(currentowner != &rent){
            cout<<"Player "<<rent.getName()<<" please roll 2 dices and pay"<<endl;
            int dice1 = rand() % 6 + 1;   // 1-6
            int dice2 = rand() % 6 + 1;
            cout<<"Player "<<rent.getName()<<"rolled "<<dice1<<" and "<<dice2<<"!"<<endl;
            int dicesum=dice1+dice2;
            if(currentowner->getGymamount()==2){
                cout <<rent.getName()<<" pays "<<currentowner->getName()<<" "<<10 * dicesum<<endl;
                currentowner->changeSavings(10*dicesum);
                rent.changeSavings(-10*dicesum);
            }
            else{
                cout <<rent.getName()<<" pays "<<currentowner->getName()<<" "<<4 * dicesum<<endl;
                currentowner->changeSavings(4*dicesum);
                rent.changeSavings(-4*dicesum);
	}
}
}

void Gym::purchase(Player & owner){
        currentowner = &owner;
        owner.changeSavings(-getBuildCost());
        cout<<owner.getName()<<" purchases "<<getName()<<endl;
        cout <<"It costs "<<getBuildCost()<<endl;
    int g = owner.getGymamount();
    owner.setGymamount(g+1);
    buildingowner = owner.getName();
}

void Gym::mortgage(Player & owner){
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
        int r = owner.getGymamount();
        owner.setGymamount(r - 1);
        
    }
}

void Gym::unmortgage(Player & owner){
    if(buildingowner != owner.getName()){
        cout << "You cannot unmortgage other's property!"<<endl;
    }else if(!mortgaged){
        cout << "You cannot unmortgage a unmortgaged property!"<<endl;
    }else {
        cout << "You have unmortgaged "<<getName()<<endl;
        mortgaged = false;
        int unmortgagefee = (buildingcost *0.6);
        int tw = owner.getTotalWorth();
        owner.changeSavings(-unmortgagefee);
        owner.setTotalWorth(tw - buildingcost * 0.1);
        int r = owner.getGymamount();
        owner.setGymamount(r + 1);
    }
}


string Gym::getMonoBlock(){return "";}
    void Gym::setMonoBlock(string mb){}
    int  Gym::getPurchaseCost(){return 0;}
    void  Gym::setPurchaseCost(int pc){}
 int  Gym::getImprovement(){return 0;}
void  Gym::setImprovement(int im){}
    int  Gym::getImproveCost(){return 0;}
    void  Gym::setImproveCost(int ic){}
    void  Gym::improve(Player &p){}
void Gym::sellimprove(Player& p){}
