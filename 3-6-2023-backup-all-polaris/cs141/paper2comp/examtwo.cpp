#include <iostream>
using namespace std;


void somethingref(int &num);

int main(){
  char temp;
  int mainNum;

  cout<<"give me a string and lets see what I get with a char variable:\n";
  cin>>temp;

  cout<<"\n"<<temp<<endl;

  cout<<"give me a number:\n";
  cin>>mainNum;

  cout<<"outside before the function (and right before the 3*num expression ref parameter passing): "<<mainNum;

  somethingref(3*mainNum); //so I am right, this is false and cannot be done with ref parameters, POG CHAMP
  //complier fucking explodes lol 

  cout<<"outside the function (after the 3*mainNum expression): "<<mainNum;




  return 0;
}


void somethingref(int &num){

  cout<<"inside the function: "<<num;

}
