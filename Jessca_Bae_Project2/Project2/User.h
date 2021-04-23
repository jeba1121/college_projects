// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Homework 7 - Problem # 4

#include<iostream>
#include<string>
#include<array>
using namespace std;

/**
 * create class User
 * private Data members: string username, int array ratings, int numRatings, int size-capacity of the array at 50
 * set default constructer: username is empty string, numRatings to 0, size to 50, all elements of ratings array to 0
 * parameterized constructer: takes string, array of int, one int for initializeing username, ratings, and numRatings(numRatings cannot be>50)
 * getUsername returns username as string
 * setUsername void- assigns username the value of input string
 * getRatingsAt(int idx) int- returns rating scored at that index, if index>size of ratings array, return -1
 * setRatingsAt(int indx,int value) bool- sets the rating to value at the specified indx, if indx is within bounds of the array and value is between 0-5. returns true if updated, falst if not
 * getNumRatings returns numRatings as int
 * setNumRatings void- assigns numRatings to input 
 * getSize returns size as int
*/

class User
{
    public:
        User();//set default constructers
        
        User(string username,int ratings[],int numRatings);//parameterized constructor array of int
        
        string getUsername();//getters
        int getRatingAt(int idx);
        int getNumRatings();
        int getSize();
        
        void setUsername(string u);//setters
        bool setRatingAt(int idx,int value);
        void setNumRatings(int value);
        
        
    
    private://data members private
        string username;
        int size;
        int ratings[50];
        int numRatings;

};
