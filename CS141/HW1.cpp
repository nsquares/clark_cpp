// Nathan Nguyen
// Inventory Assignment (HW1)
// CS 141
// last modified: 2/2/2021
#include <iostream>
using namespace std;

int main(){

    string product_name;
    double wholesale_price; //wholesale price per item
    int quantity;
    double total_price_paid; //by the company
    double markup; //represented as a percent which is 10 for 10%
    double retail_price;  

    cout<<"What is the product name (one word)? ";
    cin>>product_name;
    
    cout<<"Wholesale price per item? ";
    cin>>wholesale_price;

    cout<<"Quantity? ";
    cin>>quantity;
    total_price_paid = wholesale_price * quantity;

    cout<<"Markup (as a percent)? "; //has to be greater than one because I will convert number to decimal and will add one when calculating retail 
    cin>>markup;
    retail_price=wholesale_price*(1+(markup/100));

    cout<<product_name<<", "<<wholesale_price<<", "<<quantity<<", "<<total_price_paid<<", "<<retail_price<<", "<<(retail_price*quantity)-total_price_paid;
    //print out complete record to user

    return 0;
}
