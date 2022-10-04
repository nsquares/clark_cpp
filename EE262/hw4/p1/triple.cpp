#include"triple.h"

namespace simSequence {

  template <typename T>  
  Triple<T>::Triple(T first, T second, T third)
    :first(first), second(second), third(third), name("unnamed") 
    //different style for assigning values to private variables
  {
    //another style is:
    //this->first = first;    //"this" keyword is a pointer to the current object 
                              //so the RHS first is from the argument
    //(*this).first  //desugar of ->
  }
  
  template <typename T>  
  Triple<T>::Triple(T first, T second, T third, string name)
    :first(first), second(second), third(third), name(name)
  {}

  template <typename T>
  T Triple<T>::getFirstElem(){
    return first;
  }

  template <typename T>
  T Triple<T>::getSecondElem(){
    return second;
  }

  template <typename T>
  T Triple<T>::getThirdElem(){
    return third;
  }

  template <typename T>
  void Triple<T>::print(){
    std::cout<<name<<": ("<<first<<", "<<second<<", "<<third<<")"<<std::endl;     
  }

  //explicit instantiation that are specific to the driver file -> client2.cpp
  template class Triple<long>;
  template class Triple<int>;
  template class Triple<char>;
  template class Triple<double>;
  template class Triple<string>;
}




