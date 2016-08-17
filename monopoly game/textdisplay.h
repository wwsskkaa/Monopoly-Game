#ifndef TEXTDISPLAY_HH
#define TEXTDISPLAY_HH
#include <iostream>
#include <string>
#include <map>

class TextDisplay{
private:

    std::map<std::string, std::string> playerloc; // first char:player name, second string: location
    std::map<std::string, int> improveprogress; // first string: building name, second int:improvement number
    std::map<std::string, std::string> squareplayer;    
public:
    TextDisplay();
    ~TextDisplay();
void generateDraw(); 
void drawBeginning();
void notifyRemove(std::string name);
void drawEnding(std::string);
void drawdice(int n);
    void notify(std::string buildingname, int improve); // changes improvements on text display
    void notify(std::string playername, std::string currentloc); // changes the location of the player on the text display
	std::string printImprove(std::string buildingname);
	std::string printPlayer(std::string playerlist);
	void drawBoard();
};

#endif
