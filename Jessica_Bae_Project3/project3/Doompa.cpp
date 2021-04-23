// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Project 3 class Doompa


#include <iostream>
#include <math.h>
#include <array>
#include <string>
#include"Doompa.h"
using namespace std;

int Doompa::getKingArmySize()
{
    return armySize;
}
int Doompa::getKingMorale()
{
    return morale;
}
int Doompa::getKingStrength()
{
    return strength;
}
void Doompa::setKingArmySize(int a)
{
    armySize=a;
}
void Doompa::setKingMorale(int m)
{
    morale=m;
}
void Doompa::setKingStrength(int s)
{
    strength=s;
}
int Doompa::calcKingArmySize(int playerArmy)
{
    armySize-=playerArmy; //I WILL ADJUST THESE FUNCTION WITH THE DIE FUNCTION IMPLEMENTED LATER
    return armySize; 
}
int Doompa::calcKingMorale(int playerMorale)
{
    morale-=playerMorale; //^
    return morale;
}
int Doompa::calcKingStrength(int playerStrength)
{
    strength-= playerStrength;
    return strength;
}
