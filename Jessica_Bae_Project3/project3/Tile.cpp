// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Project 3 class Tile

#include <iostream>
#include <math.h>
#include <array>
#include <string>
#include "Tile.h"

using namespace std;


int Tile::getSpace()
{
    return space;
}
int Tile::getProbability()
{
    return probability;
}
int Tile::setSpace(int s)
{
    space=s;
}
int Tile::setProbability(int p)
{
    probability=p;
}
int Tile::calcProbability()
{
    srand(time(NULL));
    int prob=random() % 100 + 1;
    return prob;
}
bool Tile::calcLuck(int probability)
{
    if(probability>=0 && probability<=50)
    {
        luck=true;
    }
    if(probability>50 && probability<=100)
    {
        luck=false;
    }
    return luck;
}
