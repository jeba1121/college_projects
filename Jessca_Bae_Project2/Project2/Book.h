// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Homework 7 - Problem # 3 and 5

#include <iostream>
#include <string>

using namespace std;

/**
 * create class Book
 * Set default title and author to empty strings
 * Create parameterized constructers with string t and a
 * getTitle returns the title as string
 * getAuthor returne the author as string
 * setTitle assigns input string to title
 * setAuthro assigns input string to author
*/


class Book
{
    public:
        Book()//default constructer
        {
            title="";//empty strings
            author="";
        };
        Book(string t, string a);//parameterized constructer
        
        string getTitle();//getters
        string getAuthor();
        
        void setTitle(string a);//setters
        void setAuthor(string b);
    
    private:
        string title;//data members
        string author;
};