//Nathan Nguyen
// lab 12

#include <iostream>
using namespace std;


class Counter{ //class for a type called counter
private:

  int num; //an object of this type is used to count things


public:
  //constructor
  Counter();
  Counter(int);
  
  //member functions
  int increment();
  int decrement();
  void print();

};

Counter::Counter(){
  num=0;
}
Counter::Counter(int a){
  num=a;
}


int Counter::increment(){
  return num++;
}

int Counter::decrement(){

  if(num > 0){  //do not let the value go below zero
    return num--;
  }

  return num;
}

void Counter::print(){
  cout<<num;
}



int main(){

  Counter c1;
  Counter c2(10);

  cout<<"C1 starts at ";
  c1.print();
  cout<<endl;

  c1.increment();
  c1.increment();

  cout<<"C1 now at ";
  c1.print();
  cout<<endl;

  c1 = c2;

  c1.decrement();

  cout<<"C1 now at ";
  c1.print();
  cout<<endl;


  return 0;
}
