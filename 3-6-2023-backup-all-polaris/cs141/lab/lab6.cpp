// Nathan Nguyen
// CS 141 Lab 6 files
// 3/5/21

#include <iostream>
#include <fstream>
using namespace std;

int main(){

  char advice;
  int count=0;    //this is for counting '\n' back to back
  ifstream in;
  ofstream out;


  cout<<">>>Previous advice: \n";
  in.open("advice.txt");

  while(in.get(advice)){ //if at the end of the file and no more char to read, it will be false
    cout<<advice;
  }

  in.close();

  
  cout<<"\n>>>Your advice to next user. Hit ENTER twice to exit:\n";
  out.open("advice.txt");
  
  
  while(count<2){   //end after two '\n'
    cin.get(advice);
    out.put(advice);

    if(advice=='\n') //count first and when back to back
      count++;
    else if(advice!='\n'&&count==1) //only subtract when count once already so it is never negative or less than zero
      count--;
  }

  cout<<"Thanks for your advice.\n\n";

  return 0;
}
