// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Project 2 - Problem # 0
#include <iostream>
#include <string>
#include <array>
#include <math.h>
#include <fstream>
#include <algorithm>
#include "Library.h"
using namespace std;
//split function
int split (string str, char c,string words[],int num)
{
    words[num];
    if (str.length() == 0) {//if there is nothing in the string return 0
        return 0;
    }
    string word = "";
    int j = 0;
    str = str + c;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c) 
        {
        	if (word.length() == 0) continue;
            words[j]=word;//save word to array words
            j++;
            word = "";
        } 
        else
        {
            word = word + str[i];
        }
        if(j>num)//still add j to array but return -1
        {
            return -1;
        }
    }
    return j ;
}



int Library::getSizeBook()
{
    return sizeBook;
}
int Library::getSizeUser()
{
    return sizeUser;
}
int Library::getNumBooks()
{
    return numBooks;
}
int Library::getNumUsers()
{
    return numUsers;
}
int Library::readBooks(string fileName)
{
    if(numBooks ==sizeBook) // if numbooks equal to the size return -2
    {
        return -2;
    }
    ifstream file; 
    file.open(fileName);
    string line,author,title; //name strings, author, title and line
    if(file.is_open())//if file opens or exists
    {
        while(getline(file,line) && numBooks<sizeBook)//look till the end of file and while numbooks<size
        {
            //look at each line
            if(line.length()>0)//if they are not empty
            {
                author= line.substr(0,line.find(","));//author is from the begining of line to the ,
                title= line.substr(line.find(",")+1);//title is from the comma to end of line
                books[numBooks].setAuthor(author);//set author to the array
                books[numBooks].setTitle(title);//set title to the array
                numBooks++;//total books in the system
                
            }
        }
        return numBooks;
    }
    else
    {
        return -1;
    }
    file.close();
}
void Library::printAllBooks()
{
    if(numBooks<=0)//if numBooks=0
    {
        cout<<"No books are stored"<<endl;
    }
    else
    {
        cout<<"Here is a list of books"<<endl;
        for(int i=0;i<numBooks;i++)//go through each array from 0-numBooks and by adding 1 to i
        {
            cout<<books[i].getTitle()<<" by ";
            cout<<books[i].getAuthor()<<endl;
        }
    }
}
int Library::readRatings(string fileName)
{
    if(numUsers>=sizeUser)
    {
        return -2;
    }
    ifstream file(fileName.c_str());
    string line,user,ratings;
    if(file.is_open())
    {
        while(!file.eof() && numUsers<sizeUser)
        {
            getline(file,line);
            if(line.length()>0)
            {
               
               string ratingArr[51];
               int result=split(line,',',ratingArr,51);
               if(result>0)
               {
                   users[numUsers].setUsername(ratingArr[0]);
                   for(int i=0;i<50;i++)
                   {
                       string ratingNum=ratingArr[i+1];
                       if(!ratingNum.empty())
                       {
                           int ratings=stoi(ratingNum);
                           users[numUsers].setRatingAt(i,ratings);
                       }
                   }
                   numUsers++;
               }
            }
        }
        return numUsers;
    }
    else
    {
        return -1;
    }
}
int Library::getRating(string username, string title)
{
    int userIdx=-1;
    int bookIdx=-1;
    transform(username.begin(),username.end(),username.begin(),::tolower);//username to lowercase
    transform(title.begin(),title.end(),title.begin(),::tolower);//title to lowercase
    for(int i=0;i<numUsers;i++)
    {
        string name= users[i].getUsername(); //save the getusername to string name
        transform(name.begin(),name.end(),name.begin(),::tolower);//convert name to lowercase
        if(name==username)//if you can
        {
            userIdx=i;//save index 
            break;
        }
    }
    for(int i=0;i<numBooks;i++)
    {
        string bookName= books[i].getTitle();//same as above
        transform(bookName.begin(),bookName.end(),bookName.begin(),::tolower);
        if(bookName==title)
        {
            bookIdx=i;
            break;
        }
    }
    if(userIdx==-1 || bookIdx==-1)//if you cant save index, the title or user was not found
    {
        return -3;
    }
    return users[userIdx].getRatingAt(bookIdx);//return the rating of the bookindx with userindx
    
}
int Library::getCountReadBooks(string username)
{
    int count=0;
    int userIdx=-1;
    int bookIdx=-1;
    transform(username.begin(),username.end(),username.begin(),::tolower);//username to lowercase
    for(int i=0;i<numUsers;i++)
    {
        string name= users[i].getUsername(); //save the getusername to string name
        transform(name.begin(),name.end(),name.begin(),::tolower);//convert name to lowercase
        if(name==username)//if you can
        {
            userIdx=i;//save index 
            break;
        }
    }
    for(int i=0;i<numBooks;i++)
    {
        int rating=users[userIdx].getRatingAt(i);
        if(rating!=0)
        {
            count++;
        }
    }
    
    if(userIdx==-1)//if you cant save index, the title or user was not found
    {
        return -3;
    }
    return count;
}
void Library::viewRatings(string username)
{
    string original=username;
    int userIdx=-1;
    int bookIdx=-1;
    int totalRating=0;
    transform(username.begin(),username.end(),username.begin(),::tolower);//username to lowercase
    for(int i=0;i<numUsers;i++)
    {
        string name= users[i].getUsername(); //save the getusername to string name
        transform(name.begin(),name.end(),name.begin(),::tolower);//convert name to lowercase
        if(name==username)//if you can
        {
            userIdx=i;//save index 
        }
    }
    for(int i=0;i<numBooks;i++)
    {
        int rating=users[userIdx].getRatingAt(i);
        totalRating+=rating; //if there are 0 ratings
    }
    if(userIdx==-1)//if username cant be updated
    {
        cout<<username<<" does not exist."<<endl;
    }
    if (totalRating==0)
    {
        cout<< username<<" has not rated any books yet."<<endl;
    }
    if (totalRating!=0 && userIdx!=-1)//if username is saved and ratings are not all 0
    {
        
        cout<<"Here are the books that "<<original<<" rated"<<endl;
        for(int i=0;i<numBooks;i++)
        {
            int rating=users[userIdx].getRatingAt(i);//look at all the ratings
            totalRating+=rating;//update the total
            if(rating!=0)//as long as ther rating isnt 0
            {
                cout<<"Title : "<<books[i].getTitle()<<endl;
                cout<<"Rating : "<<rating<<endl;
                cout<<"-----"<<endl;
    
            }
        }
        
    }
}
double Library::calcAvgRating(string title)
{
    int userIdx=0;
    double totalRating=0.0;
    int count=0;
    double avgRating=0.0;
    transform(title.begin(),title.end(),title.begin(),::tolower);//title to lowercase
    
    int bookIdx=-1;
    for(int i=0;i<numBooks;i++)
    {
        string bookName= books[i].getTitle();//same as above
        transform(bookName.begin(),bookName.end(),bookName.begin(),::tolower);
        if(bookName==title)//check if both book and title are the samee case sensitive
        {
            bookIdx=i;//save the place they are equal
            for(int j=0;j<numUsers;j++)
            {
                int rating=users[j].getRatingAt(bookIdx);//look at the rating of that book for all users
                if(rating!=0)
                {
                    count++;//count how many ratings theyre are
                }
                totalRating+=rating;//total up the ratings
            }
        }
    }
    avgRating=totalRating/count;//divide by count to get average
    
    if(bookIdx==-1)//if you cant save index, the title was not found
    {
        return -3;
       
    }
    if(totalRating==0)
    {
        return 0;
    }
    return avgRating;

}    
int Library::addUser(string username)
{
    string original=username;
    int idx;
    if(numUsers==sizeUser)
    {
        return -2;
    }
    else
    {
        transform(username.begin(),username.end(),username.begin(),::tolower);//username to lowercase
        for(int i=0;i<numUsers;i++)
        {
            string name= users[i].getUsername(); //save the getusername to string name
            transform(name.begin(),name.end(),name.begin(),::tolower);//convert name to lowercase
            if(name==username)//if they equal the same, name is already in database
            {
                return 0;
            }
            else//if you cant
            {
                idx=i+1; //the index where it is open in the array
                users[numUsers].setUsername(original);//set the username
                users[numUsers].setRatingAt(idx,0);//set rating at that index as 0
                numUsers++;
                return 1;
            }
            
        }
    }
    
}
int Library::checkOutBook(string username,string title,int rating)
{
    int userIdx=-1;
    int bookIdx=-1;
    transform(username.begin(),username.end(),username.begin(),::tolower);//username to lowercase
    transform(title.begin(),title.end(),title.begin(),::tolower);//title to lowercase
    for(int i=0;i<numUsers;i++)
    {
        string name= users[i].getUsername(); //save the getusername to string name
        transform(name.begin(),name.end(),name.begin(),::tolower);//convert name to lowercase
        if(name==username)//if you can
        {
            userIdx=i;//save index 
            break;
        }
    }
    for(int i=0;i<numBooks;i++)
    {
        string bookName= books[i].getTitle();//same as above
        transform(bookName.begin(),bookName.end(),bookName.begin(),::tolower);
        if(bookName==title)
        {
            bookIdx=i;
            break;
        }
    }
    if((userIdx==-1 || bookIdx==-1) && (rating>=0 && rating<=5))//if you cant save index, the title or user was not found
    {
        return -3; // but valid ratings
    }
    bool result=users[userIdx].setRatingAt(bookIdx,rating);
    
    if(!result) //invalid ratings
    {
        return -4;
    }
    return result;
}
void Library::getRecommendations(string username)
{
    string original=username;
    int userIdx=-1;
    int bookIdx=-1;
    int ssd=0;
    int total=0;
    int smallest=0;
    int otherIdx;
    int ratings;
    int otherRatings;
    int closestR;
    int result=0;
    transform(username.begin(),username.end(),username.begin(),::tolower);//username to lowercase
    for(int i=0;i<numUsers;i++)
    {
        string name= users[i].getUsername(); //save the getusername to string name
        transform(name.begin(),name.end(),name.begin(),::tolower);//convert name to lowercase
        if(name==username)
        {
            userIdx=i; //save idx where they are equal
        }
        for(int j=0;j<numBooks;j++)
        {
            ratings=users[userIdx].getRatingAt(j); //look at ratings of user
            if(i!=userIdx)
            {  
                otherRatings=users[i].getRatingAt(j);//look at ratings of others
                ssd+=pow(ratings-otherRatings,2);//calculate ssd
            }
            
        }
        total=ssd;//update the total
        ssd=0;//reset ssd to 0 after each user
        if(total>0 || total<smallest)
        {
            smallest=total;//find the smallest ssd value and save indx of that user
            otherIdx=i;
            break;
        }
    }
    
    if(userIdx!=-1)//if username is valid
    {
        for(int j=0;j<numBooks;j++)
        {
            closestR=users[otherIdx].getRatingAt(j);
            ratings=users[userIdx].getRatingAt(j);
            if(ratings==0 && closestR>=3) //compare the user and other users ratings with the lowest ssd
            {
                bookIdx=j;
                cout<<"Here are a list of recommendations"<<endl;
                cout<<books[bookIdx].getTitle()<<" by ";
                cout<<books[bookIdx].getAuthor()<<endl;
                result++;
            }
            
        }
        if(result==0) //if you cant find any ratings that arent 0 and higher than 3
        {
            cout<<"There are no reccomendations for "<<original<<" at present"<<endl;
        }
    }
    if(userIdx==-1) //if you cant find the username 
    {
        cout<<original<<" does not exist."<<endl;
    }
    
}