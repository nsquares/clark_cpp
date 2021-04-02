//all about functions

#include <iostream>
//#include <cmath>
using namespace std;

// ask the user for something and return an int
// parameters are min, max, and prompt

int getint (int min, int max, string prompt);


int main (){

    int number;

    number = getint(1,6,"roll the dice");
    cout<<"you rolled "<<number;

    return 0;
}




int getint (int min, int max, string prompt){

    int value;

    while(true){

    cout<<prompt<<": \n"<<"between "<<min<<" and "<<max<<endl;
    cin>>value;

    if ((value >=min)&&(value<=max)){
        return value;
    }
    }
}