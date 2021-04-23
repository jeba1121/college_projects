// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Homework 7 - Problem # 4

#include "User.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

/**
 * create member functions from class User
 * set default and parameterized constructer definitions
 * getUsername returns username as string
 * setUsername void- assigns username the value of input string
 * getRatingsAt(int idx) int- returns rating scored at that index, if index>size of ratings array, return -1
 * setRatingsAt(int indx,int value) bool- sets the rating to value at the specified indx, if indx is within bounds of the array and value is between 0-5. returns true if updated, falst if not
 * getNumRatings returns numRatings as int
 * setNumRatings void- assigns numRatings to input 
 * getSize returns size as int
*/
 
User::User()
{
    username="";
    numRatings=0;
    size=50;
    for(int i=0;i<size;i++)//initialize ratings back to 0
    {
         ratings[i]=0;
    }
}

User::User(string uname,int newRatings[],int newNum)
{
    size=50;
    for(int i=0;i<size;i++)
    {
        ratings[i]=0;
    }
    username=uname;
    if(newNum<=size)
    {
        numRatings=newNum;
    }
    
    for(int i=0;i<numRatings;i++)//numRatings cannot be greater than 50
    {
        ratings[i]=newRatings[i];
    }
}
string User::getUsername()
{
    return username;
}
void User::setUsername(string u)
{
    username=u;
}
int User::getRatingAt(int idx)//return rating scored at that index if index is less than numRatings
{
    if(idx>=size)
    {
        return -1;
    }
    else
    {
        return ratings[idx];
    }
    
}
bool User::setRatingAt(int idx, int value)
{
    if((idx<size) && idx>=0)//if index within bounds of array and value is 0-5
    {
        if(value>=0 && value<=5)
        {
            ratings[idx]=value;//update rating to value at specified index
            return true;
        }
    }

    return false;
}
int User::getNumRatings()
{
    return numRatings;
}
void User::setNumRatings(int value)
{
    numRatings=value;
}
int User::getSize()
{
    return size;
}