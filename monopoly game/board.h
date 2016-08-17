
#ifndef ___BOARD___
#define ___BOARD___
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
#include "textdisplay.h"
#include "tuition.h"
#include "unownableproperty.h"
#include "academicbuilding.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>



class Board{
    Square* squareblock[40];
    Player * p[6];
    int totalplayer;
    int current;
   std::map <char, bool> checklist;// map[char] == true if char is avalible;
    int rolltime;
    int rollchance;
    bool loading;
    bool testing;
int rimscuptotal;
std::string readfilename;
TextDisplay* td;
    int stillingame[6];
    int stillinplayer;
    int dicethisturn;
public:
    Board();
    ~Board();
void payback(Player * p);
void setFilename(std::string file);
    int roll();//needed done
    bool CheckMono(std::string property) const;
    void trade(Player &p1, Player &p2, std::string offer, std::string require);
    void init();
void action(Player *p,int r);
    void play();
    bool move(Player * p, int move);//return true if this move passes collectOSAP
    void save();
    void cleanUp();
    void auction(std::string);
    void showassets(Player * );
        int getCuptotal();
    void setCuptotal(int);
    void setLoading(bool);
    void setTesting(bool);
    bool getLoading();
    bool getTesting();
    Player * convertPlayer(std::string);
    bool checkimprove(std::string);
    int convertSquare(std::string);
	void bankruptcy(Player& p1, Player* p2);
	void load(std::string filename);
	void save(std::string filename);
	void removePlayer(std::string playername);
	void setTD(TextDisplay* td);
    //Tue new:
    void playroll(Player *);
    void playtrade(Player *);

};


#endif

