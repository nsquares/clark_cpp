// Nathan Nguyen
// Inventory Assignment lab8 (only reading files up to "END")
// CS 141
// last modified: 3/19/2021
#include <iostream>
#include <fstream>
using namespace std;



int main(){

  string product_name;
  char temp; //everything after product name



  ifstream in;
  char filename[80];

  cout<<"File name to read in instead of write out?: ";
  cin>>filename;  //ask the user for the name of a file to write info in

  in.open(filename);
  if(in.fail()){                          //check if it failed or not
    cout<<"Cannot open "<<filename<<endl;
    return 0;
  }


  //cin.ignore();

  while(!in.eof()) {



  //cin.ignore(); //I need clean out the \n from the cin>>filename statement above this line
  getline(in,product_name);

  if(product_name=="END"){
    cout<<product_name<<endl;
    break;
  }

  else{

    cout<<product_name<<endl;
    while(temp!='\n'){
      in.get(temp);
      cout<<temp;
    }
  }

  }

  in.close();

  return 0;
}

