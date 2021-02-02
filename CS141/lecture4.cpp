#include <iostream>
using namespace std;

void rockpapersci();


int main(){
    //ls -al command shows the permission of files and when they were made
    //exam on feb 11
    //rockpapersci();

    //binary
    //octal base 8 - groups of 3 bits
        //starting an inegral value with zero indicates this
    //hexadecimal - base 16 - groups of 4 bits
        //starting 0x indicates this
    //java uses unicode
    //all other languages uses ACSII

    //8 bits = one byte
    //ints have the first bit represent positive or negative like 0 means positive

    //char < short <= int <= long
    //unsigned int and longs do not have sign bit like positive or negative so one more bit can be used for counting


    //float are good for math bad for comparing
    //float < double < long double
    //double just have more presicion

    int a=11;
    int b=2;
    double c;
    c=a/b;
    c=static_cast<double>(a)/b; //force a to be a double
    //local variable is inside main
    //global variable is outside of main
    //if variables have the same name, innermost scope variable will be used

    



    return 0;
}

void rockpapersci(){

    char first, second; //player
    char repeat;
    bool win1, win2, tie;
    int wincount1=0;
    int wincount2=0;
    //do while loop
    do {
        cout<<"First choice: r,p,s: ";
        cin>>first;
        cout<<"Second choice: r,p,s: ";
        cin>>second;
        win1=tie=win2=false;

        switch (first){
            case 'p':{
                if (second=='p') tie=true;
                else if (second=='r') win1=true;
                else win2=true;
                break;
            }
            case 'r':{
                if (second=='r') tie=true;
                else if (second=='p') win1=true;
                else win2=true;
                break;
            } 
            case 's':{
                if (second=='s') tie=true;
                else if (second=='r') win1=true;
                else win2=true;
                break;
            }           
            default:{
                cout<<"please use either r, p, or s\n";
            }            
        }

        if (win1){
            wincount1++;
            cout<<"first wins\n";
        }
        if (win2){
            wincount2++;
            cout<<"second wins\n";
        }
        if (tie) cout<<"Tie\n";

        cout<<"Again? ";
        cin>>repeat;

    } while(repeat=='y' || repeat=='y');
    cout<<"Player 1 wins: "<<wincount2<<" Player 2 wins: "<<wincount2;

    //switch


}