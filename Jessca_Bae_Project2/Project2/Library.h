// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Project 2 - Problem # 0
#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <string>
#include <array>
#include "Book.h"
#include "User.h"

using namespace std;

/**
 * create class Library
 * private data members : int sizeBook, int sizeUser, Book array books, User array users, int numBooks, int numUsers
 * set default constructer: numBooks and numusers=0
 * getters: getSizeBook, getSizeUser, getNumBooks, getNumUsers, that returns as int
 * readBooks- takes string (fileName) and populates books array: returns the total number of books in books array as int
 * printAllBooks-prints books stored in books array
 * readRatings- takes a string (fileName) populates usuers array: returns the total number of users in users array as int
 * other getters: getRating-returns user rating for the specific book (username,book title)
 * getCountReadBooks: returns num of books read by that user as int
 * viewRatings: takes string and prints all books user has ratings for
 * calcAvgRating: takes string(title of Book) and returns average rating of the specified book as a double
 * addUser: takes username and returns integer 1 if the user is added, 0 if the username exists in the array and -2 if the array is already full
 * checkOutBook: takes 2 strings and int for username,title of the book and new rating. returns 1 if rating is updated. returns -4 if value is not valid, and -3 if the value is valid but the user or title doesnt exist
 * getReccomendations:takes a string username and prints the first 5 book reccomendations fro the most similar different user
*/

class Library
{
    public:
        Library()//default constructer
        {
            numBooks=0;//set values to 0
            numUsers=0;
        };
        
        int getSizeBook();
        int getSizeUser();
        int getNumBooks();
        int getNumUsers();
        
        int readBooks(string fileName);
        void printAllBooks();
        int readRatings(string fileName);
        int getRating(string username,string title);
        int getCountReadBooks(string username);
        void viewRatings(string username);
        double calcAvgRating(string title);
        int addUser(string username);
        int checkOutBook(string usermame,string title,int rating);
        void getRecommendations(string username);
    
    private:
        int sizeBook=50;
        int sizeUser=100;
        Book books[50];
        User users[100];
        int numBooks;
        int numUsers;
};
#endif