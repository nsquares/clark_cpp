// 1/26/2021
//Nathan Nguyen
//cs141

// conditions like if statements
//braking distance

// mph to meters/sec
//reaction time is 500 ms (half seconds)

//how far traveling before braking and after

//v=v0+at
//initial speed * reaction time =distance spent before braking

// 1/2 initial speed * braking time =distance spent after braking


#include <iostream>
using namespace std;
int main()
{
    /*
    double start_speed;
    double reaction_time;
    double cof; // coefficient of friction
    const double mph_to_mps=0.45;
    double speed_mps;
    double time_to_stop;
    const double g=9.8;
    double distance_to_stop;

    cout<<"how fast u going in mph? ";
    cin>>start_speed;
    speed_mps=start_speed*mph_to_mps;

    cout<<"reaction time in seconds ";
    cin>>reaction_time;
    
    cout<<"coefficient of frict, 0.0 - 1.0? ";
    cin>>cof;

    time_to_stop=speed_mps/(g*cof);
    distance_to_stop=time_to_stop*speed_mps/2.0;

    distance_to_stop += speed_mps * reaction_time;

    cout<<"it will take you " << time_to_stop+reaction_time <<endl;
    cout<<"distance is stop is meters " << distance_to_stop <<endl;

*/
    //data structures are like bool string int
    //control structures like if statements
//-------------------------------------------------------------------------------------------------
    // {} to if statements is a compound if statement

/*
    int num1, num2;
    char c;

    cout<<"give two numbers: ";
    cin>>num1>>num2;

    cout<<"+ or - ";
    cin>>c;
    

    if(c=='+') cout<<num1+num2;
    else if (c=='-') cout<<num1-num2; //will always trigger
    else cout<<"garbage, try again\n";


    */

//------------------------------------------

    int num;
    cout<<"give num ";
    cin>>num;

    if ((num%2) == 0){
        cout<<num<<" is divisible by 2\n";
    }
    if ((num % 3) ==0){
        cout<<num<<" is divisble by 3\n";        
    }
    if (((num%2)==0) && ((num%3) ==0)){
        cout<<num<<" is divisible by 6\n";
    }

    return 0;
}


