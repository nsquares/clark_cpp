#ifndef TRIPLE_H     //this is an include guard
#define TRIPLE_H

#include<iostream>
#include<string>

using std::ostream;      
using std::string;


namespace simSequence {         //simple sequence
  template <typename T>         //template class
  class Triple {

  public:
    Triple(T first, T second, T third);              //two constructors
    Triple(T first, T second, T third, string name);

    T getFirstElem();         // three accessors
    T getSecondElem();
    T getThirdElem();

    void print();        //public member function

  private:  
  //remember that private data variables are not considered part of the "interface" of the class 
  //but have to be in the header file that contains the interface of the class 
    T first;
    T second;
    T third;
    string name;    //this is needed for the public member function print()
  };
}

#endif
