// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Project 3 class General


#include <iostream>
#include <math.h>
#include <array>
#include <string>
using namespace std;

class General
{
    public:
        //default constructer
        General()
        {
            genUsername="General Oomp";
            armySize=10;
            morale=10;
            strength=10;
            
        };
        //getters
        string getGenUsername();
        int getGenArmySize();
        int getGenMorale();
        int getGenStrength();
        
        //setters
        void setGenArmySize(int a);
        void setGenMorale(int m);
        void setGenStrength(int s);
        
        //functions
        int calcGenArmySize(int playerArmy);
        int calcGenMorale(int playerMorale);
        int calcGenStrength(int playerArmy);
        
        
        
    private:
        string genUsername;
        int armySize;
        int morale;
        int strength;
        
};