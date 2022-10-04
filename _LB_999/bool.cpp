#include <iostream>
using namespace std;

#define MAX 3

int main()
{
    //thinking of making a for loop {switch statement{ write three functions like notThis(bool&), orThese(bool, bool), andThese(bool, bool) } } //that goes as long as there are things to calculate in the expression inputted by user
    //end of for loop is print the inputs and the output, after the for loop finishes, the screen should have a truth table

    //bool a,b,c,d;


    bool input[MAX];

    //what if I just use typedefs and then pull bits out in specific positions and then convert num to bool?

    uint8_t number = 7;
    uint8_t holder;

    //how about I just have the user input the input values like 0000 0001 0010 ........ and have an array of bools
        //for loop with the array of bools and populate with first line of values from user keyboard input and then print output, then next loop is clear array and populate based on the second line of keyboard input and then print output of that set of input
    int value;
    
    
    for(int i=0; i<(2^MAX); i++)
    {        
        bool x,y,a,b,c,d;

        for(int j=0; j<MAX; j++)
        {
            cin>>value;
            input[j] = (bool)value;
            //cout<<input[j]<<endl; //debug
        }
        a=input[0];
        b=input[1];
        c=input[2];
        //d=input[3];


        //x = (!b) & ( (!c) | (a & d) );  //if you input 0011, x and y are not equal to each other..........................
        
        
        //ima be honest, would this be faster to program in matlab?

        //or fuck that and write your own 2-D array lookup table for the input because the input will always be the same for testing all problems (what I should do is DCBA instead of ABCD when populating and writing my answers on HW so everything is synced in and this method is easier to program)

        //y= ((!a)&(!b)&(!c)) | (a & (!b) & (!c)) | ( (!a) & (!b) & d);

        y=!( !(a|b) & !( b|(!c) ) );



        //cout<<"Output x: "<<x<<endl;

        cout<<"Output y: "<<y<<endl;
    }    



    return 0;
}