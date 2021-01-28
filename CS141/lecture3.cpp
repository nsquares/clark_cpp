#include <iostream>
using namespace std;

void switchBoi(void); //so the russian guy on youtube said it is good practice to write void in the parameters if passing nothing at his university but idk bro
void loopBoi();
void romanNumCalc();

int main(){
    
    //switchBoi();
    //loopBoi();
    romanNumCalc();

    return 0;
}
//-----------------------------------------------------------------------------------------

void switchBoi(void){
    int num1, num2;
    char c;

    cout<<"give two numbers: ";
    cin>>num1>>num2;

    cout<<"basic operation: ";
    cin>>c;
    
    switch(c){

        case '+': {
            cout<<num1+num2;
            break;
        }
        case '-': {
            cout<<num1-num2;
            break;
        }
        case '*':  //thats how you do it properly
        case 'm':
        { //what, I found this on my own but how can this work
            cout<<num1*num2;
            break;
        }
        case '/':{
            cout<<num1/num2;  //forgot to add an if statement to handle divide by zero like prof but i already know
            break;
        }
        default:{   //like a last else statement but you dont have to have this boi
            cout<<"garbage, try again\n";
        }
        
    }
    //use switch for long if else statement chain

    //think menu = switch
}
//-------------------------------------------------------------------------------------------------------------------------------------------------

void loopBoi(){
        //do while has the test condition after the first loop run so at bottom

    int i=5;

    do{ //always run at least one (good example is ATM because why would the user turn on the machine if they at least wanted to do one thing?)
        cout << i <<" bottles of beer on the wall"<<endl;
        i--;
    } while (i>1);

    for (i=0; i<10; i++) { //for loop for counting 
        cout<<i<<" bottles of gatorade \n";
    }

    //DONT USE GOTO loops cuz old and bad practice

    //EXAM example?
    
    for (int j=1; j<=10; j++) {
        cout<<j<<" "<<j*j<<" "<< j*j*j<<endl;
    }

    //list ended by sentinel value so like end the loop when the user inputs something that will specifically end the loop
    //use do while loop most likely for this sentinel value ending

    //fencepost errors mean when to start and when to finish in a for loop and you are one or two off, thats understandable

    //nested loops are used to analyze all pixels on a screen or image, interesting
}
//----------------------------------------------------------------------------------------------------------------------------------------------------
void romanNumCalc(){  //unfinished by prof because he got tired and lazy and endded class early, pogchamp
    //roman numerals
    int number;
    cout<<"give a number: ";
    cin>>number;

    while (number>=1000){
        cout<<"M";
        number-=1000;
    }
    if (number>=900){
        cout<<"CM";
        number-=900;
    }
    if (number>=500){
        cout<<"D";
        number-=500;   
    }
    while (number>=100){
        cout<<"C";
        number-=100;
    }
    cout<<endl;

}