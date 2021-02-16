// functions mainly

#include <iostream>
#include <cmath> //use this to make double functions? and another file include which is:
#include <cstdlib> //this is standard c library that can be used in c++

using namespace std;

const double PI = 3.14159;
void pizza();
void tri();
int getint(int min, int max, string prompt); //write out the parameters/arugments when declaring, these are exactly the same as the ones in its definition, this is good practice only for readability
//teacher did it so as the textbook


int calc_val(int hund, int tens, int units); 
//dont have to name the parameters here in declaring but it is useful 
// for the programmer to remember what parameter is what in what order so always write it

// Like it could all be 'int calc_val(int, int, int)'



int main(){

//linux power user
// grep (find expressions or files that you forgot the location of)
// ls -al gives more info about ls

//prompt is a message on a screen to show that the system is waiting for input

//PEBKAC (clueless user joke for IT ppl)
//problem exist between keyboard and chair, the user/human

//do not use ^ in c++ for exponents, it means something else

// #include<cmath> to use math functions

// area = pi*r*r


//polaris crashed so just commenting
//how to write a function

//1 determine parameters

//2 determine type of return or the type of func

//3 delcare at top, above main

//4 define below main

//the parameters that are passed are the values of the expressions, variables, or constants
//variables in functions disappear when the function ends

//functions are called subroutines also and 


//void functions
    //just go do things and dont care about return
    //just a prompt or go does its own thing
    //can or cannot return values like in cout statements wise
    //and can or cannot have parameters



//overloading, pushed off to next class

//no functions on the exam





    pizza();

    return 0;
}

void tri(){
    double length,width;
    double angle;

    cout<<"leng";
    cin>>length;

}



void pizza(){
    int l, w;
    double area;
    double r;

    cout<<"Enter length and width: ";
    cin>>l>>w;                          //the correct way to cin multiple variables in one line of code, dont use l, w like the way it was declared, idk why teacher did that

    area=l*w;
    r=sqrt(area/PI);
    
    cout<<"Radius "<<r<<endl;
}

int calc_val(int hund, int tens, int units){

    return(100*hund+10*tens+units);
}



int getint(int min, int max, string prompt){
    int userAnswer;
    do {
    cout<<"give me a number between "<<min<<" and "<<max;
    cin>>userAnswer;

    if((userAnswer>=min)&&(userAnswer<=max)){
        return userAnswer;
    }


    } while(!((userAnswer>=min)&&(userAnswer<=max)));

    return 0;

}

void clear(){
    cout<<static_cast<char>(12);
}