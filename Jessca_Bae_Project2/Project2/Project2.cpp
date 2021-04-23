// CS1300 Spring 2019
// Author: Jessica Bae
// Recitation 208 - Josh Ladd
// Cloud9 Workspace Editor Link: https://ide.c9.io/jeba1121/jb_workspace
// Project 2 - Problem # 11
#include <iostream>
#include <string>
#include <array>
#include <math.h>
#include <fstream>
#include <algorithm>

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



//////////////////////////////////////////////////////////////////////////////////
// -- book class
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
//////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////
// -- user class
 
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

User::User()
{
    username="";
    numRatings=0;
    size=50;
    for(int i=0;i<size;i++)//initialize ratings back to 0
    {
         ratings[i]=0;
    }
}

User::User(string uname,int newRatings[],int newNum)
{
    size=50;
    for(int i=0;i<size;i++)
    {
        ratings[i]=0;
    }
    username=uname;
    if(newNum<=size)
    {
        numRatings=newNum;
    }
    
    for(int i=0;i<numRatings;i++)//numRatings cannot be greater than 50
    {
        ratings[i]=newRatings[i];
    }
}
string User::getUsername()
{
    return username;
}
void User::setUsername(string u)
{
    username=u;
}
int User::getRatingAt(int idx)//return rating scored at that index if index is less than numRatings
{
    if(idx>=size)
    {
        return -1;
    }
    else
    {
        return ratings[idx];
    }
    
}
bool User::setRatingAt(int idx, int value)
{
    if((idx<size) && idx>=0)//if index within bounds of array and value is 0-5
    {
        if(value>=0 && value<=5)
        {
            ratings[idx]=value;//update rating to value at specified index
            return true;
        }
    }

    return false;
}
int User::getNumRatings()
{
    return numRatings;
}
void User::setNumRatings(int value)
{
    numRatings=value;
}
int User::getSize()
{
    return size;
}
//////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////////
// -- library class
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
//////////////////////////////////////////////////////////////////////////////////


// -- library class: constructor


// -- library class: getters/setters

// -- library class: methods (and other functions)


// printAllBooks
// cout << "Here is a list of books" << endl;

// viewRatings
// cout << username << " does not exist." << endl;
// cout << username << " has not rated any books yet." << endl;
// cout << "Here are the books that "<< name << " rated" << endl;
// cout << "Title : " << title << endl;
// cout << "Rating : " << rating << endl;
// cout << "-----" << endl;

// getRecommendations
// cout << username << " does not exist." << endl;
// cout << "Here is the list of recommendations" << endl;
// cout << title << " by " << author << endl;
// cout << "There are no recommendations for " << username <<" at present."<<endl;

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
        totalRating+=rating;
    }
    if(userIdx==-1)
    {
        cout<<username<<" does not exist."<<endl;
    }
    if (totalRating==0)
    {
        cout<< username<<" has not rated any books yet."<<endl;
    }
    if (totalRating!=0 && userIdx!=-1)
    {
        
        cout<<"Here are the books that "<<original<<" rated"<<endl;
        for(int i=0;i<numBooks;i++)
        {
            int rating=users[userIdx].getRatingAt(i);
            totalRating+=rating;
            if(rating!=0)
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
        if(bookName==title)
        {
            bookIdx=i;
            for(int j=0;j<numUsers;j++)
            {
                int rating=users[j].getRatingAt(bookIdx);
                if(rating!=0)
                {
                    count++;
                }
                totalRating+=rating;
            }
        }
    }
    avgRating=totalRating/count;
    
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
    string name="";
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
            name= users[i].getUsername(); //save the getusername to string name
            transform(name.begin(),name.end(),name.begin(),::tolower);//convert name to lowercase
            if(name!=username)
            {
                idx=i+1;
            }
            
        }
        if(name==username)
            {
                return 0;
            }
        else if(name!=username)//if you cant
            {
                users[numUsers].setUsername(original);
                users[numUsers].setRatingAt(idx,0);
                numUsers++;
                return 1;
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
        return -3;
    }
    bool result=users[userIdx].setRatingAt(bookIdx,rating);
    
    if(!result)
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
            userIdx=i;
        }
        for(int j=0;j<numBooks;j++)
        {
            ratings=users[userIdx].getRatingAt(j);
            if(i!=userIdx)
            {  
                otherRatings=users[i].getRatingAt(j);
                ssd+=pow(ratings-otherRatings,2);
            }
            
        }
        total=ssd;
        ssd=0;
        if(total>0 || total<smallest)
        {
            smallest=total;
            otherIdx=i;
            break;
        }
    }
    
    if(userIdx!=-1)
    {
        for(int j=0;j<numBooks;j++)
        {
            closestR=users[otherIdx].getRatingAt(j);
            ratings=users[userIdx].getRatingAt(j);
            if(ratings==0 && closestR>=3)
            {
                bookIdx=j;
                cout<<"Here are a list of recommendations"<<endl;
                cout<<books[bookIdx].getTitle()<<" by ";
                cout<<books[bookIdx].getAuthor()<<endl;
                result++;
            }
            
        }
        if(result==0)
        {
            cout<<"There are no reccomendations for "<<original<<" at present"<<endl;
        }
    }
    if(userIdx==-1)
    {
        cout<<original<<" does not exist."<<endl;
    }
    
}

/* displayMenu:
 * displays a menu with options
 * DO NOT MODIFY THIS FUNCTION
 */
void displayMenu(){
	cout << "Select a numerical option:" << endl;
	cout << "======Main Menu=====" << endl;
	cout << "1. Read book file" << endl;
	cout << "2. Read user file" << endl;
	cout << "3. Print book list" << endl;
	cout << "4. Get rating" << endl;
	cout << "5. Find number of books user rated" << endl;
	cout << "6. View ratings" << endl;
	cout << "7. Get average rating" << endl;
	cout << "8. Add a user" << endl;
	cout << "9. Checkout a book" << endl;
	cout << "10. Get recommendations" << endl;
	cout << "11. Quit" << endl;
}


int main(int argc, char const *argv[]) {

	// temp variables
    string choice;
    string bookFileName;
    string userFileName;
    string userName, bookTitle;
    string strRating;
    Library();
    Library myLib;
    int sizeBook=50;
    int sizeUser=100;
    int numBooks;
    int numUsers;
    int rv;
    int user;
    int rate;
    int count;
    double ans;
    int success;
    int check;
    

    while (choice != "11") {
        displayMenu();

        // take a menu opton
        getline(cin, choice);

        // convert the `choice` to an integer
        int menuChoice = stoi(choice);

        switch (menuChoice) {

            case 1:
                // Initialize library -- readBooks
                cout << "Enter a book file name:" << endl;
                getline(cin, bookFileName);
                
                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                rv=myLib.readBooks(bookFileName);
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code.
                // readBooks returned -1
                if(rv==-1)
                {
                    cout << "No books saved to the database." << endl;
                }
                // readBooks returned -2
                else if(rv==-2)
                {
                    cout << "Database is already full. No books were added." << endl;
                }
                // readBooks returned book arr size
                else if(rv==sizeBook)
                {
                    cout << "Database is full. Some books may have not been added." << endl;
                }
                // readBooks returned otherwise
                else
                {
                    cout << "Total books in the database: " << rv << endl;
                }

                numBooks=rv;

                cout << endl;
                break;

            case 2:
                //  Initialize user catalog -- readRatings

                cout << "Enter a user file name:" << endl;
                getline(cin, userFileName);


                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                user= myLib.readRatings(userFileName);
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code.
                // readRatings returned -1
                if(user==-1)
                {
                    cout << "No users saved to the database." << endl;
                }
                // readRatings returned -2
                else if(user==-2)
                {
                    cout << "Database is already full. No users were added." << endl;

                }
                // readRatings returned user arr size
                else if(user==sizeUser)
                {
                    cout << "Database is full. Some users may have not been added." << endl;
                }
                // readRatings returned otherwise
                else
                {
                    cout << "Total users in the database: " << user << endl;
                }
                numUsers=user;

                cout << endl;
                break;

            case 3:
                // Display library -- printAllBooks

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////

                // If the database has not been initialized

                if(numBooks==0 || numUsers==0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    myLib.printAllBooks();
                }

                cout << endl;
                break;

            case 4:
                //  Get a rating -- getRating

                //////////////////////////////////////////////////////////////////////////
                // Your code here. Call the appropriate function(s).
                //////////////////////////////////////////////////////////////////////////

                // Use the below messages and match them to the return code. Update variables as needed.


                // If the database has not been initialized
                if(numBooks==0 || numUsers==0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                        // take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
    
                    // take book title
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle);
                    
                    rate=myLib.getRating(userName,bookTitle);
                    // getRating returned 0
                    if(rate==0)
                    {
                        cout << userName << " has not rated " << bookTitle << endl;
                    }
                    // getRating returned -3
                    else if(rate==-3)
                    {
                        cout << userName << " or " << bookTitle << " does not exist." << endl;
                    }
                    // getRating returned other than 0 or -3
                    else
                    {
                        cout << userName << " rated " << bookTitle << " with " << rate << endl;
                    }
                    // 
                    
                }
                

                cout << endl;
                break;

            case 5:
                // Get number of books the user has rated -- getCountReadBooks

                // If the database has not been initialized
                if(numBooks==0 || numUsers==0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
                    
                    count=myLib.getCountReadBooks(userName);
                    
                    
                    // getCountReadBooks returned 0
                    if(count==0)
                    {
                        cout << userName << " has not rated any books." << endl;
                    }
                    // getCountReadBooks returned -3
                    else if(count==-3)
                    {
                        cout << userName << " does not exist." << endl;
                    }
                    // getCountReadBooks returned other than 0 or -3
                    else if(count!=0 || -3)
                    {
                        cout << userName << " rated " << count << " books." << endl;
                    }

                }
                
            	cout << endl;
                break;

            case 6:
                // View user’s ratings -- viewRatings

                // If the database has not been initialized
                if(numBooks==0 || numUsers==0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    // take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
                    myLib.viewRatings(userName);
                    

                }
        		
            	cout << endl;
                break;

            case 7:
                // Calculate the average rating for the book -- calcAvgRating

                // If the database has not been initialized
                if(numBooks==0 || numUsers==0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    	// take book title
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle);
                    ans=myLib.calcAvgRating(bookTitle);
                    // calcAvgRating returned -3
                    if(ans==-3)
                    {
                        cout << bookTitle << " does not exist." << endl;
                    }
                    // calcAvgRating returned other than -3
                    else
                    {
                        cout << "The average rating for " << bookTitle << " is " << ans << endl;
                    }
                }
        	
            	cout << endl;
                break;
            case 8:
                // Add a user to the database -- addUser
        		// take user name
                cout << "Enter username:" << endl;
                getline(cin, userName);
                
                success=myLib.addUser(userName);
                // addUser returned 1
                if(success==1)
                {
                    cout << "Welcome to the library " << userName << endl;
                }
                // addUser returned 0
                else if(success==0)
                {
                    cout << userName << " already exists in the database." << endl;
                }
                // addUser returned -2
                else if(success==-2)
                {
                    cout << "Database is already full. " << userName << " was not added." << endl;
                }
            	cout << endl;
                break;
            case 9:
                // Check out the book -- checkOutBook
                
                // If the database has not been initialized
                if(numBooks==0 || numUsers==0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
                    // take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
    
                    // take book title
                    cout << "Enter book title:" << endl;
                    getline(cin, bookTitle);
    
                    // take rating
                    cout<<"Enter rating for the book:"<<endl;
                    getline(cin, strRating);
                    int rating=stoi(strRating);
                    
                    check=myLib.checkOutBook(userName,bookTitle,rating);
    
                    // checkOutBook returned 1
                    if(check==1)
                    {
                        cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                    }
                    // checkOutBook returned -4
                    if(check==-4)
                    {
                        cout << strRating << " is not valid." << endl; 
                    }
                    // checkOutBook returned -3
                    if(check==-3)
                    {
                        cout << userName << " or " << bookTitle << " does not exist." << endl;
                    }    
                }
        		
            	cout << endl;
                break;
            case 10:
                // get recommendations  -- getRecommendations

                // If the database has not been initialized
                if(numBooks==0 || numUsers ==0)
                {
                    cout << "Database has not been fully initialized." << endl;
                }
                else
                {
            		// take user name
                    cout << "Enter username:" << endl;
                    getline(cin, userName);
                    myLib.getRecommendations(userName);
                }

            	cout << endl;
                break;

            case 11:
                // quit
                cout << "good bye!" << endl;
                break;

            default:
                cout << "invalid input" << endl;
                cout << endl;
        }
    }

    return 0;
}