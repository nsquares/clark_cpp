// loops

#include <iostream>
using namespace std;

int main(){

    int inputTemp, sumOfEvens;

    cout<<"Give a list of even numbers and insert any odd number at the end: ";
    cin>>inputTemp;

    while ((inputTemp%2) == 0){
        
        sumOfEvens+=inputTemp;
        cin>>inputTemp;
    }
    cout<<"Sum of the evens is "<<sumOfEvens<<endl;

    return 0;
}