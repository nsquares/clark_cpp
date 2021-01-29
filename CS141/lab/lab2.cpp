// Nathan Nguyen
// lab2.cpp (Simple ATM)
// CS 141
// 1/28/21

#include <iostream>
using namespace std;

int main(){
    double balance = 1000.00;   //user's money
    double userAmountInput;     // how much the user wants to add or substract to balance
    char userSelection;         //for the switch case / main menu of the ATM

    cout<<"What would you like to do?:"<<endl;
    cout<<"--(C)heck your balance"<<endl;
    cout<<"--(D)eposit"<<endl;
    cout<<"--(W)ithdraw"<<endl;
    cout<<"--(E)xit"<<endl;
    cin>>userSelection;

    switch (userSelection){
        case 'C':              //user could use capital or not but should be treated the same
        case 'c':{
            cout<<"Your current balance is: "<<balance<<endl;
            break;
        }
        case 'D':
        case 'd':{
            cout<<"How much money do you want to deposit?"<<endl;
            cin>>userAmountInput;
            cout<<"Your new balance is: "<<userAmountInput+balance;
            break;
        }
        case 'W':
        case 'w':{
            cout<<"How much money do you want to withdraw?"<<endl;
            cin>>userAmountInput;

            if(userAmountInput<=balance){
                cout<<"Your new balance is: "<<balance-userAmountInput;
            }
            else{
                cout<<"Cannot do that, will go into negative or is invalid"<<endl;
            }

            break;
        }
        case 'E':
        case 'e':{
            cout<<"Bye";
            break;
        }
        default:{
            cout<<"Input is not 'C,D,W, or E' so will exit anyways."<<endl;
        }
    }

    return 0;
}