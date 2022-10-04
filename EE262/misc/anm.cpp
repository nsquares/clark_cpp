//understanding virtual functions and early/late binding
//late binding is also known as dynamic dispatch

#include <iostream>
#include <exception>
#include <stdexcept>

using std::endl;
using std::cout;

class Animal {
public:
  //IMPORTANT: eat must be virtual for dynamic dispatch (in function feed) to work
  virtual void eat() { std::cout << "I'm eating generic food."<<endl; }  
  
  //void eat() { std::cout << "I'm eating generic food."<<endl; }
};

class Cat : public Animal {
public:
  void eat() { std::cout << "I'm eating a rat."<<endl; }
};

class Dog : public Animal {
public:
  void eat() { std::cout << "I'm eating a cat."<<endl; }
};

void test1();
void test2();

//a function designed and written before the subclasses of Animal were designed/added
//feed();

//for dynamic dispatch, we need pointers or reference types, so this wont work
//A plain Animal is always an Animal; it can never refer to any of its subtypes
//(note: making xyz an Animal& will allow dynamic dispatch for test1)

void feed(Animal xyz) {
  xyz.eat();
}

//feed all Animals
//an Animal pointer allows dynamic dispatch
//its runtime type can be Animal or any of its subtypes
void feed(Animal* xyz) {
  xyz->eat();
}

//of course, can overload feed for each subtype
//but that means writing a feed function each time a subclass of Animal is created
// void feed(Cat *xyz) {
//   xyz->eat();
// }

int main(void) {
  cout<<"Test1: "<<endl;
  test1();
  cout<<endl<<endl;

  cout<<"Test2: "<<endl;
  test2();

 return 0;
}


void test1() {  
  Animal someone;
  Cat cat;
  Dog dog;

  someone.eat();
  cat.eat();
  dog.eat();

  cout<<endl<<"Using feed:"<<endl;
  feed(someone);
  feed(cat);
  feed(dog);    
}


void test2() {
  Animal* someone = new Animal;
  Cat* cat = new Cat;
  Dog* dog = new Dog;
  someone->eat(); 
  cat->eat();
  dog->eat();
    
  cout<<endl<<"Using feed:"<<endl;

  //virtual eat() in Animal needed for dynamic dispatch
  feed(someone);
  feed(cat);
  feed(dog); 
}