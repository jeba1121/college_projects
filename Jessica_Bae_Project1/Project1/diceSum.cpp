// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208- Josh Ladd
// Cloud9 Workspace Editor Link : https://ide.c9.io/jeba1121/jb_workspace
// Project 1- Problem # 2

/**
 *create function diceSum
 * function takes 1 int argument for sum
 * function returns nothing
 * use rollDie function to simulate rolling a die
 * identify values int sum
 * if statement the sum must be 2 or 12
 *      under if statement, while statement to explain while sum doesnt equal the desiredSum(keep doing the thing)
 *      under while statement: roll and assign roll to value die1 and die2
 *      identify int rolls variable to count how many rolls 
 *      calculate sum of die1 and die2
 *      output print: you rolled a <die1> and <die2>
 *      add 1 to rolls each time until while statement condition is fullfilled
 *      when you get sum, output: Got a <desiredSum> in <rolls> rolls!
 * else print: The desired sum should be between 2 and 12
 * 
*/

#include <iostream>
#include <math.h>
using namespace std;

/*rollDie
 * returns a random integer between 1 and 6,
 * works as rolling a die.
 * return value, int number (1-6)
 */
int rollDie()
{
return random()% 6 + 1;
}

void diceSum(int desiredSum)
{   
    int sum;
    if((desiredSum>=2) and (desiredSum<=12)) //valid input between 2 and 12
    {
        while((sum!= desiredSum))//keep doing the stuff below until sum == desired sum
        {
            int rolls;
            int die1= rollDie(); //roll#1
            int die2= rollDie(); //roll #2
            sum= die1+die2; //add rolls for sum
            cout<<"You rolled a "<<die1<< " and a "<< die2<<endl;
            rolls++; //add 1 to count of rolls after each roll is made
            if(sum==desiredSum) //when sum finally equals desiredSum
            {
                cout<<"Got a " <<sum<< " in "<< rolls<< " rolls!"<<endl; //print sum and roll count
            }
        }
    }
    else //must be valid input
    {
        cout<< "The desired sum should be between 2 and 12"<<endl;
    }

}

int main()
{
    //test 1
    //expected output
    //The desired sum should not be between 2 and 12
    diceSum(1);
    //test 2
    //expected output
    //you rolled a 2 and a 5
    //you rolled a 4 and a 2
    //got a 6 in 2 rolls!
    diceSum(6);
}
