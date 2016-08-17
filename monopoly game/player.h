
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
//#include "board.h"
//#include "square.h"
class Board;
class Square;

class Player{
std::string name;
char namechar;
int location;
bool intimsline;
bool bankrupt; // new
int lineturn;
int savings;
int totalworth;
int rimcupsowned;
int residencesowned;
int gymsowned;
Board* gb;
Square* currentsquare;
int oweamount;
bool wincup;

public:
Player(std::string name,char namechar,int rimcupsowned,int savings,int location,bool intimsline,int lineturn,Board*gb);
~Player();
void changeSavings(const int change);
    int getLineturn()const;
    void setLineturn(const int l);
std::string getName()const;
void setName(const std::string n);
char getCharName()const;
void setCharName(const char n);
void setSavings(const int s);
int getSavings()const;
void setTotalWorth(const int t);
int getTotalWorth()const;
void setLocation(const int l);
int getLocation() const;
    bool getTimsLine()const;
    void setTimsline(const bool t);
void setBankrupt(const bool b);
int getRimCups()const;
void setRimCups(const int c);
int getResiamount()const;
void setResiamount(const int r);
int getGymamount()const;
void setGymamount(const int g);
    Square* getcurrentsquare();
    void setcurrentsquare(Square * sq);
    int getOweAmount();
    void setOweAmount(int i);
bool getwincup();
void setwincup(bool b);
};

#endif

