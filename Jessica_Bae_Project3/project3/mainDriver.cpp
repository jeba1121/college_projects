#include <iostream>
#include <math.h>
#include <string>
#include <array>
#include <fstream>
#include "User.h"
#include "Tile.h"
#include "General.h"
#include "Doompa.h"


using namespace std;



/**
 * have the game start off with intro and input username for user
 * roll the die 3 times to input the starting armysize, morale and strength of user
 * introduce user to other characters
 * user then rolls again to determine the turn (or maybe ill have user go first)
 * user rolls again to move on the space
 * calculate probability of that space- luck, unluck, fight
 * if luck- user gains either strength, morale, or army size depending on their role
 *      if luck and roll=3; user gets option to choose an ally
 *      if ally- sum their armysize, morale and strength- they will share victory!
 *      if solo- they gain an extra 10 in all categories
 *      for computers- they will always choose solo if they roll 3 and get luck 
 * if unluck-user loses the stated above or depending on the role, goes back the num spaces
 * if fight- user fights general and if win-gains morale and strength if loses- loses armysize
 *          -user cannot fight until over 15 spaces
 * the other users get to go and repeates the process above
 * the user must complete 150 spaces to challenge general again- general armysize,morale,and strength will be
 *      adjusted from any other fight tiles
 *      winning the general gives extra 20 in all categories- and king doomp loses army,morale,strength
 *      adjusted from the general tile
 *      if lost- user goes back 70 spaces and redo
 * then the user gets chance to face king doompa
 * if not- go back 70 spaces and redo
 * the winner is the first who gets to challenge and win against king doomp
 * you win if your ally wins
 * ultimate victory if you win solo
*/

int rollDie()
{
	return random() % 6 + 1; 
}

int comp()
{
    return random()%4 + 1;
}

int compLuck()
{
    return random() % 3 + 1;
}

int prob()
{
    return random() % 100 + 1;
}

int turnCount(int roll)
{
	int count;
	count=0;
	switch(roll)
	{
		case 1:
			count+=1;
			break;
		case 2:
			count+=2;
			break;
		case 3:
			count+=3;
			break;
		case 4:
			count+=4;
			break;
		case 5:
			count+=5;
			break;
		case 6:
			count+=6;
			break;
	}
	return count;
}

void game()
{
    User user;
    User comp;
    Tile tile;
    Tile compTile;
    General general;
    string name;
    Doompa doomp;
    
    char a;
    char c;
    char ans;
    char choice;
    char fight;
    
    int armySize;
    int morale;
    int strength;
    int space;
    
    int probability;
    int roll;
    bool luck;
    int playerSpace=0;
    int playerTurn=0;
    int compSpace=0;
    
    cout<<"Welcome to Charlie and the Doomed Factory!"<<endl;
    cout<<"The viral strain, Brocoloitis, exposed by King Doompa has halted the production of chocoloate."<<endl;
    cout<<"And you have been assigned by the special chocolate forces and Willy Wonka to help save the factory and the world!"<<endl;
    cout<<"Special agent...."<<endl;
    cout<<"Ahhhhh bonkers..jog my memory...what was your name again?"<<endl;
    cout<<endl;
    cin>>name;
    user.setUsername(name);
    cout<<endl;
    cout<<"AHHHHHHHH special agent "<<user.getUsername()<<endl;
    cout<<"Let us choose your equipment!"<<endl;
    cout<<"First your gear"<<endl;
    cout<<endl;
    cout<<"1. Sherrif's outfit"<<endl;
    cout<<"2. R.P.D gear"<<endl;
    cout<<"3. Micky Mouse T-Shirt"<<endl;
    cout<<"4. Monster Hunter"<<endl;
    cout<<"5. Genji's Cyborg Suit"
    cin>>a;
    cout<<endl;
    while(a!='1' && a!='2' && a!='3' && a!='4' && a!='5')
    {
        cout<<"Please choose a listed option"<<endl;
        cin>>a;
    }
    if(a=='1' || a=='2' || a=='3' || a=='4' || a=='5')
    {
        srand(time(NULL));
        int b=rollDie();
        user.setMorale(b);
        cout<<"Ahhhh the good ole ";
        if(a=='1')
        {
            cout<<"Sherrif's outfit"<<endl;
        }
        if(a=='2')
        {
            cout<<"R.P.D gear"<<endl;
        }
        if(a=='3')
        {
            cout<<"Mickey Mouse T-Shirt"<<endl;
        }
        if(a=='4')
        {
            cout<<"Monster Hunter gear"<<endl;
        }
        if(a=='5')
        {
            cout<<"Cyborg suit"<<endl;
        }
        cout<<"Congratulations! Your morale went up by "<<user.getMorale()<<endl;
        cout<<endl;
        
    }
    cout<<"Next your weapon!"<<endl;
    cout<<endl;
    cout<<"1. Claire's Grenade Launcher"<<endl;
    cout<<"2. Darryl's Crossbow"<<endl;
    cout<<"3. Brick"<<endl;
    cout<<"4. Torb Turret"<<endl;
    cout<<"5. Banana"<<endl;
    cin>>c;
    while(c!='1' && c!='2' && c!='3' && c!='4' && c!='5')
    {
        cout<<"Please choose a listed option"<<endl;
        cin>>c;
    }
    if(c=='1' || c=='2' || c=='3' || c=='4' || c=='5')
    {
        srand(time(NULL));
        int d=rollDie();
        user.setStrength(d);
    }
    cout<<endl;
    cout<<"I wish you victory with the almighty ";
    if(c=='1')
    {
        cout<<"Grenade Launcher"<<endl;
    }
    if(c=='2')
    {
        cout<<"Crossbow"<<endl;
    }
    if(c=='3')
    {
        cout<<"Brick"<<endl;
    }
    if(c=='4')
    {
        cout<<"Turret"<<endl;
    }
    if(c=='5')
    {
        cout<<"BanANA"<<endl;
    }
    cout<<"Congratulations! Your Strength went up by "<<user.getStrength()<<endl;
    cout<<endl;
    cout<<"Here's a list of all players on the board!"<<endl;
    cout<<user.getUsername()<<endl;
    user.readPlayers("player.txt");
    cout<<endl;
    cout<<"Now lets head off to save CHOCOLATE!!!"<<endl;
    cout<<endl;
    while(playerSpace!= 50 || compSpace!=50)
    {
        while( playerTurn==0)
        {
            if(playerTurn!=0 || playerSpace==50)
            {
                break;
            }
            cout<<"Press any key to roll..."<<endl;
            cin>>ans;
            srand(time(NULL));
            roll=rollDie();
            playerSpace+=roll;
            cout<<"You rolled a "<<roll<<endl;
            tile.setSpace(playerSpace);
            probability=tile.calcProbability();
            luck=tile.calcLuck(probability);
            if(luck==true)
            {
                cout<<"You landed on a lucky tile!"<<endl;
                cout<<"Would you like to increase... "<<endl;
                cout<<"1. Army size"<<endl;
                cout<<"2. Morale"<<endl;
                cout<<"3. Strength"<<endl;
                cin>>choice;
                while(choice!='1' && choice!= '2' && choice!= '3')
                {
                    cout<<"Please choose one of the given options"<<endl;
                    cin>>choice;
                }
                if(choice=='1')
                {
                    cout<<"Your army size has increased by "<<roll<<endl;
                    armySize=user.calcArmySize(roll);
                    user.setArmySize(armySize);
                }
                if(choice=='2')
                {
                    cout<<"Your morale has increased by "<<roll<<endl;
                    morale=user.calcMorale(roll);
                    user.setMorale(morale);
                }
                if(choice=='3')
                {
                    cout<<"Your strength has increased "<<endl;
                    strength=user.calcStrength(roll);
                    user.setStrength(strength);
                }
            }
            if(luck!=true)
            {
                cout<<"You landed on a unlucky tile!"<<endl;
                cout<<endl;
                space=tile.getSpace();
                if(space<20)
                {
                    cout<<"The doompas have scavaged your base!"<<endl;
                    roll=roll*-1;
                    morale=user.calcMorale(roll);
                    cout<<"Your morale has decreased to "<<morale<<endl;
                    user.setMorale(morale);
    
                }
                if(space>20)
                {
                    cout<<"The doompas are looking for a challenge!"<<endl;
                    cout<<"Will you fight? [y/n]?"<<endl;
                    cin>>fight;
                    while(fight!='n' && fight!='N'&& fight!='Y' &&fight!='y')
                    {
                        cout<<"Please enter n for no or y for yes"<<endl;
                        cin>>fight;
                    }
                    if(fight=='n' || fight=='N')
                    {
                        cout<<"You have ran away!"<<endl;
                        strength=user.calcStrength(-1);
                        user.setStrength(strength);
                        cout<<"As a result your strength has decreased to "<<strength<<endl;
                    }
                    if(fight=='y' || fight=='Y')
                    {
                        armySize=user.getArmySize();
                        strength=user.getStrength();
                        if(armySize<5 && strength<5)
                        {
                            cout<<"You have lost the battle!"<<endl;
                            roll=roll*-1;
                            armySize=user.calcArmySize(roll);
                            cout<<"Your army has decreased to "<<armySize<<endl;
                            user.setArmySize(armySize);
                        }
                        else
                        {
                            cout<<"You have won the battle!"<<endl;
                            armySize=user.calcArmySize(roll);
                            strength=user.calcStrength(5);
                            user.setArmySize(armySize);
                            user.setStrength(strength);
                            cout<<"Your army has grown. Congratulations on saving some doompas!"<<endl;
                        }
                    }
                }
            }
            cout<<endl;
            cout<<"Here is a summary of your turn!"<<endl;
            cout<<endl;
            cout<<"Army Size: "<<user.getArmySize()<<endl;
            cout<<"Morale: "<<user.getMorale()<<endl;
            cout<<"Strength: "<<user.getStrength()<<endl;
            cout<<endl;
            playerTurn++;
            
        }
        while(playerTurn!=0)
        {
            if(playerTurn==0 || playerSpace==50)
            {
                break;
            }
            srand(time(NULL));
            roll=rollDie();
            cout<<"It is now Willy Wonka's turn"<<endl;
            cout<<"Press any key to continue..."<<endl;
            cin>>ans;
            cout<<endl;
            cout<<"Willy Wonka rolled a "<<roll<<endl;
            compSpace+=roll;
            compTile.setSpace(compSpace);
            probability=compTile.calcProbability();
            luck=compTile.calcLuck(probability);
            if(luck==true)
            {
                cout<<"Willy landed on a lucky tile!"<<endl;
                if(roll==1 || roll==2)
                {
                    cout<<"Willy's army size has increased by "<<roll<<endl;
                    armySize=comp.calcArmySize(roll);
                comp.setArmySize(armySize);
                }
                if(roll==3 || roll==4)
                {
                    cout<<"Willy's morale has increased by "<<roll<<endl;
                    morale=comp.calcMorale(roll);
                    comp.setMorale(morale);
                }
                if(roll==5 || roll==6)
                {
                    cout<<"Willy's strength has increased"<<endl;
                    strength=comp.calcStrength(roll);
                    comp.setStrength(strength);
                }
            }
            if(luck!=true)
            {
                cout<<"Willy landed on a unlucky tile!"<<endl;
                cout<<endl;
                space=compTile.getSpace();
                if(space<20)
                {
                    cout<<"The doompas have scavaged Willy's base!"<<endl;
                    roll=roll*-1;
                    morale=comp.calcMorale(roll);
                    cout<<"Willy's morale has decreased to "<<morale<<endl;
                    comp.setMorale(morale);
    
                }
                if(space>20)
                {
                    cout<<"Willy decided to fight!"<<endl;
                    armySize=comp.getArmySize();
                    strength=comp.getStrength();
                    if(armySize<30 && strength<20)
                    {
                        cout<<"Willy lost the battle!"<<endl;
                        roll=roll*-1;
                        armySize=comp.calcArmySize(roll);
                        cout<<"Willy's army has decreased to "<<armySize<<endl;
                        comp.setArmySize(armySize);
                    }
                    else
                    {
                        cout<<"Willy has won the battle!"<<endl;
                        armySize=comp.calcArmySize(roll);
                        strength=comp.calcStrength(5);
                        comp.setArmySize(armySize);
                        comp.setStrength(strength);
                        cout<<"Willy's army has grown. Congratulations Willy!"<<endl;
                    }
                }
            }
            cout<<endl;
            cout<<"Here is a summary of Willy's turn!"<<endl;
            cout<<endl;
            cout<<"Army Size: "<<comp.getArmySize()<<endl;
            cout<<"Morale: "<<comp.getMorale()<<endl;
            cout<<"Strength: "<<comp.getStrength()<<endl;
            cout<<"It is now your turn"<<endl;
            playerTurn--;
            cout<<endl;
        }
        if(playerSpace==50)
        {
            cout<<endl;
            cout<<"You have reached the right amount of stats to challenge General Oomp!"<<endl;
            cout<<"Shall you fail, Willy will challenge General Oomp!"<<endl;
            cout<<endl;
            break;
        }
        

    }
    int genArmy= general.calcGenArmySize(user.getArmySize());
    general.setGenArmySize(genArmy);
    int genMorale=general.calcGenMorale(user.getMorale());
    general.setGenMorale(genMorale);
    int genStrength=general.calcGenStrength(user.getStrength());
    general.setGenStrength(genStrength);
    cout<<"Press any key to see the general's stats..."<<endl;
    cin>>ans;
    cout<<endl;
    cout<<"Army Size: "<<general.getGenArmySize()<<endl;
    cout<<"Morale: "<<general.getGenMorale()<<endl;
    cout<<"Strength: "<<general.getGenStrength()<<endl;
    if(user.getArmySize()<general.getGenArmySize())
    {
        cout<<"You were not able to save enough oompa loompas..."<<endl;
        cout<<"Game Over"<<endl;
    }
    else if(user.getArmySize()>general.getGenArmySize())
    {
        cout<<"You have defeated General Ooompa!"<<endl;
        user.calcArmySize(genArmy);
        user.calcMorale(genMorale);
        user.calcStrength(genStrength);
        cout<<endl;
        cout<<"DUNDUND DUNNNNNNNN"<<endl;
        cout<<"King Doompa has emerged from his slumber"<<endl;
        cout<<"THIS IS THE MOMENT OF FATE"<<endl;
        cout<<"PRESS ANY KEY IF YOU DARE"<<endl;
        cin>>ans;
        int doompArm= doomp.calcKingArmySize(user.getArmySize());
        doomp.setKingArmySize(doompArm);
        int doompMor= doomp.calcKingMorale(user.getMorale());
        doomp.setKingMorale(doompMor);
        int doompStr=doomp.calcKingStrength(user.getStrength());
        doomp.setKingStrength(doompStr);
        cout<<"Let me present King Doompa's stats..."<<endl;
        cout<<"Army Size: "<<doomp.getKingArmySize()<<endl;
        cout<<"Morale: "<<doomp.getKingMorale()<<endl;
        cout<<"Strength: "<<doomp.getKingStrength()<<endl;
        cout<<endl;
        if(user.getMorale()>doomp.getKingMorale())
        {
            cout<<"Your spirit is greater, I command you Special Agent "<<user.getUsername()<<endl;
        }
        if(user.getArmySize()>doomp.getKingArmySize() && user.getStrength()>doomp.getKingStrength())
        {
            cout<<"You have defeated King Doomp"<<endl;
            cout<<"We can't thank you enough for your hard work and perservation!"<<endl;
            cout<<"Congratulations!"<<endl;
        }
        if(user.getArmySize()<doomp.getKingArmySize() && user.getStrength()<doomp.getKingStrength())
        {
            cout<<"We commend you for your hard work...but we have failed our mission"<<endl;
            cout<<"Chocolate has been lost forever....turned into brocoli"<<endl;
            cout<<"Game Over"<<endl;
        }

    }
    
    
    
}

int main()
{
	// start the game! 
	game();
	return 0;
}