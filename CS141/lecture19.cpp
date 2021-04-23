//objects (main difference between cpp and c)
//and classes

#include <iostream>

using namespace std;

class Date{
private:
    int total; //assume 12 months and 30 days each
    //so the benefit is that we change message representation and the main is untouched and does not care how the date class works, main sending messages and receivieng is standard and does not need to change

    int month;
    int year;
    int day;
public:
    void p_date() const;  //dont change the object due
    void g_date();
    bool before(const Date d) const;
    //constructors are functions so they can do work on variables
    Date(int,int,int);

    Date();
    //accessors
    friend bool pre (const Date, const Date);
    //you can also overload operators
    friend bool operator < (const Date, const Date); //operators are really functions

    friend Date operator + (const Date, const Date);

    friend ostream& operator << (ostream& outs, const Date d); //not on test
    friend istream& operator >> (istream& ins, Date &d); //not on test
    //whats special here is that they have to pass and return streams 


    //mutators change private data in class

    

};

istream& operator >> (istream& ins, Date &d){
    ins>>d.month;
    ins.get(); //user need to add the slash
    ins>>d.day;
    ins.get();
    ins>>d.year;

    return ins;
}


ostream & operator << (ostream & outs, const Date d){ //not on the test
    outs<<d.month<<"/"<<d.day<<"/"<<d.year<<endl;
    return outs;
}


Date operator + (const Date d1, const Date d2){
    Date new_date;
    new_date.year = d1.year + d2.year;
    new_date.month = d1.month + d2.month;
    new_date.day = d1.day + d2.day;
if (new_date.day>30){
    new_date.day -= 30;
    new_date.month++;

}

if (new_date.month>12){
    new_date.month -= 12;
    new_date.year++;

}
    return new_date;
}


bool operator < (const Date d1, const Date d2){
    if(d1.year < d2.year) return true;
    else if (d1.year >d2.year) return false;
    if (d1.month<d2.month) return true;
    else if (d1.month >d2.month) return false;
    if (d1.day<d2.day) return true;
    else return false;
}


bool pre (const Date d1, const Date d2){
    if(d1.year < d2.year) return true;
    else if (d1.year >d2.year) return false;
    if (d1.month<d2.month) return true;
    else if (d1.month >d2.month) return false;
    if (d1.day<d2.day) return true;
    else return false;
}


//how to access two objects in one function? friend functions

Date::Date(){

    month=year=day=0;
}


//all about sperating implementation for user interface

/* quiz

-a class is a user defined data type that is abstract and has data variables and member functions

-variables of a class are called objects

-dot operator is used to access members of the objects, (data member or function members)

-:: operator is to access within scope of a class (called the "scope resolution operator") (this is used in general for namespace std and trying to access things that are outside of scope)
    -so like you can define member functions outside the class by using this operator or you can just defined it inside the class and never use this operator.......... okay prof.

-


*/

//there is an error because all instances point to this constructor, we need a constructor that is blank (time to overload)
//constructor
Date::Date(int m, int d, int y){

    month = m;
    day = d;
    year = y;
}


void Date::p_date() const{    //we are inside the class date so no dot operator
    //int month,year,day;

/*
    year=total /360;
    month=(total-(year*360)) / 30;
    day=total - (year*360) -(month*30);
*/

    cout<<month<<"/"<<day<<"/"<<year;

    //total++; //this cannot be done because const keyword


}


void Date::g_date(){
    //int year, month, day;
    cout<<"month day year: ";
    cin>>month>>day>>year;

    //total = year*360 + month*30 +day;
} 



//dont change date d and dont change due if invoked with due object/class?
bool Date::before(const Date d) const{ //bool return of the class date

    if(year<d.year){
        return true;
    }
    else if (year>d.year) return false;

    if (month<d.month) return true;
    else if (month>d.month) return false;

    if (day<d.day) return true;
    else return false;
    

   //if (total<d.total) return true; else return false;

}



int main(){

    Date checkout; //this is an instance of the class and is called an object?
    int intvariable; //just like how this is an instance of an int
    //"intvaraible" is an object of type int, so these variables are all objects?


    Date today(4,15,2021);
    Date onemonth(1,0,0);

    cout<<"Today is: ";
    today.p_date();
    cout<<endl;

    cout<<today;

    string something; //string is an object

    Date due; //store due date here after getting a checkout date

    //checkout.g_date();
    cin>>checkout;

    //cin>>due;



    //cout<<checkout.month;  //this is now private date and cannot use it in main (only can use it in member functions)



    due = checkout + onemonth; //plus operator returns a date

    cout<<"checkout date: ";
    checkout.p_date(); //call to member function
    cout<<endl;


    cout<<"Due day: "<<due;


    if (due.before(checkout)) cout<<"cannot be due before checkout";
    if (pre(due,checkout)) cout<<"can\'t be due before checkout";
    if (due < checkout) cout<<"cannot be due before checkout";


/*

cout.width(30);                   //have to set width right before you use left and right justified
cout<<left<<"This is a test";
cout<<right<<"and another test\n";


-functiosn hide the details of something is done

-data structures (or struct) group data in a useful way and is not hidden, and has to be managed 

-string is an object


instead of struct, write a class and put public keyword and thats how you make this hidden like a fucntion


-class is like a struct and both classes and structs can have objects within them which are instances or calls of other classes or structs

-step two after making a class:
-write a member function within class declaration


:: is the "scope resolution" operator

:: is used with a class name

dot is used with an object in a class





-objects holds the data privately
-program sends messages to objects through member functions or operators



const--------------------------------------------

item is data type (struct or class)
groceries is a object of struct or class

void print_stuff (const Item &groceries)  //this is how you protect ref parameters to not be changed in function

-value parameters do not need cosnt
-you can put a const keyword in all parameters pretty much
-also, once you call a variable const, always write const with it everywhere else





classes--------------------------------------

think about these three when writing classes
-constructors
-accessors
-mutators/modifiers


*/






    return 0;
}