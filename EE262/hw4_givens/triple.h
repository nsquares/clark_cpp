#ifndef TRIPLE_H
#define TRIPLE_H

#include<iostream>
#include<string>

using std::ostream;
using std::string;


namespace simSequence {
  template <typename T>
  class Triple {

  public:
    Triple(T first, T second, T third);
    Triple(T first, T second, T third, string name);

    T getFirstElem();
    T getSecondElem();
    T getThirdElem();

    void print();

  private:
    T first;
    T second;
    T third;
    string name;
  };
}

#endif
