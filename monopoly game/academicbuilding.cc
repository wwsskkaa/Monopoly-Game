#include "player.h"
#include "academicbuilding.h"
#include <iostream>
#include <string>
using namespace std;

AcademicBuilding::AcademicBuilding(string s1,string s2, int i1,int i2,int i3,int i4,int i5,int i6,int i7,int i8):OwnableProperty(s1,i1),MonoBlock(s2),improvecost(i2)
{   improvelevel = 0;
    tuition[0] = i3;
    tuition[1] = i4;
    tuition[2] = i5;
    tuition[3] = i6;
    tuition[4] = i7;
    tuition[5] = i8;
}
AcademicBuilding::~AcademicBuilding(){}
int AcademicBuilding::pay(){
    return tuition[improvelevel];
}
string AcademicBuilding::getMonoBlock()
{
	return MonoBlock;
}
void AcademicBuilding::setMonoBlock(std::string mb)
{
	MonoBlock=mb;
}
int AcademicBuilding::getPurchaseCost()
{
return purchasecost;

}
void AcademicBuilding::setPurchaseCost(int pc)
{
purchasecost=pc;
}
int AcademicBuilding::getImprovement()
{
	return improvelevel;
}
void AcademicBuilding::setImprovement(int im)
{
	improvelevel=im;
}
int AcademicBuilding::getImproveCost()
{
	return improvecost;
}
void AcademicBuilding::setImproveCost(int ic)
{
	improvecost = ic;
}

void AcademicBuilding::improve(Player & p){
    if(p.getSavings() <improvecost){
        cout<<"Sorry, you don't have enough savings to improve!"<<endl;
    }
    else if(&p != currentowner){
        cout << "Sorry, you cannot improve other's property"<<endl;
        }
    else if(getImprovement() == 5){
        cout << "Sorry, you property already has 5 improvements and cannot be improved anymore"<<endl;
        }
    else{
        improvelevel++;
        int wow =p.getTotalWorth();
        p.changeSavings(-improvecost);
        p.setTotalWorth(wow);
	cout<<"You buy improvement for $"<<improvecost<<endl;
    }
}
//int AcademicBuilding::getImprovement(){
//    return improvelevel;
//}
//void AcademicBuilding::setImprovement(int i){
//    improvelevel = i;
//}

void AcademicBuilding::sellimprove(Player& p){
    if(&p != currentowner){
        cout<<"Sorry, you cannot sell other's improvements"<<endl;
    }
    if(getImprovement() == 0){
        cout << "Sorry, you can't sell improvements of a property not improved."<<endl;
    }
    else{
        currentowner->changeSavings(0.5*improvecost);
        int www = p.getTotalWorth();
        p.setTotalWorth(www - improvecost);
        cout<<"You get "<<0.5*improvecost<<" by selling an improvements"<<endl;
        improvelevel--;
    }
}
void AcademicBuilding::action(Player & rent){
    if(mortCondition()){
        cout<<"You dont need to pay for a mortgaged property!"<<endl;
    }else if(&rent != currentowner){
        if(rent.getSavings() >= pay()){
        cout <<rent.getName()<<" pays "<<currentowner->getName()<<" "<<pay()<<endl;
        currentowner->changeSavings(pay());
        rent.changeSavings(-pay());
        }
        else{
            int owe = pay() - rent.getSavings();
            cout << "You don't have enough savings to pay"<<endl;
            cout << "You have to pay "<<owe<<endl;
            cout << "You can trade, mortgage or sell improvements to get money"<<endl;
            cout << "Or, You get enter 'bankrupt' to declear bankruptcy" <<endl;
           // rent.setOweAmount(owe);
           currentowner->changeSavings(owe);
	   rent.changeSavings(-pay());
        }
    }
}

void AcademicBuilding::purchase(Player & owner){
        currentowner = &owner;
    int tw = owner.getTotalWorth();
        owner.changeSavings(-getBuildCost());
	owner.setTotalWorth(tw);
        cout<<owner.getName()<<" purchases "<<getName()<<endl;
        cout <<"It costs "<<getBuildCost()<<endl;
        buildingowner = owner.getName();
}
void AcademicBuilding::unmortgage(Player & owner){
    if(buildingowner != owner.getName()){
        cout << "You cannot unmortgage other's property!"<<endl;
    }else if(!mortgaged){
        cout << "You cannot unmortgage a unmortgaged property!"<<endl;
    }else{
        cout << "You have unmortgaged "<<getName()<<endl;
        mortgaged = false;
        int tw = owner.getTotalWorth();
        int unmortgagefee = (buildingcost * 0.6);
        owner.changeSavings(-unmortgagefee);
        owner.setTotalWorth(tw - buildingcost * 0.1);
    }
}

void AcademicBuilding::mortgage(Player & owner){
    if(buildingowner != owner.getName()){
        cout << "You cannot mortgage other's property!"<<endl;
    }else if(mortgaged){
        cout << "You cannot mortgage a mortgaged property!"<<endl;
    }else if(getImprovement() != 0){
        cout << "You have to sell all improvements before mortgage"<<endl;
    }else{
        mortgaged = true;
        cout <<"you have mortgaged "<<getName()<<endl;
        int w =owner.getTotalWorth();
        owner.changeSavings(buildingcost / 2);
        owner.setTotalWorth(w);
//	owner.setTotalWorth(owner.getSavings() + buildingcost / 2);
    }
}
