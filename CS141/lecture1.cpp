// Farenhiet to Celius
// Nathan Nguyen
// 1/21/2021

#include<iostream>
using namespace std;

int main(){
/*  
    double f;
    double c;

    cout << "What is the temp in F?: ";
    cin >> f;

    c=(f-32)*5/9;
    c=(f-32)*(5.0/9.0); // to force a double  

    //try to always work in all ints or all doubles, bad practice to mix

    cout << "temp in c from f: " << c;

*/
    //if making a constant variable, use const in front and then the convention for naming is ALL CAPS

    const double SPEED_OF_SOUND = 1248; //ft per sec

    //cin throws away blanks and stops storing your input when it detects a blank or space
    //cin does not convert string to int or int to string but what if we use var keyword?

    //modulo == % //this gives only the remainder
//--------------------------------------------------
    //int a=5;
    //int b=-3;
    //cout<<a<<" modulo "<<b<<" equals "<<a%b<<endl;

    int principal=1000;
    double rate=0.05;

    principal=(rate+1)*principal;

    principal*=(1+rate);

    principal+=rate*principal;

    //ternary operator ? :

    //A=b?C:d;

    //

    return 0;
}