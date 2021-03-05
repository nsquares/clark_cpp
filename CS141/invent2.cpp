



// Nathan Nguyen
// Inventory Assignment
// CS 141
// last modified: 2/22/2021
#include <iostream>
using namespace std;

int printRecord(string product_name,double wholesale_price,int quantity,double retail_price,\
double total_price_paid);
//prints out the complete record of a product with a long cout statement

int main(){

  string product_name;
  double wholesale_price; //wholesale price per item
  int quantity;
  double total_price_paid; //by the company
  double markup; //represented as a percent which is 10 for 10%
  double retail_price;

  char userLoop; //holds user's reply to add another record

  cout<<static_cast<char>(12); //line feed






  do {
  cout<<"What is the product name (one word)? ";
  cin>>product_name;

  cout<<"Wholesale price per item? ";
  cin>>wholesale_price;

  cout<<"Quantity? ";
  cin>>quantity;
  total_price_paid = wholesale_price * quantity;

  cout<<"Markup (as a percent)? "; //has to be greater than one because I will convert numbe\
r to decimal and will add one when calculating retail
  cin>>markup;
  retail_price=wholesale_price*(1+(markup/100));


  printRecord(product_name,wholesale_price,quantity,retail_price,total_price_paid);

  cout<<"Add another record (Y/N)?\n";
  cin>>userLoop;


  } while( (userLoop=='Y') || (userLoop=='y') );

  return 0;
}








int printRecord(string product_name,double wholesale_price,int quantity,double retail_price,\
double total_price_paid){

  cout<<product_name<<", "<<wholesale_price<<", "<<quantity<<", "<<retail_price<<", "<<(reta\
il_price*quantity)-total_price_paid<<endl;
  //print out complete record to user

  return 0;
}
