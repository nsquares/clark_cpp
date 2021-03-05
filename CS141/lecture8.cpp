//1) determine the type and number of parameters
//2) 

//1 determine parameters

//2 determine type of return or the type of func

//3 delcare at top, above main

//4 define below main


#include <iostream>
using namespace std;
const double PI = 3.14159;

void printName(string first, string last);
// print last then first

void clear();
//clear the screen and bell trigger

int getage();
//ask for the person's age


//overloading
double volume(double r); //sphere volume
double volume(double r, double h); //cylinder volume (radius and height)
double volume(double l, double w, double h); //box volume (sides)

int main (){
   /* int person_age;
    string first, last;

    clear();

    cout<<"first name? ";
    cin>>first;

    cout<<"last name? ";
    cin>>last;   

    person_age = getage();

    printName(first, last);
    cout<<"age: "<< person_age;
*/
    double side1=10;
    double side2=20;
    double side3=30;

    double vol;

    vol=volume(side1);
    cout<<"sphere vol with radius side1: "<<vol<<endl;

    vol=volume(side1,side2);
    cout<<"cylinder vol with radius side1 and height side2: "<<vol<<endl;

    vol=volume(side1, side2, side3);
    cout<<"box: "<<vol;


    return 0;
}

void printName(string f, string l){  //bad funciton in reality cuz one liner
    cout<<l<<", "<<f;
    return; //could write this for a void function 
        //dont have to write it but it is useful for breaking out of loops in a void function, lol
}

void clear(){                      //good func to reduce complexity
    cout<<static_cast<char>(12);
    cout<<static_cast<char>(7);
}

int getage(){        //get int is more worth writing than this func
    int a;
    cout<<"age: ";
    cin>>a;
    return a;
}






double volume(double r){
    return(PI*4.0/3.0*r*r*r);
}

double volume(double r, double h){
    return(PI*r*r*h);
}

double volume(double a, double b, double c){
    return(a*b*c);
}