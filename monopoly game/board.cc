#include "board.h"
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
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;


Board::Board ()
{
    readfilename="";
    totalplayer=0;
    current=0;
    rimscuptotal=0;
    rolltime=0;
    loading=false;
    testing=false;
    td=new TextDisplay();
    rollchance=0;
    checklist['G']=true;
    checklist['B']=true;
    checklist['D']=true;
    checklist['P']=true;
    checklist['S']=true;
    checklist['$']=true;
    checklist['L']=true;
    checklist['T']=true;
//    atexit(cleanUp);
    for(int i = 0 ; i < 6; i ++){
        stillingame[i] = i;
    }
   // checkwin = 0;
}
void Board:: cleanUp ()
{
	
	delete td;
    for(int i = 0 ; i < totalplayer; i++){
	delete p[i];
}

for(int i = 0; i < 40; i++){
	delete squareblock[i];
}

}

Board::~Board()
{
cleanUp();
}
void Board::setFilename(string file)
{
	readfilename=file;
}
void Board::init()
{
squareblock[0]=new CollectOsap("COLLECTOSAP");
squareblock[1]=new AcademicBuilding("AL","Arts1",40,50,2,10,30,90,160,250);
squareblock[2]=new Slc("SLCBOTTOM");
squareblock[3]=new AcademicBuilding("ML","Arts1",60,50,4,20,60,180,320,450);
squareblock[4]=new Tuition("TUITION");
squareblock[5]=new Residence("MKV");
squareblock[6]=new AcademicBuilding("ECH","Arts2",100,50,6,30,90,270,400,550);
squareblock[7]=new NeedlesHall("NEEDLESHALLBOTTOM");
squareblock[8]=new AcademicBuilding("PAS","Arts2",100,50,6,30,90,270,400,550);
squareblock[9]=new AcademicBuilding("HH","Arts2",120,50,8,40,100,300,450,600);
squareblock[10]=new DcTims("DCTIMSLINE");
squareblock[11]=new AcademicBuilding("RCH","Eng",140,100,10,50,150,450,625,750);
squareblock[12]=new Gym("PAC");
squareblock[13]=new AcademicBuilding("DWE","Eng",140,100,10,50,150,450,625,750);
squareblock[14]=new AcademicBuilding("CPH","Eng",160,100,12,60,180,500,700,900);
squareblock[15]=new Residence("UWP");
squareblock[16]=new AcademicBuilding("LHI","Health",180,100,14,70,200,550,750,950);
squareblock[17]=new Slc("SLCLEFT");
squareblock[18]=new AcademicBuilding("BMH","Health",180,100,14,70,200,550,750,950);
squareblock[19]=new AcademicBuilding("OPT","Health",200,100,16,80,220,600,800,1000);
squareblock[20]=new GooseNesting("GOOSENESTING");
squareblock[21]=new AcademicBuilding("EV1","Env",220,150,18,90,250,700,875,1050);
squareblock[22]=new NeedlesHall("NEEDLESHALLUP");
squareblock[23]=new AcademicBuilding("EV2","Env",220,150,18,90,250,700,875,1050);
squareblock[24]=new AcademicBuilding("EV3","Env",240,150,20,100,300,750,925,1100);
squareblock[25]=new Residence("V1");
squareblock[26]=new AcademicBuilding("PHYS","Sci1",260,150,22,110,330,800,975,1150);
squareblock[27]=new AcademicBuilding("B1","Sci1",260,150,22,110,330,800,975,1150);
squareblock[28]=new Gym("CIF");
squareblock[29]=new AcademicBuilding("B2","Sci1",280,150,24,120,360,850,1025,1200);
squareblock[30]=new GoToTims("GOTOTIMS");
squareblock[31]=new AcademicBuilding("EIT","Sci2",300,200,26,130,390,900,1100,1275);
squareblock[32]=new AcademicBuilding("ESC","Sci2",300,200,26,130,390,900,1100,1275);
squareblock[33]=new Slc("SLCRIGHT");
squareblock[34]=new AcademicBuilding("C2","Sci2",320,200,28,150,450,1000,1200,1400);
squareblock[35]=new Residence("REV");
squareblock[36]=new NeedlesHall("NEEDLESHALLRIGHT");
squareblock[37]=new AcademicBuilding("MC","Math",350,200,35,175,500,1100,1300,1500);
squareblock[38]=new CoopFee("COOPFEE");
squareblock[39]=new AcademicBuilding("DC","Math",400,200,50,200,600,1400,1700,2000);
    squareblock[1]->setAcBuilding(true);
    squareblock[3]->setAcBuilding(true);
    squareblock[6]->setAcBuilding(true);
    squareblock[8]->setAcBuilding(true);
    squareblock[9]->setAcBuilding(true);
    squareblock[11]->setAcBuilding(true);
    squareblock[13]->setAcBuilding(true);
    squareblock[14]->setAcBuilding(true);
    squareblock[16]->setAcBuilding(true);
    squareblock[18]->setAcBuilding(true);
    squareblock[19]->setAcBuilding(true);
    squareblock[21]->setAcBuilding(true);
    squareblock[23]->setAcBuilding(true);
    squareblock[24]->setAcBuilding(true);
    squareblock[26]->setAcBuilding(true);
    squareblock[27]->setAcBuilding(true);
    squareblock[29]->setAcBuilding(true);
    squareblock[31]->setAcBuilding(true);
    squareblock[32]->setAcBuilding(true);
    squareblock[34]->setAcBuilding(true);
    squareblock[37]->setAcBuilding(true);
    squareblock[39]->setAcBuilding(true);
}

void Board::setTD(TextDisplay* tdd)
{
	td=tdd;
}
int Board::getCuptotal()
{
	return rimscuptotal;
}
void Board::setCuptotal(int c)
{
	rimscuptotal=c;
}
void Board::setLoading(bool b){
    loading = b;
}
void Board::setTesting(bool b){
    testing = b;
}
bool Board::getLoading(){
    return loading;
}
bool Board::getTesting(){
    return testing;
}
Player* Board::convertPlayer(string owner)
{
    for(int i=0;i<6;i++)
    {
        if(p[i]->getName()==owner)
        {
            return p[i];
        }
    }
   return NULL;
}

void Board::payback(Player * p){
    int l = p->getLocation();
    int o = p->getOweAmount();
    if(p->getOweAmount()!= 0){
        if(l == 1 || l == 3 || l == 5 || l == 6 || l == 8 || l == 9 || l==11 || l == 13 || l == 12
           || l == 14 || l == 15 || l == 16 || l == 18 || l == 19 || l == 21 || l == 23
           || l == 24 || l == 25 || l == 26 || l == 27 || l == 28 || l == 29 || l == 31
           || l == 32 || l == 34 || l == 35 || l == 37 || l == 39)
	{
            if(p->getSavings() >= o)
	    {
                p->changeSavings(-o);
                squareblock[l]->getcurrentowner()->changeSavings(o);
                p->setOweAmount(0);
            }
            else
	    {
                int q = p->getSavings();
                int so = o - q;
                p->changeSavings(-q);
                squareblock[l]->getcurrentowner()->changeSavings(q);
                p->setOweAmount(so);
                cout <<p->getName()<<": You still owe "<<so<<endl;
            }
        }
        else
	{
            if(p->getSavings() >= o)
	    {
                p->changeSavings(-o);
                p->setOweAmount(0);
            }
            else
	    {
                int q = p->getSavings();
                int so = o - q;
                p->changeSavings(-q);
                p->setOweAmount(so);
                cout <<p->getName()<<": You still owe "<<so<<endl;
            }
        }
   }
    //if(p->getOweAmount() == 0) return true;
    //else return false;
}

void Board::showassets(Player * p){
    cout <<p->getName()<<"'s Asset List:"<<endl;
    cout<<"Total worth: $"<<p->getTotalWorth()<<endl;
	cout<<"Savings: $"<<p->getSavings()<<endl;
	cout<<"# of Rim cups: "<<p->getRimCups()<<endl;
	cout<<"Owned Building: (organized by Monopoly block)"<<endl;
    cout <<endl<<"Arts1 Block:"<<endl;
    if(squareblock[1]->getcurrentowner() == p){
        cout <<"AL"<<endl;
    }
    if(squareblock[3]->getcurrentowner() == p){
        cout <<"ML"<<endl;
    }
    cout <<endl<<"Arts2 Block:"<<endl;
    if(squareblock[6]->getcurrentowner() == p){
        cout <<"ECH"<<endl;
    }
    if(squareblock[8]->getcurrentowner() == p){
        cout <<"PAS"<<endl;
    }
    if(squareblock[9]->getcurrentowner() == p){
        cout <<"HH"<<endl;
    }
    cout <<endl<<"Eng Block:"<<endl;
    if(squareblock[11]->getcurrentowner() == p){
        cout <<"RCH"<<endl;
    }
    if(squareblock[13]->getcurrentowner() == p) cout <<"DWE"<<endl;
    if(squareblock[14]->getcurrentowner()==p) cout <<"CPH"<<endl;
    cout <<endl<<"Health Block:"<<endl;
    if(squareblock[16]->getcurrentowner() == p) cout <<"LHI"<<endl;
    if(squareblock[18]->getcurrentowner() == p) cout <<"BMH"<<endl;
    if(squareblock[19]->getcurrentowner() == p) cout <<"OPT"<<endl;
    cout <<endl<<"Env Block:"<<endl;
    if(squareblock[21]->getcurrentowner() == p) cout <<"EV1"<<endl;
    if(squareblock[23]->getcurrentowner() == p) cout <<"EV2"<<endl;
    if(squareblock[24]->getcurrentowner() == p) cout <<"EV3"<<endl;
    cout <<endl<<"Sci1 Block:"<<endl;
    if(squareblock[26]->getcurrentowner() == p) cout <<"PHYS"<<endl;
    if(squareblock[27]->getcurrentowner() == p) cout <<"B1"<<endl;
    if(squareblock[29]->getcurrentowner() == p) cout <<"B2"<<endl;
    cout <<endl<<"Sci2 Block:"<<endl;
    if(squareblock[31]->getcurrentowner() == p) cout <<"EIT"<<endl;
    if(squareblock[32]->getcurrentowner() == p) cout <<"ESC"<<endl;
    if(squareblock[34]->getcurrentowner() == p) cout <<"C2"<<endl;
    cout <<endl<<"Math Block:"<<endl;
    if(squareblock[37]->getcurrentowner() == p) cout <<"MC"<<endl;
    if(squareblock[39]->getcurrentowner() == p) cout <<"DC"<<endl;
    cout <<endl<<"Residence Block:"<<endl;
    if(squareblock[5]->getcurrentowner() == p) cout <<"MKV"<<endl;
    if(squareblock[15]->getcurrentowner() == p) cout <<"UWP"<<endl;
    if(squareblock[25]->getcurrentowner() == p) cout <<"V1"<<endl;
    if(squareblock[35]->getcurrentowner() == p) cout <<"REV"<<endl;
    cout <<endl<<"Gym Block:"<<endl;
    if(squareblock[12]->getcurrentowner() == p) cout <<"PAC"<<endl;
    if(squareblock[28]->getcurrentowner() == p) cout <<"CIF"<<endl;
}


void Board::auction(string s){
    cout<<"Auciont "<<s<<" now!!!"<<endl;
	cout << "***********************************AUCTION TIME***********************************"<< endl;
	cout << "First, some rules:"<<endl;
	cout << "1.The auction begins with the first player."<<endl;
	cout << "2.Each player can either draw or give a higher price than the previous player."<<endl;
	cout << "3.If want to draw, type 'draw'."<<endl;
	cout << "4.If want to bid, type the amount, pure numbers, no dollar sign."<<endl;
	cout << "5.Auction continues until 1 remains and that player has to pay final bid."<<endl;
	cout << "***********************************GOOD LUCK***********************************"<< endl<<endl;
    int inauction = stillinplayer;
    int currentauction = 0;
    int quitacution[6];
    int quitnum = 0;
    int bit = 0;
    int stillinauction[6];
    bool stillin = false;
    for(int i = 0 ; i < totalplayer;i++){
         stillinauction[i] = i;
    }
    for(int i = 0 ; i < 6; i++){
	quitacution[i] = -1;
	}
    while(inauction != 1 && !cin.eof()){
        if(p[currentauction] == NULL){
            if(currentauction == totalplayer){
                currentauction=0;
            }
            else currentauction++;
        }
        if(p[currentauction]!=NULL){
           // cerr<<"still in game"<<endl;
            stillin = true;
            for(int i = 0; i < quitnum; i++){
                if(quitacution[i] == currentauction){
                    stillin = false;
                    break;
                }
            }
            if(stillin){
                cout<<"Number of players in the auction is: "<<inauction<<endl;
                cout<<"The bid is "<<bit<<" now!"<<endl;
                cout<<p[currentauction]->getName()<<", it's your turn! what's your action?"<<endl;
                string action;
                while(cin >> action){
                    if(cin.eof() || cin.fail()) return;
                    if(action == "draw"){
                        quitacution[quitnum] = currentauction;
                        for(int n = 0 ; n < totalplayer; n++){
                            if(stillinauction[n] == currentauction){
                                stillinauction[n] = -2;
                                }
                            }
                        if(currentauction == totalplayer - 1){
                            currentauction = 0;
                        }
                        else{
                            currentauction++;
                        }
                            quitnum ++;
                            inauction--;
                            break;
                        }
                    else{
                        //cerr<<"action is: "<<action<<endl;
                        istringstream ss(action);
                        int currentbid;
                        ss >> currentbid;
                        if(currentbid <= bit){
                            cout <<"Sorry, you have to give a bid which is higher than the current one."<<endl;
                            cout <<"Please, re-enter your action."<<endl;
                        }
                       // else if(currentbid > p[currentauction]->getSavings()){
                       //     cout <<"You cannot afford the bid you give, please,re-enter your aciton"<<endl;
                       // }
                        else{
                            bit = currentbid;
                            if(currentauction == totalplayer-1){
                                currentauction = 0;
                            }
                            else{
                                currentauction++;
                            }
                            break;
                        }
                    }
                }
            }
            else{
                if(currentauction == totalplayer - 1){
                    currentauction = 0;
                }
                else currentauction++;
                
            }
        }
    }
	int w = 0;
	for(int q = 0; q < totalplayer; q++){
        if(p[q] != NULL){
		if(stillinauction[q] != -2 ){
			w = q;
		}
        }
	}
    cout <<p[w]->getName()<<" wins "<<s<<" by bidding "<<bit<<" dollars in the auction!"<<endl;
    squareblock[convertSquare(s)]->setcurrentowner(p[w]);
    if(p[w]->getSavings() < bit){
        int ss = p[w]->getSavings();
        p[w]->setOweAmount(bit - ss);
        cout <<p[w]->getName()<<": You now owe bank "<<bit - ss<<" after winning the auction"<<endl;
        cout<<p[w]->getName()<<": You have to pay it back or bankrupt in your turn!"<<endl;
    }
    //int www = p[w]->getTotalWorth();
    p[w]->changeSavings(-bit);
    p[w]->setTotalWorth(p[w]->getTotalWorth() + squareblock[convertSquare(s)]->getBuildCost());
}


    
int Board::roll()
{
	int returnvalue;
	if(testing==false)
	{
		returnvalue= rand() % 6 + 1;
	}
	else
	{
		cout<<"<Testing Mode> please enter 1 integer from 1-6 for dice"<<endl;
		int tdice1;
		cin>>tdice1;
		if (cin.eof() || cin.fail()){cleanUp(); exit(0);} 
		while(tdice1<1||tdice1>6)
		{
			cout<<"Out of range. Again, enter 1-6 for dice"<<endl;
			cin>>tdice1;
		}
		 returnvalue= tdice1;
	}
	return returnvalue;
}

bool Board::checkimprove(string s){
    if(s == "AL" || s == "ML"){
        if(squareblock[0]->getImprovement() != 0 || squareblock[3]->getImprovement() != 0){
            return true;
        }
    }
    if(s == "ECH" || s == "PAS" || s == "HH"){
        if(squareblock[6]->getImprovement() != 0
           || squareblock[8]->getImprovement() != 0
           || squareblock[9]->getImprovement() != 0){
            return true;
        }
    }
    if(s == "RCH" || s == "DWE" || s == "CPH"){
        if(squareblock[11]->getImprovement() != 0
           || squareblock[13]->getImprovement() != 0
           || squareblock[14]->getImprovement() != 0){
            return true;
        }
    }
    if(s == "LHI" || s == "BMH" || s == "OPT"){
        if(squareblock[16]->getImprovement() != 0
           || squareblock[18]->getImprovement() != 0
           || squareblock[19]->getImprovement() != 0){
            return true;
        }
    }
    if(s == "EV1" || s == "EV2" || s == "EV3"){
        if(squareblock[21]->getImprovement() != 0
           || squareblock[22]->getImprovement() != 0
           || squareblock[23]->getImprovement() != 0){
            return true;
        }
    }
    if(s == "PHYS" || s == "B1" || s == "B2"){
        if(squareblock[26]->getImprovement() != 0
           || squareblock[27]->getImprovement() != 0
           || squareblock[28]->getImprovement() != 0){
            return true;
        }
    }
    if(s == "EIT" || s == "ESC" || s == "C2"){
        if(squareblock[31]->getImprovement() != 0
           || squareblock[32]->getImprovement() != 0
           || squareblock[34]->getImprovement() != 0){
            return true;
        }
    }
    if(s == "MC" || s == "DC"){
        if(squareblock[37]->getImprovement()!= 0
           || squareblock[39]->getImprovement() != 0){
            return true;
        }
    }
    return false;
}

int Board::convertSquare(string buildingname)
{
    int squareindex;
    if(buildingname=="COLLECTOSAP")
    {
        squareindex=0;
    }
    else if(buildingname=="AL")
    {
        squareindex=1;
    }
    else if(buildingname=="SLCBOTTOM")
    {
        squareindex=2;
    }
    else if(buildingname=="ML")
    {
        squareindex=3;
    }
    else if(buildingname=="TUITION")
    {
        squareindex=4;
    }
    else if(buildingname=="MKV")
    {
        squareindex=5;
    }
    else if(buildingname=="ECH")
    {
        squareindex=6;
    }
    else if(buildingname=="NEEDLESHALLBOTTOM")
    {
        squareindex=7;
    }
    else if(buildingname=="PAS")
    {
        squareindex=8;
    }
    else if(buildingname=="HH")
    {
        squareindex=9;
    }
    else if(buildingname=="DCTIMSLINE")
    {
        squareindex=10;
    }
    else if(buildingname=="RCH")
    {
        squareindex=11;
    }
    else if(buildingname=="PAC")
    {
        squareindex=12;
    }
    else if(buildingname=="DWE")
    {
        squareindex=13;
    }
    else if(buildingname=="CPH")
    {
        squareindex=14;
    }
    else if(buildingname=="UWP")
    {
        squareindex=15;
    }
    else if(buildingname=="LHI")
    {
        squareindex=16;
    }
    else if(buildingname=="SLCLEFT")
    {
        squareindex=17;
    }
    else if(buildingname=="BMH")
    {
        squareindex=18;
    }
    else if(buildingname=="OPT")
    {
        squareindex=19;
    }
    else if(buildingname=="GOOSENESTING")
    {
        squareindex=20;
    }
    else if(buildingname=="EV1")
    {
        squareindex=21;
    }
    else if(buildingname=="NEEDLESHALLUP")
    {
        squareindex=22;
    }
    else if(buildingname=="EV2")
    {
        squareindex=23;
    }
    else if(buildingname=="EV3")
    {
        squareindex=24;
    }
    else if(buildingname=="V1")
    {
        squareindex=25;
    }
    else if(buildingname=="PHYS")
    {
        squareindex=26;
    }
    else if(buildingname=="B1")
    {
        squareindex=27;
    }
    else if(buildingname=="CIF")
    {
        squareindex=28;
    }
    else if(buildingname=="B2")
    {
        squareindex=29;
    }
    else if(buildingname=="GOTOTIMS")
    {
        squareindex=30;
    }
    else if(buildingname=="EIT")
    {
        squareindex=31;
    }
    else if(buildingname=="ESC")
    {
        squareindex=32;
    }
    else if(buildingname=="SLCRIGHT")
    {
        squareindex=33;
    }
    else if(buildingname=="C2")
    {
        squareindex=34;
    }
    else if(buildingname=="REV")
    {
        squareindex=35;
    }
    else if(buildingname=="NEEDLESHALLRIGHT")
    {
        squareindex=36;
    }
    else if(buildingname=="MC")
    {
        squareindex=37;
    }
    else if(buildingname=="COOPFEE")
    {
        squareindex=38;
    }
    else
    {
        squareindex=39;
    }
    return squareindex;
}

bool Board::CheckMono(string property) const{
    if(property == "AL" || property == "ML"){
        if(squareblock[1]->getcurrentowner() == squareblock[3]->getcurrentowner()){
            return true;
        }
    }
    else if(property == "ECH" || property == "PAS" || property == " HH"){
        if(squareblock[6]->getcurrentowner() == squareblock[8]->getcurrentowner() && squareblock[8]->getcurrentowner() == squareblock[9]->getcurrentowner()){
            return true;
        }
    }
    else if(property == "RCH" || property == "DWE" || property == "CPH"){
        if(squareblock[11]->getcurrentowner() == squareblock[13]->getcurrentowner() && squareblock[13]->getcurrentowner() == squareblock[14]->getcurrentowner()){
            return true;
        }
    }
    else if(property == "LHI" || property == "BMH" || property == "OPT"){
        if (squareblock[16]->getcurrentowner() == squareblock[18]->getcurrentowner() && squareblock[18]->getcurrentowner() == squareblock[19]->getcurrentowner()){
            return true;
        }
    }
    else if(property == "EV1" || property == "EV2" || property == "EV3"){
        if (squareblock[21]->getcurrentowner() == squareblock[23]->getcurrentowner() && squareblock[23]->getcurrentowner() == squareblock[24]->getcurrentowner()){
            return true;
        }
    }
    else if(property == "PHYS" || property == "B1" || property == "B2"){
        if(squareblock[26]->getcurrentowner() == squareblock[27]->getcurrentowner() && squareblock[27]->getcurrentowner() == squareblock[29]->getcurrentowner()){
            return true;
        }
    }
    else if(property == "EIT" || property == "ESC" || property == "C2"){
        if(squareblock[31]->getcurrentowner() == squareblock[32]->getcurrentowner() && squareblock[32]->getcurrentowner() == squareblock[34]->getcurrentowner()){
            return true;
        }
    }
    else if(property == "MC"|| property == "DC"){
        if(squareblock[37]->getcurrentowner() == squareblock[39]->getcurrentowner()){
            return true;
        }
    }
    return false;
}


bool Board::move(Player* p,int move){
    //cout<<"Current location is: "<<p->getLocation()<<endl;
    int m = (p->getLocation() + move) % 40;
    int o = (p->getLocation() + move) / 40;
    p->setcurrentsquare(squareblock[m]);
    p->setLocation(m);
    string sn = squareblock[m]->getName();
    string al = " ";
    al[0] = p->getCharName();
    td->notify(al,sn);
    //cout<<"Location after moving is: "<<p->getLocation()<<endl;
    //cout<<"Location name after moving is: "<<p->getcurrentsquare()->getName()<<endl;
    /*
#ifdef BONUS
    if(m == 0){
        cout<<p->getName()<<" gets extra $200 by landing on COLLECT OSAP"<<endl;
        p->changeSavings(200);
    }
#endif
     */
    if(o == 1 && m != 0) return true;
    return false;
    //cout<<"Location after moving is: "<<p->getLocation()<<endl;
}

void Board::action(Player *p,int r){
    string answer;
    bool b = true;
   /* if(p->getOweAmount()!= 0){
        cout<<p->get
    }
    */
    if (move(p, r)){
        cout<<p->getName()<<"You just got $200 by passing by COLLECT OSAP Square!"<<endl;
        p->changeSavings(200);
    }
    
    //check if it is ownable:  DONE
    int l = p->getLocation();
    if(l == 1 || l == 3 || l == 5 || l == 6 || l == 8 || l == 9 || l==11 || l == 13 || l == 12
       || l == 14 || l == 15 || l == 16 || l == 18 || l == 19 || l == 21 || l == 23
       || l == 24 || l == 25 || l == 26 || l == 27 || l == 28 || l == 29 || l == 31
       || l == 32 || l == 34 || l == 35 || l == 37 || l == 39){
        if(p->getcurrentsquare()->getcurrentowner() == NULL){
            b = false;
            cout<<p->getcurrentsquare()->getName()<<" can be bought now!"<<endl;
            cout<<p->getName()<<": enter 'Y' or 'y' to buy this property."<<endl;
			cout<<"Any other input will be considered as a no and it will be auctioned!"<<endl;
            //string answer;
            cin >> answer;
            if(answer == "Y"||answer=="y"){
                p->getcurrentsquare()->purchase(*p);
            }
            else{
                //ca    ll auction DONE!
                auction(squareblock[p->getLocation()]->getName());
            }
        }
    }
    //call action
    if(b){
    if(p->getLocation() == 2 ||
       p->getLocation() == 17||
       p->getLocation() == 33
      ){
        p->getcurrentsquare()->action(*p);
        int la = p->getLocation();
       if(p->getwincup())
        {
            rimscuptotal++;
            if(rimscuptotal > 4)
            {
                cout << "Sorry, only 4 cups are allowed to be unused in the game."<<endl;
                int c = p->getRimCups();
                while(p->getwincup()){
                    p->getcurrentsquare()->action(*p);
                }
                p->setRimCups(c-1);
            }
        }
	else{
	  p->setcurrentsquare(squareblock[la]);
	action(p,0);
	}
    }
    else{
        p->getcurrentsquare()->action(*p);
    }
    int ll = p->getLocation();
    if(ll == 1 || ll == 3 || ll == 6 || ll == 8 || ll == 9 || ll==11 || ll == 13
       || ll == 14 || ll == 16 || ll == 18 || ll == 19 || ll == 21 || ll == 23
       || ll == 24 || ll == 26 || ll == 27 || ll == 29 || ll == 31
       || ll == 32 || ll == 34 || ll == 37 || ll == 39)
    {
//	cerr<<"1"<<endl;
        if(CheckMono(squareblock[ll]->getName()))
        {
//	cerr<<"2"<<endl;
            if(squareblock[ll]->getImprovement() == 0)
            {
//		cerr<<"3"<<endl;
                if(squareblock[ll]->getcurrentowner() != p)
                {
//		cerr<<"4"<<endl;
                    cout << squareblock[ll]->getName() <<"'s block is in monopoly."<<endl;
                    cout << "Even though there is no improvement on it, still need to change double tuition."<<endl<<"So...."<<endl;
                    squareblock[ll]->action(*p);
                }
            }
        }
        
    }
    if(p->getLocation() == 30)
    {
        p->setcurrentsquare(squareblock[p->getLocation()]);
    }
    }
}
void Board::playroll(Player * p){
    if(rollchance == 1 || rolltime == 3){
        if(rolltime == 3) rollchance=1;
        cout << p->getName()<<": You cannot roll again this turn."<<endl;
    }
    else{
        int dice1;
        int dice2;
        int r;
        if(testing){
            dice1=roll();
            dice2=roll();
            cout <<p->getName()<<": You just rolled "<<dice1<<" and "<<dice2<<endl;
            rolltime++;
            rollchance = 1;
            r = dice1 + dice2;
            dicethisturn = r;
			cout <<p->getName()<<": You will move forward "<<r<<" steps."<<endl;
            //td->drawBoard();
        }
        else{
            dice1 = roll();   // 1-6
            dice2 = roll();
            cout <<p->getName()<<": You roll "<<dice1<<" and "<<dice2<<endl;
            rolltime++;
            rollchance = 1;
            r = dice1 + dice2;
            dicethisturn = r;
			cout <<p->getName()<<": You will move forward "<<r<<" steps."<<endl;
            //td->drawBoard();
        }
        if(p->getTimsLine()){
            if(dice1 == dice2){
                p->setTimsline(false);
                p->setLineturn(0);
                //td->drawBoard();
                action(p,r);
            }
            else{
                if(p->getLineturn() == 2){
                    cout <<p->getName()<<": You have to pay $50 or use a cup to get out of DC Tims"<<endl;
                    if(p->getRimCups() == 0){
                        cout <<p->getName()<<": You don't have any cup and you have to pay"<<endl;
                        //monday: check if they have 50?
                        p->changeSavings(-50);
                        if(p->getOweAmount() != 0){
                            cout<<p->getName()<<": You owe bank "<<p->getOweAmount()<<endl;
                            cout<<p->getName()<<": You can declare 'bankrupt' or get some money to leave DC tims"<<endl;
                        }
                        else {
                            action(p,r);
                            p->setTimsline(false);
                            p->setLineturn(0);
                    }
                    }
                    else
                    {
                        cout <<p->getName()<<": Please enter '$' to pay $50 or 'c' to use a cup"<<endl;
                        cout << "Any other command will be treated as '$'"<<endl;
                        string s;
                        cin >> s;
                        if(s == "c")
                        {
                            int c = p->getRimCups();
                            p->setRimCups(c - 1);
                            rimscuptotal -- ;
                            action(p,r);
                        }
                        else
                        {
                            p->changeSavings(-50);
                            if(p->getOweAmount() != 0){
                                cout<<p->getName()<<": You owe bank "<<p->getOweAmount()<<endl;
                                cout<<p->getName()<<": You can declare 'bankrupt' or get some money to leave DC tims"<<endl;
                            }
                            else{
                            action(p,r);
                         //   p->getcurrentsquare()->action(*p);
                            p->setTimsline(false);
                            p->setLineturn(0);
                            }
                        }
                        //action(p,r);
                    }
                }
                else{
                    
                    cout<<p->getName()<<": You can choose pay $50 or use a cup to leave DC Tims"<<endl;
                    cout<<p->getName()<<": You can enter '$' to pay $50, 'c' to use a cup and 'n' to stay for another round"<<endl;
                    cout <<"Any other command will be treated as 'n'"<<endl;
                    cout<<"If you don't have $50 and still enter '$', you will till in DC Tims"<<endl;
                    string a;
                    cin >> a;
                    if(a == "c")
                    {
                        if(p->getRimCups() == 0){
                            cout <<p->getName()<<": Sorry, you dont have any cups"<<endl;
                        }
                        else{
                            int c1 = p->getRimCups();
                            p->setRimCups(c1-1);
                            rimscuptotal --;
                            action(p,r);
                            p->getcurrentsquare()->action(*p);
                            p->setTimsline(false);
                            p->setLineturn(0);
                        }
                    }
                    else if(a == "$"){
                        if(p->getSavings() > 50){
                        p->changeSavings(-50);
                       // move(p,r);
                        action(p,r);
                       // p->getcurrentsquare()->action(*p);
                        p->setTimsline(false);
                        p->setLineturn(0);
                        }
                        else{
                            int xixi = p->getLineturn();
                            p->setLineturn(xixi+1);
                        }
                    }
                    else{
                        cout<<"You need to still stay in DC TIMS LINE"<<endl;
                        int lt = p->getLineturn();
                        p->setLineturn(lt+1);
                    }
                }
            }
}
            else{
                if(rolltime == 3 && dice1 == dice2){
                    //move to dc tims;
                    cout <<p->getName()<<": rolled 3 doubles in a row!!!! Need to have a rest at DC tims line. "<<endl;
cout<<endl<<"      {  }   }   } }"<<endl;
cout<<"      } {   {  {  {"<<endl;
cout<<"      { }  }    } }"<<endl;
cout<<"      _____________"<<endl;
cout<<"     {_____________} ___"<<endl;
cout<<"     |             |/ _ \\"<<endl;
cout<<"     |               [ ] |"<<endl;
cout<<"     | TIM HORTONS   [_] |"<<endl;
cout<<"     |             |\\___/"<<endl;
cout<<"     \\____________/ "<<endl<<endl;

                    p->setcurrentsquare(squareblock[10]);
                    p->setLocation(10);
                    p->setTimsline(true);
                    p->setLineturn(0);
		    string Al = " ";
		    Al[0] = p->getCharName();
		    td->notify(Al,squareblock[10]->getName());	
                }
                else{
                    if(dice1 == dice2){
                        cout <<p->getName()<<": Congrats! You rolled doubles so you can roll again"<<endl;
                        rollchance = 0;
                        //rolltime++;
                    }
                    action(p,r);
                }
	//	action(p,r);
		//string Al = " ";
		//Al[0] = p->getCharName();
		//td->notify(Al,squareblock[10]
            }
    }
}

void Board::playtrade(Player * p){
    string name;
    string give;
    string receive;
    cin >> name >> give>>receive;
    //call trade;
    istringstream s1(give);
    istringstream s2(receive);
    int m1 = -1;
    int m2 = -1;
    // check if they have enough money to trade!!!!! DONE
    bool b1 = s1 >> m1;
    bool b2 = s2 >> m2;
    if(b1 && b2)
				{
                    cout << p->getName()<<": Sorry, you cannot trade money with money because it makes no sense"<<endl;
                    cout <<"Please re-enter the command!"<<endl;
                    //check improvements in the block!!!!!!! DONE
                }
    else if(!b2 && squareblock[convertSquare(receive)]->getcurrentowner() != convertPlayer(name))
				{
                    cout <<p->getName()<<": Sorry, "<<name<<" does not have "<<receive<<endl;
                    cout <<"Please re-enter the command!"<<endl;
                }
    else if(!b1 && squareblock[convertSquare(give)]->getcurrentowner() != p)
				{
                    cout<<p->getName()<<": Sorry, you don't have "<<give<<endl;
                    cout <<"Please re-enter the command!"<<endl;
                }
    else if(b1 && p->getSavings() < m1)
				{
                    cout <<p->getName()<<": Sorry, you don't have enough money to trade"<<endl;
                }
    else if(b2 && convertPlayer(name)->getSavings() < m2)
				{
                    cout <<p->getName()<<": Sorry, "<<name<<" does not have enough money to trade with you"<<endl;
                }
    else if(!b1 && checkimprove(give))
				{
                    cout <<p->getName()<<": Sorry, there are improvements on the building or the buildings in the same mono block"<<endl;
                    cout << "You cannot trade them"<<endl;
                }
    else if(!b2 && checkimprove(receive))
				{
                    cout <<p->getName()<<": Sorry, there are improvements on the buildings you want or the buildings in the same mono block"<<endl;
                    cout <<"You cannot trade them"<<endl;
                }
    else{
        cout <<name<<", "<<p->getName()<<" wants to trade "<<receive<<" with "<<give<<endl;
        cout <<"If you accept, enter 'accept'. any other input will be treated as 'reject'"<<endl;
        string answer;
        cin >> answer;
        if(answer == "accept")
        {
            if(b1 && !b2)
            {//money -> property
                cout << p->getName()<<": You get" <<receive<<" by $"<<m1<<endl;
                p->changeSavings(-m1);
                convertPlayer(name)->changeSavings(m1);
                squareblock[convertSquare(receive)]->setcurrentowner(p);
                int m1 = p->getTotalWorth();
                int m2 = convertPlayer(name)->getTotalWorth();
                p->setTotalWorth(m1 + squareblock[convertSquare(receive)]->getBuildCost());
                convertPlayer(name)->setTotalWorth(m2 - squareblock[convertSquare(receive)]->getBuildCost());
                //SET THE ASSETLIST!!
                if(receive == "MKV" || receive == "UWP" || receive =="V1" || receive == "REV")
                {
                    int r = p->getResiamount();
                    p->setResiamount(r+1);
                    int q = convertPlayer(name)->getResiamount();
                    convertPlayer(name)->setResiamount(q - 1);
                }
                if(receive == "PAC" || receive == "CIF")
                {
                    int r = p->getGymamount();
                    p->setGymamount(r+1);
                    int q = convertPlayer(name)->getGymamount();
                    convertPlayer(name)->setGymamount(q - 1);
                }
            }
            else if(!b1 && b2)
            {//property -> money;
                cout <<p->getName()<<": You get $"<< m2 <<" by giving "<<give << endl;
                p->changeSavings(m2);
                convertPlayer(name)->changeSavings(-m2);
                squareblock[convertSquare(give)]->setcurrentowner(convertPlayer(name));
                
                int m3 = p->getTotalWorth();
                int m4 = convertPlayer(name)->getTotalWorth();
                p->setTotalWorth(m3 - squareblock[convertSquare(give)]->getBuildCost());
                convertPlayer(name)->setTotalWorth(m4 + squareblock[convertSquare(give)]->getBuildCost());
                //SET THE ASSETLIST!!
                if(give == "MKV" || give == "UWP" || give =="V1" || give == "REV"){
                    int r = p->getResiamount();
                    p->setResiamount(r-1);
                    int q = convertPlayer(name)->getResiamount();
                    convertPlayer(name)->setResiamount(q + 1);
                }
                if(give == "PAC" || give == "CIF"){
                    int r = p->getGymamount();
                    p->setGymamount(r-1);
                    int q = convertPlayer(name)->getGymamount();
                    convertPlayer(name)->setGymamount(q + 1);
                }
                payback(p);
              /*  if(p->getOweAmount() == 0 && p->getTimsLine()){
                    action(p,dicethisturn);
                    p->setLineturn(0);
                    p->setTimsline(false);
                }*/
                //if(p[current]->getOweAmount() != 0){
                //    int o = p[current]->getOweAmount();
                
                //}
            }
            else
            {//property -> property
                cout<<p->getName()<<": You get "<<receive<<" by giving "<<give<<endl;
                squareblock[convertSquare(give)]->setcurrentowner(convertPlayer(name));
                squareblock[convertSquare(receive)]->setcurrentowner(p);
                //SET THE ASSETLIST!!
                int m5 = p->getTotalWorth();
                int m6 = convertPlayer(name)->getTotalWorth();
                p->setTotalWorth(m5 + squareblock[convertSquare(receive)]->getBuildCost());
                convertPlayer(name)->setTotalWorth(m6 - squareblock[convertSquare(receive)]->getBuildCost());
                p->setTotalWorth(m5 - squareblock[convertSquare(give)]->getBuildCost());
                convertPlayer(name)->setTotalWorth(m6 + squareblock[convertSquare(give)]->getBuildCost());
                if(give == "MKV" || give == "UWP" || give =="V1" || give == "REV"){
                    int r = p->getResiamount();
                    p->setResiamount(r-1);
                    int q = convertPlayer(name)->getResiamount();
                    convertPlayer(name)->setResiamount(q + 1);
                }
                if(give == "PAC" || give == "CIF"){
                    int r = p->getGymamount();
                    p->setGymamount(r-1);
                    int q = convertPlayer(name)->getGymamount();
                    convertPlayer(name)->setGymamount(q + 1);
                }
                if(receive == "MKV" || receive == "UWP" || receive =="V1" || receive == "REV"){
                    int r = p->getResiamount();
                    p->setResiamount(r+1);
                    int q = convertPlayer(name)->getResiamount();
                    convertPlayer(name)->setResiamount(q - 1);
                }
                if(receive == "PAC" || receive == "CIF"){
                    int r = p->getGymamount();
                    p->setGymamount(r+1);
                    int q = convertPlayer(name)->getGymamount();
                    convertPlayer(name)->setGymamount(q - 1);
                }
            }
        }
        else{
            cout << p->getName()<<": Sorry, "<<name <<" doesn't accept your offer! "<<endl;
        }
    }
}

void Board::play(){
td->drawBeginning();
    init();
    if(loading==false){
		cout<<"$$$$$$$$$$$$$$   NORMAL MODE   $$$$$$$$$$$$$$"<<endl;
		cout<<"Enter a number to indicate the number of players [2-6]."<<endl;
		int number;
		cin >> number;
        string namearr[6];
        for(int i = 0; i < 6; i++){
            namearr[i] = "";
        }
        int nameindex = 0;
        if(cin.eof()||cin.fail()) return;
		while(number > 6 || number < 2){
			if(cin.eof() || cin.fail()) return;
			cout << "Please enter a number between 2 and 6!"<<endl;
			cin >> number;
		}
		totalplayer = number;
        stillinplayer = totalplayer;
		for(int i = 0; i < totalplayer; i++)
		{
			cout << "Please enter the name for player"<<i+1<<endl;
			string name;
           // char c = 'X';
            //bool bruce = false;
			while(cin >> name)
			{
                bool checkname = false;
                for(int i = 0; i < nameindex; i++){
                    if(namearr[i] == name){
                        checkname = true;
                    }
                }
				if(name == "BANK"){
					cout<<"Sorry, BANK is used for 'BANK' in the game. Please choose another name"<<endl;
				}
                else if(checkname){
                    cout<<"Sorry, "<<name<<" has been used by another player. Please choose another name"<<endl;
                }
                else {
                   /* if(name == "Bruce"){
                        cout << "Please choose a piece to represent you on the board. Avalible pieces are: "<<endl;
                        //cout << "Please choose a piece to represent you on the board. Avalible pieces are: "<<endl;
                        if(checklist['G'] == true)
                        {
                            cout << "You can enter 'G' for Goose"<<endl;
                        }
                        if(checklist['B'] == true){
                            cout << "You can enter 'B' for GRT Bus"<<endl;
                        }
                        if(checklist['D'] == true){
                            cout << "You can enter 'D' for Tim Hortons Doughnut"<<endl;
                        }
                        if(checklist['P'] == true){
                            cout << "You can enter 'P' for Professor"<<endl;
                        }
                        if(checklist['S'] == true){
                            cout << "You can enter 'S' for Student"<<endl;
                        }
                        if(checklist['$'] == true){
                            cout << "You can enter '$' for Money"<<endl;
                        }
                        if(checklist['L'] == true){
                            cout << "You can enter 'L' for Laptop"<<endl;
                        }
                        if(checklist['T'] == true){
                            cout << "You can enter 'T' for Pink tie"<<endl;
                        }
                        string extname;
                        cin >> extname;
                        if(extname == "Wayne"){
                            name = name + " " + extname;
                            bruce = true;
                        }
                        else{
                            c = extname[0];
                        }
                    }
                    */
                    namearr[nameindex] = name;
                    nameindex ++;
                break;
                }
			}
                cout << "Please choose a piece to represent you on the board. Avalible pieces are: "<<endl;
			if(checklist['G'] == true)
			{
				cout << "You can enter 'G' for Goose"<<endl;
			}
			if(checklist['B'] == true){
				cout << "You can enter 'B' for GRT Bus"<<endl;
			}
			if(checklist['D'] == true){
				cout << "You can enter 'D' for Tim Hortons Doughnut"<<endl;
			}
			if(checklist['P'] == true){
				cout << "You can enter 'P' for Professor"<<endl;
			}
			if(checklist['S'] == true){
				cout << "You can enter 'S' for Student"<<endl;
			}
			if(checklist['$'] == true){
				cout << "You can enter '$' for Money"<<endl;
			}
			if(checklist['L'] == true){
				cout << "You can enter 'L' for Laptop"<<endl;
			}
			if(checklist['T'] == true){
				cout << "You can enter 'T' for Pink tie"<<endl;
			}
            
			char c;
			string s;
			while(cin >>s)
			{
				c=s[0];
				if(cin.eof()|| cin.fail()) break;
				if(s.length() != 1)
				{
					cout <<"Please re-enter a character showing above to indicate the player"<<endl;
				}
				else
                {  // if(c == 'X'){
		//			c = s[0];
                //}
					if(c != 'G' && c != 'B' && c != 'D' && c != 'P' && c != 'S' && c != '$' && c != 'L' && c != 'T'){
						cout <<"Please re-enter a character showing above to indicate the player"<<endl;
					}
					else if(checklist[c] == false){
						cout << "Sorry, the character has be use, Please re-enter a char"<<endl;
					}
					else
					{
						p[i] = new Player(name,c,0,1500,0,false,0,this);
						p[i]->setcurrentsquare(squareblock[0]);
                        #ifdef BONUS
                        if(p[i]->getName() == "BONNIE"){
                            p[i]->changeSavings(1500 * 99);
                            p[i]->setTotalWorth(1500 * 100+750);
                            squareblock[37]->setcurrentowner(p[i]);
                            squareblock[39]->setcurrentowner(p[i]);
                        }
                        #endif
                        
						checklist[c]=false;
						string al = " ";
						al[0] = c;
						td->notify(al,"COLLECTOSAP");
						break;
					}
				}
			}
		}
		td->drawBoard();
	}
	else
	{
		cout<<"$$$$$$$$$$$$$$      LOADING MODE      $$$$$$$$$$$$$"<<endl;
		load(readfilename);
        stillinplayer = totalplayer;
		td->drawBoard();
	}
    // set the player done.
    
    string cmd;
    //	bool ifquit = true;
    while(current <= totalplayer)// &&  ifquit)
	{
        if(cin.fail() || cin.eof()) break;
	while(cin >> cmd)
		{
	   if(cmd == "quit"||cmd=="QUIT"||cmd=="Quit"){
	cout<<"Oopsssssss, You just quit the game without saving, BYE BYE!!!"<<endl;
//	ifquit = false;
	return;}

            if(cmd == "roll")
			{
                if(p[current]->getOweAmount()!= 0){
                    cout<<p[current]->getName()<<": You have to pay back your owes before roll"<<endl;
                }
                else{
                playroll(p[current]);
                //    td->drawBoard();
                }
			}
            else if(cmd == "next"){
                if(p[current]->getOweAmount() != 0 )
				{
                    cout <<p[current]->getName()<<": Still owe other player or bank money"<<endl;
                    cout << "So cannot finish your turn until you pay it back"<<endl;
                }
				else if(rollchance == 0)
				{
                    cout <<p[current]->getName()<<": You still have chance to roll"<<endl;
                    cout << "You cannot finish your turn when you still have rolling chance"<<endl;
                }
                else
				{
                    rollchance = 0;
                    rolltime = 0;
                    
                    //check player is null!!!! DONE!!
                    if(current == totalplayer - 1)
					{
                    current = 0;
                    }
                    else {
                        current++;
		//	cout<<p[current]->getName()<<", it is your turn"<<endl;
                    }
                    while(stillingame[current] == -1)
					{
                        if(current == totalplayer -1)
						{
                            current = 0;
                        }
                        else{
                            current++;
                        }
                    }
                    //break;
					td->drawBoard();
					cout<<p[current]->getName()<<", it is your turn"<<endl;
				}
			}
            else if(cmd == "trade")
			{
                playtrade(p[current]);
			}
            else if(cmd == "improve"){
                string property;
                string action;
                cin >> property>>action;
		if(property != "AL" && property != "ML" && property != "ECH"&&
		  property!= "PAS" && property != "HH" && property!= "RCH" &&
		 property != "DWE" && property != "CPH"&& property != "LHI"&&
		 property != "BMH" && property != "OPT"&& property != "EV1"&&
		 property != "EV2" && property != "EV3" && property != "PHYS"&&
		 property != "B1"  && property != "B2" && property != "EIT" &&
		 property !="ESC"  && property != "C2" && property != "MC" &&
		 property != "DC")
		{
			cout<<"Sorry can't improve non-academic buildings!"<<endl;
			cout<<"re-enter the command!"<<endl;
		}
                else if(!CheckMono(squareblock[convertSquare(property)]->getName())){
                    cout<<"Sorry, cannot buy or sell improvment of a property in which you don't have the monopoly"<<endl;
                     cout <<"Please re-enter the command!"<<endl;
                }
                else if(action == "buy"){
                    //call improve;
                    squareblock[convertSquare(property)]->improve(*p[current]);
                    td->notify(property,squareblock[convertSquare(property)]->getImprovement());
                }
                else if(action == "sell"){
                //call sell improve;
                    squareblock[convertSquare(property)]->sellimprove(*p[current]);
                    td->notify(property,squareblock[convertSquare(property)]->getImprovement());
                    payback(p[current]);
                    /*if(p[current]->getOweAmount() == 0 && p[current]->getTimsLine()){
                        this->action(p[current],dicethisturn);
                        p[current]->setLineturn(0);
                        p[current]->setTimsline(false);
                    }
                     */

                }
                else{
                    cout << "You enter a wrong command. Please re-enter it or enter 'help' to see all valid command"<<endl;
                }
            }
            else if(cmd == "mortgage"){
                string property;
                cin >> property;
                //mortgage
                if(property == "AL" || property == "ML" || property == "ECH" ||
                   property == "PAS"|| property == "HH" || property == "RCH" ||
                   property == "DWE"|| property == "CPH"|| property == "LHI" ||
                   property == "BMH"|| property == "OPT"|| property == "EV1" ||
                   property == "EV2"|| property == "EV3"|| property == "PHYS"||
                   property == "B1" || property == "B2" || property == "EIT" ||
                   property == "ESC"|| property == "C2" || property == "MC"  ||
                   property == "DC"){
                    if(checkimprove(property)){
                        //check other propery in the mono block!!!!!
                        cout << "Must sell the improvements before mortgage!"<<endl;
                    }
                    else{
                        squareblock[convertSquare(property)]->mortgage(*p[current]);
                    }
                }
                else if(property == "MKV" || property == "UWP"  || property == "V1"||
                        property == "REV" || property == "PAC"  || property == "CIF"){
                    squareblock[convertSquare(property)]->mortgage(*p[current]);
                }
                else{
                    cout<<"May want to mortgage a unownable property or you enter a wrong property."<<endl;
                    cout <<"Please re-enter the command!"<<endl;
                }
                payback(p[current]);
               /* if(p[current]->getOweAmount() == 0 && p[current]->getTimsLine()){
                    action(p[current],dicethisturn);
                    p[current]->setLineturn(0);
                    p[current]->setTimsline(false);
                }*/
                
            }
            else if(cmd == "unmortgage"){
                string property;
                cin >> property;
                //call unmortgage;
                //NOTE:CHECK SELL IMPROVEMENTS!!!!! Done
               /* if(property == "AL" || property == "ML" || property == "ECH" ||
                   property == "PAS"|| property == "HH" || property == "RCH" ||
                   property == "DWE"|| property == "CPH"|| property == "LHI" ||
                   property == "BMH"|| property == "OPT"|| property == "EV1" ||
                   property == "EV2"|| property == "EV3"|| property == "PHYS"||
                   property == "B1" || property == "B2" || property == "EIT" ||
                   property == "ESC"|| property == "C2" || property == "MC"  ||
                   property == "DC" ||property == "MKV" || property == "UWP"  || property == "V1"||
                   property == "REV" || property == "PAC"  || property == "CIF")
				   {*/
               // cin >> property;
                //call unmortgage;
                //NOTE:CHECK SELL IMPROVEMENTS!!!!! Done
                if(property == "AL" || property == "ML" || property == "ECH" ||
                   property == "PAS"|| property == "HH" || property == "RCH" ||
                   property == "DWE"|| property == "CPH"|| property == "LHI" ||
                   property == "BMH"|| property == "OPT"|| property == "EV1" ||
                   property == "EV2"|| property == "EV3"|| property == "PHYS"||
                   property == "B1" || property == "B2" || property == "EIT" ||
                   property == "ESC"|| property == "C2" || property == "MC"  ||
                   property == "DC" ||property == "MKV" || property == "UWP"  || property == "V1"||
                   property == "REV" || property == "PAC"  || property == "CIF")
				   {
                    
						squareblock[convertSquare(property)]->unmortgage(*p[current]);
                   }
                else
				{
                    cout<<"You may want to mortgage a unownable property or you enter a wrong property."<<endl;
                    cout <<"Please re-enter the command!"<<endl;
                }
		//	}
	}
            else if(cmd == "bankrupt"){
                //bankrupt;
                //bankrupt;
                if(p[current]->getOweAmount()==0){
                    cout <<"Sorry, "<<p[current]->getName()<<" cannot declare bankruptcy!"<<endl;
                }
                else{
                    int lbr = p[current]->getLocation();
                    if(lbr == 1 || lbr == 3 || lbr == 5 || lbr == 6 || lbr == 8 || lbr == 9 || lbr==11 || lbr == 13 || lbr == 12
                       || lbr == 14 || lbr == 15 || lbr == 16 || lbr == 18 || lbr == 19 || lbr == 21 || lbr == 23
                       || lbr == 24 || lbr == 25 || lbr == 26 || lbr == 27 || lbr == 28 || lbr == 29 || lbr == 31
                       || lbr == 32 || lbr == 34 || lbr == 35 || lbr == 37 || lbr == 39){
                        
                        if(squareblock[lbr]->getcurrentowner() == NULL){
                            bankruptcy(*p[current],NULL);
                        }
                        else{
                            bankruptcy(*p[current],squareblock[lbr]->getcurrentowner());
                        }
                    }
                    else{
                        bankruptcy(*p[current],NULL);
                    }
                    stillingame[current] = -1;
                    //stillinplayer--;
              //  }
                int checkwin = 0;
                for(int i = 0; i < totalplayer; i ++){
                    if(p[i] != NULL){
                        checkwin++;
                    }
                }
                if(stillinplayer == 1){
                    for(int i = 0 ; i < totalplayer; i++){
                        if(p[i] != NULL){
                        //    cout << "CONGRATULATION!!!"<<endl;
                         //   cout <<p[i]->getName()<<" WINS THE GAME!!!!!!"<<endl;
                            td->drawEnding(p[i]->getName());
                      
                            return;
                        }
                    }
                }
                else{
                    rollchance = 0;
                    rolltime = 0;
                    if(current == totalplayer - 1)
                    {
                        current = 0;
                    }
                    else {
                        current++;
                    }
                    while(stillingame[current] == -1)
                    {
                        if(current == totalplayer -1)
                        {
                            current = 0;
                        }
                        else{
                            current++;
                        }
                    }
			cout<<p[current]->getName()<<", it is your turn."<<endl;
                }
            }}
            else if(cmd == "asset"){
                //show assets;
                if(p[current]->getOweAmount() != 0){
                    cout <<"Sorry, cannot see assets when you decide how to pay"<<endl;
                }
                else{
                    showassets(p[current]);
                }
            }
            else if(cmd == "save"){
                string file;
                cin >> file;
                //save the game to the file
		save(file);
		cout<<"File is saved successfully to "<<file<<endl;
            }
            else if(cmd == "help"){
                cout<<"The valid inputs are:"<<endl;
                cout<<"roll"<<endl;
                cout<<"next"<<endl;
                cout<<"trade <name> <give> <receive>"<<endl;
                cout<<"improve <property> buy/sell"<<endl;
                cout<<"mortgage <property>"<<endl;
                cout <<"unmortgage <property>"<<endl;
                cout<<"bankrupt"<<endl;
                cout <<"asset"<<endl;
                cout<<"save <filename>"<<endl;
				cout<<"quit"<<endl;
cout<<"CAUTION: 'quit' will end the game without saving!"<<endl;
/*#ifdef BONUS
cout<<"quitgame"<<endl;
cout<<"CAUTION: 'quitgame' will remove you from the game and other players continue the game."<<endl;
#endif*/
            }
            /*
#ifdef BONUS
            else if(cmd == "quitgame"){
                rollchance = 0;
                rolltime = 0;
               / string al=" ";
                al[0]=p[current]->getCharName();
                td->notifyRemove(al);
                delete p[current];
                stillinplayer--;
                p[current]=NULL;
		/
		cout<<p[current]->getName()<<" just quits the game"<<endl;
                bankruptcy(*p[current],NULL);
		//removePlayer(p[current]->getName());
                if(current == totalplayer - 1) current = 0;
                else current++;
               // cout << p[current]->getName()<<", it is your turn"<<endl;
                if(stillinplayer == 1){
                    for(int i = 0 ; i < totalplayer; i++){
                        if(p[i] != NULL){
                            //    cout << "CONGRATULATION!!!"<<endl;
                            //   cout <<p[i]->getName()<<" WINS THE GAME!!!!!!"<<endl;
                            td->drawEnding(p[i]->getName());
                            
                            return;
                        }
                    }
                }
                cout << p[current]->getName()<<", it is your turn"<<endl;
            }
#endif 
       */
            else{
                cout<<"Sorry, the command is invalid. You can enter 'help' to see all valid commands"<<endl;
				}	
		}
	}

 }

void Board::save(string filename)
{

	ofstream myfile;
	myfile.open(filename.c_str());
    myfile << totalplayer << endl;
    for(int i=0;i<totalplayer;i++)
    {
	if(p[i]!=NULL)
	{
		if(p[i]->getLocation()==10)
		{
			if(p[i]->getTimsLine()==true)
			{
	               		 myfile<<p[i]->getName()<<" "<<p[i]->getCharName()<<" "<<p[i]->getRimCups()<<" "<<p[i]->getSavings()<<" "<<p[i]->getLocation()<<" 1 "<<p[i]->getLineturn()<<"\n";
			}
			else
			{
                    		myfile<<p[i]->getName()<<" "<<p[i]->getCharName()<<" "<<p[i]->getRimCups()<<" "<<p[i]->getSavings()<<" "<<p[i]->getLocation()<<" 0"<<"\n";
			}
                }
		else
		{
			myfile<<p[i]->getName()<<" "<<p[i]->getCharName()<<" "<<p[i]->getRimCups()<<" "<<p[i]->getSavings()<<" "<<p[i]->getLocation()<<"\n";
		}
	}
    }
    for(int j=0;j<40;j++)
    {
	if(squareblock[j]->getOwnable()==true)
	{
		string own="BANK";
		if(squareblock[j]->getcurrentowner()!=NULL)
		{
			own=squareblock[j]->getcurrentowner()->getName();
		}
		int improvement=0;
		if(squareblock[j]->getAcBuilding()==true)
		{
			improvement=squareblock[j]->getImprovement();
		}
		if(squareblock[j]->mortCondition()==true)
		{
			improvement=-1;
		}
		myfile<<squareblock[j]->getName()<<" "<<own<<" "<<improvement<<"\n";
	}
    }
    myfile.close();
 }

void Board::load(string filename)
{
  string line;
  ifstream myfile (filename.c_str());
  if (myfile.is_open())
  {
    int playersum;
    myfile>>playersum;
    totalplayer=playersum;
    for(int i=0;i<playersum;i++)
	{
		string name;
		char charname;
		int money, position, timscups, timsline, lineturn;
		myfile>>name>>charname>>timscups>>money>>position;
		string A=" ";
		A[0]=charname;
		td->notify(A, squareblock[position]->getName());
		rimscuptotal+=timscups;
		if(position==10)
		{
			myfile>>timsline;
			if(timsline==1)
			{
				myfile>>lineturn;
				p[i]=new Player(name,charname,timscups,money,position,true,lineturn,this);
				/*
				NEED TO MAKE SURE TIMSCUPS TOTAL IS HANDLED.
				*/
		/*	#ifdef BONUS
			if(p[i]->getName() == "BONNIE){
				p[i]->changeSavings(1500 * 99);
				p[i]->setTotalWorth(1500 * 100);
				squareblock[37]->setcurrentowner(p[i]);
				squareblock[39]->setcurrentowner(p[i]);
			}
			#endif*/
			}
			else
			{
				p[i]=new Player(name,charname,timscups,money,position,false,0,this);
			}
		}
		else
		{
			p[i]=new Player(name,charname,timscups,money,position,false,0,this);
		}
	}

		for (int i=0; i<28; i++) 
		{
		string buildingname;
		string buildingowner;
	 	int improvements;
			myfile>>buildingname>>buildingowner>>improvements;
			if (buildingowner != "BANK")
			{
			for (int j=0; j<40; j++) {
				if (squareblock[j]->getOwnable()==true) {
					if (buildingname==squareblock[j]->getName()) {
						squareblock[j]->setOwner(buildingowner);
						squareblock[j]->setcurrentowner(convertPlayer(buildingowner));
						for (int h=0; h <playersum; h++) 
						{
							if (buildingowner==p[h]->getName())
							{
								//TODO*************
								//set asset list
								//**********
								if(improvements==-1)
								{//mortgage
									//TODO FIX BELOW SETMORTAGE
									squareblock[j]->setMortgage(true);
								}
								else if(improvements==0)
								{	p[h]->setTotalWorth(p[h]->getTotalWorth()+squareblock[j]->getBuildCost());
									if(buildingname=="UWP"||buildingname=="MKV"||buildingname=="REV"||buildingname=="V1")
									{//residence
										p[h]->setResiamount(p[h]->getResiamount()+1);
									}
									else if(buildingname=="CIF"||buildingname=="PAC")
									{//gym
										p[h]->setGymamount(p[h]->getGymamount()+1);
								    }
								}
								else
								{	p[h]->setTotalWorth(p[h]->getTotalWorth()+squareblock[j]->getBuildCost());
									td->notify(buildingname,improvements);
									squareblock[j]->setImprovement(improvements);
									//if(squareblock[j]->getAcBuilding()==true)
									//{
									//	td->notify(buildingname, improvements);
		    								p[h]->setTotalWorth(p[h]->getTotalWorth()+(squareblock[j]->getImproveCost())*improvements);

									//}
								}
							}
						}
					}
				}
			}
		}
	}
			myfile.close();

	}				
  else 
  {cout << "Sorry no file with this name exist!";} 
}


void Board::bankruptcy(Player& p1, Player* p2) {
    bool auctionarray[40];
    int auctionnumber = 0;
    bool bank = false;
    for(int i = 0; i< 40; i++){
        auctionarray[i] = false;
    }
	if(p2==NULL)
	{
        bank = true;
		cout<<"Player "<<p1.getName()<<" just declared bankruptcy!"<<endl;
		cout<<"All of Player "<<p1.getName()<< "'s money will go to the school(aka the bank)!"<<endl;
		for (int i=0; i<40; i++)
		{
           // cout<<"1"<<endl;
			if(squareblock[i]->getOwnable()==true)
			{
               // cout<<"2"<<endl;
				if(p1.getName()==squareblock[i]->getOwner())
				{
                  //  cout<<"3"<<endl;
					//change current owner
					squareblock[i]->setOwner("");
					squareblock[i]->setcurrentowner(NULL);
                   // cout<<"4"<<endl;
					//TODO********** if it is mortagaged property
					if(squareblock[i]->mortCondition()==true)
					{
						squareblock[i]->setMortgage(false);
					}
					//TODO**********AUCTION ON THIS BUILDING
                    auctionarray[i] = true;
                    auctionnumber++;
				}
			}
		}
		rimscuptotal -= p1.getRimCups();
	}
	else
	{
		cout<<"Player "<<p1.getName()<<" just declared bankruptcy while oweing Player "<<p2->getName()<<" money."<<endl;
		cout<<"All of Player "<<p1.getName()<< "'s assets will go to Player "<<p2->getName()<<endl;
		//p2->changeSavings(p1.getSavings());//first transfer money
		for (int i=0; i<40; i++)
		{
			if(squareblock[i]->getOwnable()==true)
			{
				if(p1.getName()==squareblock[i]->getOwner())
				{
					//change current owner
					squareblock[i]->setOwner(p2->getName());
					squareblock[i]->setcurrentowner(convertPlayer(p2->getName()));			
					//update p2's asset list
					//TODO********** if it is mortagaged property
					if(squareblock[i]->mortCondition()==true)
					{
                        //cout<<p2->getName()<<endl;
                        //cout<<squareblock[i]->getName();
                        
                        cout<<squareblock[i]->getName()<<" is mortgaged"<<endl;
                        cout<<p1.getName()<<" need to immediately pay 10 percent of the value of "<<squareblock[i]->getName()<<" because it is mortagaged!"<<endl;
                        cout<<p2->getName()<<", if you want to unmortgage it now, you dont need to pay it!"<<endl;
                        cout<<p2->getName()<<", do you want to unmortgage it now?"<<endl;
                        cout<<"Enter 'y' to mortgage it, any other input will be treated as no"<<endl;
                        string m;
                        cin >> m;
                        if(m == "y"){
                            squareblock[i]->unmortgage(*p2);
                        }
                        else{
						
                            p2->changeSavings(-(squareblock[i]->getBuildCost()/10));
                            p2->setTotalWorth(p2->getTotalWorth()-(squareblock[i]->getBuildCost()/10));
                            cout<<squareblock[i]->getName()<<" is still mortgaged and can be unmortgaged later."<<endl;
                    }
                    }
                        cout<<squareblock[i]->getName()<<" is "<<p2->getName()<<"'s."<<endl;
				}
			}
		}
		p2->setGymamount(p2->getGymamount()+p1.getGymamount());
		p2->setResiamount(p2->getResiamount()+p1.getResiamount());
		p2->setRimCups(p1.getRimCups() + p2->getRimCups());//transfer rim cups
		p2->setTotalWorth(p2->getTotalWorth()+p1.getTotalWorth());//transfer total worth
	}
	cout<<"Game over for Player "<<p1.getName()<<" :( "<<endl<<"DON'T CRY. WE WILL MISS U <3"<<endl;
    string bn = p1.getName();
	removePlayer(p1.getName());//set p[removedplayer] to NULL
    if(bank && auctionnumber != 0){
        cout<<"NOW, Let's auction "<<bn<<"'s property"<<endl;
        for(int i = 0; i < 40; i++){
            if(auctionarray[i]){
                auction(squareblock[i]->getName());
            }
        }
    }
}
void Board::removePlayer(string playername)
{
//	td->notifyremove(playername);
	for(int i=0;i<totalplayer;i++)
	{
		if(p[i]!=NULL)
		{
			if(p[i]->getName()==playername)
			{
		string al=" ";
		al[0]=p[i]->getCharName();
		td->notifyRemove(al);
                delete p[i];
                stillinplayer--;
				p[i]=NULL;
			}
		}
	}
}
