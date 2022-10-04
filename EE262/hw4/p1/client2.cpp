#include<iostream>
#include<string>
#include"triple.h"

using std::string;
using std::endl;
using std::cout;

using simSequence::Triple;

int main(void) {

  //initializing an object of template class triple type long with the name "var1" and var1(stuff) is a constructor call

  Triple<long> var1(11, 1500, 780000, string("var1"));         
  var1.print();
  cout<<"var1's third element: "<<var1.getThirdElem()<<endl;

  cout<<endl;
  Triple<char> var2('t', 'n', 'o', string("var2"));
  var2.print();
  cout<<"var2's first element: "<<var2.getFirstElem()<<endl;

  cout<<endl;
  Triple<double> var3(0.44, 1.567, -89.432523, string("var3"));
  var3.print();
  cout<<"var3's second element: "<<var3.getSecondElem()<<endl;

  cout<<endl;
  Triple<string> var4(string("go"), string("away"), string("corona"), string("var4"));   
  var4.print();
  
  //doing string("something") is just explicit and tries to make sure that the variable passed is a string and not a cstring or array of characters
  //same can be done for int(5) and double(5.05) and other basic data types because they are all essentially classes and these forms are constructors in the same way as you make your own classes and constructors


  cout<<endl;
  Triple<int> var5(-10, 20, 30);
  var5.print();

  return 0;
}

