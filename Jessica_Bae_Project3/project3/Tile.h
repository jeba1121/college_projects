// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Project 3 class Tile

#include <iostream>
#include <math.h>
#include <array>
#include <string>

using namespace std;

class Tile
{
    public:
        Tile()
        {
            space=0;
            probability=100;
            fightResult=true;
            luck=true;
        };
        //getters
        int getSpace(); //space is the sum of rolls
        int getProbability(); //return the calculated prob of that space
        
        //setters
        int setSpace(int s);
        int setProbability(int p);

        //functions
        int calcProbability(); //calc probability out of 100 using rand
        bool calcLuck(int probability); //if probability is luck, roll die and if luck is 3-6 than=true
        
  
    private:
        int space;
        int probability;
        bool fightResult;
        bool luck;
};
