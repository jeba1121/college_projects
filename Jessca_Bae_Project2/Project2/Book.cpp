// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Homework 7 - Problem # 3 and 5

#include "Book.h"
#include<iostream>
#include<string>
using namespace std;

/**
 * create member functions from class Book
 * Parameterized constructor: set strings to title and author
 * getTitle returns the title
 * getAuthor returns the author
 * setTitle sets input string to title
 * setAuthor sets input string to author
*/

Book::Book(string t, string a)
{
    title=t;
    author=a;
}
string Book::getTitle()
{
    return title;
}
string Book::getAuthor()
{
    return author;
}
void Book::setTitle(string a)
{
    title=a;
}
void Book::setAuthor(string b)
{
    author=b;
}