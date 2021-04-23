// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Project 3 class User

#include<iostream>
#include<string>
#include<array>
#include <math.h>

using namespace std;


class User
{
    public:
        //default constructer
        User()
        {
            username="";
            armySize=0;
            morale=0;
            strength=0;
        };
        User(string username);
        //getters
        string getUsername();
        int getArmySize();
        int getMorale();
        int getStrength();
        
        //setters
        void setUsername(string u);
        void setArmySize(int a);
        void setMorale(int m);
        void setStrength(int s);
        
        
        //functions
        //int readStats(string fileName,string username);
        int calcArmySize(int dieRoll);
        int calcMorale(int dieRoll);
        int calcStrength(int dieRoll);
        void readPlayers(string fileName);
        
        
    private:
        string username;
        int armySize;
        int morale;
        int strength;
        string stats[4];
};