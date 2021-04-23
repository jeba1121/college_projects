// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Project 3 class General


#include <iostream>
#include <math.h>
#include <array>
#include <string>
#include "General.h"
using namespace std;

string General::getGenUsername()
{
    return genUsername;
}
int General::getGenArmySize()
{
    return armySize;
}
int General::getGenMorale()
{
    return morale;
}
int General::getGenStrength()
{
    return strength;
}
void General::setGenArmySize(int a)
{
    armySize=a;
}
void General::setGenMorale(int m)
{
    morale=m;
}
void General::setGenStrength(int s)
{
    strength=s;
}
int General::calcGenArmySize(int playerArmy)
{
    armySize-=playerArmy; //I WILL ADJUST THESE FUNCTION WITH THE DIE FUNCTION IMPLEMENTED LATER
    return armySize; 
}
int General::calcGenMorale(int playerMorale)
{
    morale-=playerMorale; //^
    return morale;
}
int General::calcGenStrength(int playerStrength)
{
    strength-= playerStrength;
    return strength;
}
