// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208- Josh Ladd
// Cloud9 Workspace Editor Link : https://ide.c9.io/jeba1121/jb_workspace
// Project 1- Problem # 1

/**
 * create function printOddNums
 * integer takes input, integer (max value)
 * function returns nothing
 * function prints positive integers less than or equal to the value
 * create a for loop
 * condition for the loop: an int greater than 0 and <= the max value
 * add 2 to int i until condition is met
 * print int i 
*/

#include <iostream>
#include <math.h>
using namespace std;

void printOddNums(int num)
{
    for (int i = 1; (i<=num); i=i+2) //add 2 to 1 when i<=num
    {
        cout<<i<<endl;
    }
}

int main()
{
    //test 1
    //expected output
    //1
    //3
    //5
    //7
    //9
    //11
    printOddNums(11);
    //test 2 
    //expected output
    //1
    //3
    printOddNums(3);
}