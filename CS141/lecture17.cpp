//structs

#include <iostream>
using namespace std;

struct Point{ //create your own types and group variables together

    double x;
    double y;
};  //outside of main so all functions can use it

//can use structs that contain structs

//you cannot cout a struct


//Month this_month; //struct that has an array int in it
//this_month.day[15]

//you can have an array of structs

struct Date{ //order does not matter because dot operator and writing the int name so doesnt matter
    int year;
    int month;
    int day;

};

struct Book{
    string name;
    Date duedate;
};


void printslope (Point, Point);

void print_date(Date);
Date get_date(string);
bool check_dates(Date, Date);

Point input();

int main(){

    Point start;
    Point end = {4.0,-2.0};

    start.x=2.0;
    start.y=3.0;

//    start=input();
    printslope(start,end);

    Date checkout;
    Date due;
    Book b={"A Tale of Two Cities"}; //automatcally placed in string
    b.duedate=get_date("Book due date ");

    checkout=get_date("What is the checkout date ");
    due=get_date("What is the due date ");

    cout<<"Now we need to check if ";
    print_date(due);
    cout<<" is after ";
    print_date(checkout);
    cout<<endl;

    cout<<"The answer is "<<check_dates(checkout,due)<<endl;



/*
//homework 3:
while (true){
    getline(infile,name);
    if(name=="end"){
    infile.close();
    return 0;
    }
}

-right arrow right arrow and getline();, be careful like I already found out last night


-how to output cout statements in color lol (download this presentation)

basic types: int bool double char
classes and objects: strings, vectors, streams
type that groups similar basic types: arrays

data type that groups different basic types of data or variables into one data type or variable:  struct

-struct is a user-defined data type



whats good?

-you can store an entire record in one variable
-you can create your own type to hold whatever you want
-you can return an entire struct from a function

-classes and objects are much better than structs
    -if you change the implementation, you have to run around all your code and look for all occurrences in structs


*/






    return 0;
}
Point input(){
    Point ret;
    cout<<"enter two values ";
    cin>>ret.x>>ret.y;
    return ret;
}


void printslope (Point a, Point b){

    double slope;

    slope=(b.y-a.y) / (b.x-a.x);

    cout<<"slope from "<<a.x<<", "<<a.y<<" to "<<b.x<<", "<<b.y<<endl;

    cout<<"is "<<slope<<endl;
    return;

}

void print_date(Date d){

    cout<<d.month<<"/"<<d.day<<"/"<<d.year;
}

Date get_date(string prompt){

    Date ret;
    cout<<prompt;
    cin>>ret.month>>ret.day>>ret.year;

    return ret;
}

bool check_dates(Date d1, Date d2){
    if(d1.year<d2.year) return true;
    else if (d1.year == d2.year){
        if (d1.month<d2.month) return true;
        else if (d1.month == d2.month){
            if (d1.day<d2.day) return true;
        }
    }
    return false;
}