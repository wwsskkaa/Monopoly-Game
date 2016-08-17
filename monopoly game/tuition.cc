#include "tuition.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;

Tuition ::Tuition(string name): UnownableProperty(name)
{}

Tuition ::~Tuition ()
{}

void Tuition ::action(Player& player)
{
#ifdef BONUS
    if(player.getName() == "BONNIE"){
        cout<<"BONNIE receives a $2000 scholarship this term!!"<<endl;
        player.changeSavings(2000);
    }
    else{
        cout<<player.getName()<<": You are currently in Tuition Square."<<endl;
	string choice;
	int paying=300;
	cout << "Choose one from below: "<<endl<<"Option 1: pay $300 tuition now."<<endl<<"Option 2: pay 10% of total worth now"<<endl;
	cout << "Type 1 for Option 1 and 2 for Option 2" << endl;
    cout << "CAUTION: asset command will not work now."<<endl;
    cout << "CAUTION: invalid input other than 'asset' will be counted as a choice of Option 1."<<endl;
	cin >> choice;
	while(choice=="asset")
	{
		cout<<"asset command doesn't work at this square. type 1 or 2 to choose payment option."<<endl;
		cin>>choice;
	}
	if(choice=="2")
	{
		cout << player.getName() << "picked Option 2: 10% of total worth." <<endl;
		paying=player.getTotalWorth()/10;
	}
	else
	{
		cout << player.getName() << "picked Option 1: $300 tuition."<<endl;
	}
	player.changeSavings((0-paying));
    }
#endif
#ifndef BONNUS
    cout<<player.getName()<<": You are currently in Tuition Square."<<endl;
    string choice;
    int paying=300;
    cout << "Choose one from below: "<<endl<<"Option 1: pay $300 tuition now."<<endl<<"Option 2: pay 10% of total worth now"<<endl;
    cout << "Type 1 for Option 1 and 2 for Option 2" << endl;
    cout << "CAUTION: asset command will not work now."<<endl;
    cout << "CAUTION: invalid input other than 'asset' will be counted as a choice of Option 1."<<endl;
    cin >> choice;
    while(choice=="asset")
    {
        cout<<"asset command doesn't work at this square. type 1 or 2 to choose payment option."<<endl;
        cin>>choice;
    }
    if(choice=="2")
    {
        cout << player.getName() << "picked Option 2: 10% of total worth." <<endl;
        paying=player.getTotalWorth()/10;
    }
    else
    {
        cout << player.getName() << "picked Option 1: $300 tuition."<<endl;
    }
    player.changeSavings((0-paying));
#endif
}

