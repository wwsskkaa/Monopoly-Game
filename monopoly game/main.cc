#include "textdisplay.h"
#include "square.h"
#include "player.h"
#include "ownableproperty.h"
#include "collectosap.h"
#include "coopfee.h"
#include "dctims.h"
#include "goosenesting.h"
#include "gototims.h"
#include "gym.h"
#include "needleshall.h"
#include "residence.h"
#include "slc.h"
#include "board.h"
#include "tuition.h"
#include "unownableproperty.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

/*
 * TODO: update main function to take argument "-graphics" for part b. 
 * If -graphics argument is provided, forward this to the controller
 */
int main(int argc, char *argv[]) {
Board gameboard;
//TextDisplay* td;
//gameboard.setTD(td);
srand(time(0));
//************************command line argument*************************
if(argc==2&&strcmp(argv[1], "-testing") ==0)
{
	cout<<"You are entering the testing mode which the dice results depend on your input."<<endl;
	gameboard.setTesting(true);
	gameboard.setLoading(false);
}
else if(argc==3&&strcmp(argv[1], "-load") == 0)
{
	cout<<"You choose to load game from file: "<<argv[2]<<endl;
	gameboard.setTesting(false);
	gameboard.setLoading(true);
	gameboard.setFilename(argv[2]);
}
else if(argc==4)
{
	if(strcmp(argv[1], "-testing") == 0&&strcmp(argv[2], "-load") == 0)
	{
	        cout<<"You are entering the testing mode which the dice results depend on your input."<<endl;
		cout<<"You choose to load game from file: "<<argv[3]<<endl;
		gameboard.setTesting(true);
		gameboard.setLoading(true);
        gameboard.setFilename(argv[3]);

	}
	else if(strcmp(argv[1], "-load") == 0&&strcmp(argv[3], "-testing") == 0)
	{
		 cout<<"You are entering the testing mode which the dice results depend on your input."<<endl;
                cout<<"You choose to load game from file: "<<argv[2]<<endl;
                gameboard.setTesting(true);
                gameboard.setLoading(true);
        gameboard.setFilename(argv[2]);

	}
}
else
{
	cout<<"You are entering the normal mode with no loading and testing."<<endl;
                gameboard.setTesting(false);
                gameboard.setLoading(false);

}

gameboard.play();
}
