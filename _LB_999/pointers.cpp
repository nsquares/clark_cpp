
#include <iostream>

using namespace std;


int main(void){

  int y[] = {3,9,10};
  int* ypointer = y;

  cout<<y<<endl;

  cout<<*y<<endl;



  //these are all the same--------
  cout<<*(ypointer+1)<<endl;
  cout<<*(y+1)<<endl;
  cout<<&y[1]<<endl;

  return 0;
}