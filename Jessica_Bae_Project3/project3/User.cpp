// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Project 3 class User

#include<iostream>
#include<string>
#include<array>
#include <fstream>
#include <math.h>
#include "User.h"

using namespace std;


User::User(string u)
{
    username=u;
}
string User::getUsername()
{
    return username;
}
int User::getArmySize()
{
    return armySize;
}
int User::getMorale()
{
    return morale;
}
int User::getStrength()
{
    return strength;
}
void User::setUsername(string u)
{
    username=u;
}
void User::setArmySize(int a)
{
    armySize=a;
}
void User::setMorale(int m)
{
    morale=m;
}
void User::setStrength(int s)
{
    strength=s;
}

int User::calcArmySize(int dieRoll)
{
    armySize+=dieRoll; //I WILL ADJUST THESE FUNCTION WITH THE DIE FUNCTION IMPLEMENTED LATER
    return armySize; 
}
int User::calcMorale(int dieRoll)
{
    morale+=dieRoll; //^
    return morale;
}
int User::calcStrength(int dieRoll)
{
    strength+=dieRoll;
    return strength;
}
void User::readPlayers(string fileName)
{
    ifstream file;
    file.open(fileName);
    string line,player;
    if(file.is_open())
    {
        while(getline(file,line))
        {
            if(line.length()>0)
            {
                player=line.substr(0,line.find(","));
                for(int i=0;i<1;i++)
                {
                    stats[i]=player;
                    cout<<stats[i]<<endl;
                }
            }
        }
    }
    file.close();
}