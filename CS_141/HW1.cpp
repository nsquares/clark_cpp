// Nathan Nguyen
// HW 1
// CS 141
#include <iostream>
using namespace std;

int main(){

    string product_name;
    double wholesale_price; //wholesale price per item
    int quantity;
    double total_price_paid; //by the company
    double markup;
    double retail_price;  

    cout<<"What is the product name (one word)? ";
    cin>>product_name;
    
    cout<<"Wholesale price per iterm? ";
    cin>>wholesale_price;

    cout<<"Quantity? ";
    cin>>quantity;
    total_price_paid = wholesale_price * quantity;

    cout<<"Markup (less than 1 so in decimal format)? "; //has to be less than one because I will add one when calculating retail and will not convert number to decimal
    cin>>markup;
    retail_price=wholesale_price*(1+markup);

    cout<<product_name<<", "<<wholesale_price<<", "<<quantity<<", "<<total_price_paid<<", "<<retail_price<<", "<<(retail_price*quantity)-total_price_paid;
    //print out complete record to user

    return 0;
}
