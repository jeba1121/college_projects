// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Project 3 class King Doompa


#include <iostream>
#include <math.h>
#include <array>
#include <string>

class Doompa
{
    public:
        //default constructer
        Doompa()
        {
            armySize=20;
            morale=20;
            strength=20;

        };
        //getters
        int getKingArmySize();
        int getKingMorale();
        int getKingStrength();
        
        //setters
        void setKingArmySize(int a);
        void setKingMorale(int m);
        void setKingStrength(int s);
        
        //functions
        int calcKingArmySize(int playerArmy);
        int calcKingMorale(int playerMorale);
        int calcKingStrength(int playerArmy);
        
        
        
    private:
        int armySize;
        int morale;
        int strength;
};