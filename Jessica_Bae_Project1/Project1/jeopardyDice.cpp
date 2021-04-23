// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208- Josh Ladd
// Cloud9 Workspace Editor Link : https://ide.c9.io/jeba1121/jb_workspace
// Project 1- Problem # 3


///////////////////////////////////////////////////////////////////////////////////////////////////
// Step1: Steps to solve this problem
// write an algorithm in pseudocode explaining how you are approaching the problem, step by step 
///////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 3 functions will be made
 * one to calculate die rolls for player
 * another to calculate die rolls for comp
 * and lastly to print the total
 * first introduce
 * than roll the die with cin(input)
 * make sure input acounts for lowercase and capital
 * and if input is no
 * move on
 * if input is yes
 * roll the die
 * input circumstances of each die
 * if die and playerTotal reach 8, break
 * do the same for computer without input loops
 * call player first to save return turntotal
 * do the same for computer
 * then if turn is on player and totalscore is not 80
 * recall player
 * do same for comp
 * break for each if score is 80 or reaches 80


*/




///////////////////////////////////////////////////////////////////////////////////////////////////
// Step2: Code it up! 
// After finishing up your pseudocode, translate them into c++ 
// IMPORTANT: rollDie() and main() are already written for you.
// You need to complete game function as well as at least 3 other additional functions
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
using namespace std; 

/**
 * rollDie 
 * returns a random integer between 1 and 6, works as rolling a dice.
 * return value, int number (1-6)
 */

int rollDie()
{
	return random() % 6 + 1; 
}




int player()
{
	int turnCount;
	int playerScore;
	turnCount=2;
	int turnTotal;
	int compTotal;
	turnTotal=0;
	compTotal=0;
	do
	{	
		if((80-(playerScore+turnTotal)<0) or (turnTotal>=80))//80 is the max a player get so if their total score+the turn total of the round is 80 then terminate. if playerScore is not saved then terminate at turntotal 80
		{
			break;
		}
		cout<<"It is now human's turn"<<endl;
		cout<<endl;
		cout<<"Do you want to roll a dice(Y/N)?"<<endl;
		char ans;
		cin>>ans;
		if((ans=='n')or(ans=='N'))//if no, terminate turn
			{
				turnCount++;
				cout<<"Your turn total is "<<turnTotal<<endl;
				break;
			}
		while ((ans=='y')or(ans=='Y'))//create loop if you keep rolling the die
		{
			if((80-(playerScore+turnTotal)<0) or (turnTotal>=80))
		{
			break;
		}
			srand(time(NULL));
			int die1=rollDie();
			if((die1==2) or(die1==5))
			{
				turnTotal+=0;
				cout<<"You rolled a "<<die1<<endl;
				cout<<"Your turn total is "<<turnTotal<<endl;
				turnCount++;
				break;
			}
			else if((die1==1)or(die1==3)or(die1==6))
			{
				turnTotal+=die1;
				turnCount;
				cout<<"You rolled a "<<die1<<endl;
				cout<<"Your turn total is "<<turnTotal<<endl;
				
				cout<<"Do you want to roll again(Y/N)?"<<endl;
				cin>>ans;
			}
			else if((die1==4))
			{
	
				turnTotal+=15;
				turnCount;
				cout<<"You rolled a "<<die1<<endl;
				cout<<"Your turn total is "<<turnTotal<<endl;
				cout<<"Do you want to roll again[Y/N]?"<<endl;
				cin>>ans;
			}
			if((ans=='n')or(ans=='N'))//if no, it switches to comp turn and terminates
			{
				turnCount++;
				cout<<"Your turn total is "<<turnTotal<<endl;
				break;
			}
		}
	}
	while((turnCount%2==0));
	return(turnTotal);
}

int comp()
{
	int compScore;
	int turnCount;
	turnCount=2;
	int turnTotal;
	int compTotal;
	turnTotal=0;
	compTotal=0;
	do
	{	
		cout<<"It is now computer's turn"<<endl;
		cout<<endl;
		srand(time(NULL));
		int die1=rollDie();

		if((die1==2) or(die1==5))
		{	
			
			compTotal+=0;
			cout<<"Computer rolled a  "<<die1<<endl;
			cout<<"Computer turn total is "<<compTotal<<endl;
			turnCount-=1;
			break;
		}
		else if((die1==1)or(die1==3)or(die1==6))
		{
			compTotal+=die1;
			cout<<"Computer rolled a  "<<die1<<endl;
			cout<<"Computer turn total is "<<compTotal<<endl;

		}
		else if((die1==4))
		{
			compTotal+=15;
			cout<<"Computer rolled a  "<<die1<<endl;
			cout<<"Computer turn total is "<<compTotal<<endl;
		}
			
	}
	while((turnCount%2==1));
	return compTotal;
}
void print(int playerScore, int compScore)
{
	cout<<"computer: "<<compScore<<endl;
	cout<<"human: "<<playerScore<<endl;
}

/**
 * game 
 * driver function to play the game
 * the function does not return any value
 */

int turnCount=2;
int turnTotal=0;
int compTotal=0;
int playerScore=0;
int compScore=0;

void game()
{
	cout<< "Welcome to Jeopardy Dice!"<<endl;
	cout<<endl;
	playerScore+=player();//call functions once to set playerScore value
	print(playerScore,compScore);
	cout<<endl;
	compScore+=comp();
	print(playerScore,compScore);
	cout<<endl;

	while((turnCount%2==0)and(80-playerScore>0))//do it again till playerScore reaches 80
	{	
		playerScore+=player();
		cout<<"computer: "<<compScore<<endl;
		cout<<"human: "<<playerScore<<endl;
		cout<<endl;
		if(80-playerScore<=0)//break when it reaches 80 or more
		{
			cout<<"Congratulations! human won this round of Jeopardy Dice!";
			break;
		}
    	if((turnCount%2==0)and(80-compScore>0))//same idea for computer score
    	{
    		compScore+=comp();
    		cout<<"computer: "<<compScore<<endl;
    		cout<<"human: "<<playerScore<<endl;
    		cout<<endl;
    		if(80-compScore<=0)//break when it reaches 80 or more
    		{
    			cout<<"Congratulations! computer won this round of Jeopardy Dice!";
    			break;
    		}
	    }
	}

	
}


///////////////////////////////////////////////////////////////////////////////////////////////////
// don't change the main. 
// Once you finished please paste your code above this line 
///////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	// start the game! 
	game();
	return 0;
}
