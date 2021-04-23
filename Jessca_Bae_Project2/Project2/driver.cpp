#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <algorithm>
#include <math.h>
// #include "Book.h"
// #include "User.h"
#include "Library.h"
using namespace std;

int main()
{
    //test readBooks and printallbooks
    
    Library myLibrary;
    //
    int rv=myLibrary.readBooks("fileName.txt");
    cout<<"rv="<<rv<<endl;
    cout<<"numBooks= ";
    cout<<myLibrary.getNumBooks()<<endl;
    //myLibrary.printAllBooks();
    
    //test readratings and getrating
    
    //Library myLibrary1;
    //myLibrary1.readBooks("fileName.txt");
    //int rv1= myLibrary1.readRatings("ratings.txt");
    //cout<<"rv1= "<<rv1<<endl;
    //cout<<"numUsers= ";
    //cout<<myLibrary1.getNumUsers()<<endl;
    //cout<<myLibrary1.getRating("ninja","book 1")<<endl;
    //cout<<myLibrary1.getRating("ninja","book 2")<<endl;
    //cout<<myLibrary1.getRating("ninja","book 3")<<endl;
    //cout<<myLibrary1.getRating("ninja","book 4")<<endl;
    //cout<<myLibrary1.getRating("ninja","book 5")<<endl;
    
    //getCountReadBooks
    
    //Library myLibrary2;
    //myLibrary2.readBooks("fileName.txt");
    //myLibrary2.readRatings("ratings.txt");
    //cout<<myLibrary2.getCountReadBooks("ninja")<<endl;
    
    //viewRatings
    //Library myLibrary3;
    //myLibrary3.readBooks("fileName.txt");
    //myLibrary3.readRatings("ratings.txt");
    //myLibrary3.viewRatings("NinJa");
    //myLibrary3.viewRatings("Daequan");
    //myLibrary3.viewRatings("user");
    
    //calcAvgRating
    //Library myLib;
    //myLib.readBooks("fileName.txt");
    //myLib.readRatings("ratings.txt");
    //cout<<myLib.calcAvgRating("Book 1")<<endl;
    
    //addUsers
    Library myLib1;
    //myLib1.readRatings("ratings.txt");
    //cout<<"numUsers= "<<myLib1.getNumUsers()<<endl;
    //cout<<myLib1.addUser("ninja1")<<endl;
    //cout<<myLib1.addUser("ninja")<<endl;
    //cout<<"newnum = "<<myLib1.getNumUsers()<<endl;
    //cout<<myLib1.getCountReadBooks("ninja1")<<endl;
    Library l16 = Library();
    l16.readRatings("ratings.txt");
   // int rv = l16.addUser("ben");
    cout << "addUser returned: " << rv << endl;
    

    //checkoutbook
    //Library myLib2;
   //myLib2.readBooks("fileName.txt");
    //myLib2.readRatings("ratings.txt");
    //int oldRating=myLib2.getRating("Ninja","Book 1");
  //  int rv= myLib2.checkOutBook("Ninja1","Book 1",1);
   // int newRating=myLib2.getRating("Ninja","Book 1");
  //  cout<<"rv= "<<rv<<endl;
   // cout<<"oldRating = "<<oldRating<<endl;
   // cout<<"newRating = "<<newRating<<endl;
    
    //getReccomendations
    Library myLib3;
    myLib3.readBooks("fileName.txt");
    myLib3.readRatings("ratings.txt");
    myLib3.getRecommendations("Ninja");
}