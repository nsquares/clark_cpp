#include <iostream>
#include <cassert>
#include  <algorithm>

using std::endl;
using std::cout;
using std::cerr;
using std::ostream;
using std::initializer_list;
using std::copy;

class simvd { //simple vector only for doubles
public:
  friend ostream& operator<<(ostream& os, const simvd& x);

  simvd() {
    capacity = INIT_CAPACITY; //initial capacity
    elems = new double[INIT_CAPACITY];
    curr_size = 0; //no elements yet
  }

  //one argument constructor
  //modern C++ initialization
  simvd(int ic)
    :capacity{ic}, elems{new double[ic]}, curr_size{0} {
      //capacity = ic
      //elems = new double[ic];
      //curr_size = 0;
  }

  //copy constructor
  simvd(const simvd& orig) {
    capacity = orig.capacity;

    //elems = orig.elems; //BAD shallow copy
    
    elems = new double[capacity]; //deep copy

    //copy over the data
    for (int i = 0; i < orig.curr_size; i++) {
      elems[i] = orig.elems[i];
    }

    curr_size = orig.curr_size;
    //this->curr_size = orig.curr_size;
    //(*this).curr_size = orig.curr_size;
  }

  simvd(const initializer_list<double>& lst) {
    curr_size = lst.size();
    capacity = curr_size + INCR_CAPACITY;

    elems = new double[capacity];
    initializer_list<double>::iterator it;
    int i = 0;
    for (it = lst.begin(); it != lst.end(); it++) {
      elems[i++] = *it;
    }    
  }
  
  ~simvd() {
    //cout<<"deleting elems ..."<<endl;
    delete[] elems;
  }

  int get_capacity() const {
    //capacity = 1000;
    return capacity;
  }

  int get_size() const {
    return curr_size;
  }

  void set(double val, int loc) {
    //assert(loc >= 0 && loc < curr_size);
    if (!(loc >= 0 && loc < curr_size)) {
      cerr<<"simvd.set: illegal location"<<endl;
      return;
    }      
    elems[loc] = val;
  }

  double at(int loc) const {
    assert(loc >= 0 && loc < curr_size);

    // if (loc >= curr_size) {
    //   cerr<<"simvd: container value at "<<loc<<
    // 	"does not exist."<<endl;
    //   //exit(1);
    //   return 0.0;
    // }
    
    return elems[loc];
  }

  void append(double e) {
    if (curr_size == capacity) {
      capacity += INCR_CAPACITY;
      double* sec_elems = new double[capacity];

      for (int i = 0; i < curr_size; i++) {
	      sec_elems[i] = elems[i];
      }
      sec_elems[curr_size++] = e;
      delete[] elems;
      elems = sec_elems;
    } else {
      elems[curr_size++] = e;
    }
  }

  //copy assignment
  //overloaded function
  simvd&  operator=(const simvd& original) {
    this->curr_size = original.curr_size;
    this->capacity = original.capacity;

    this->elems = new double[capacity];

    //TODO: can use copy from algorithms
    //copy(original.elems, (original.elems)+original.curr_size-1, elems);

    //TODO: can print to check correct copying
    for (int i = 0; i < original.curr_size; i++)
      this->elems[i] = original.elems[i];

    return *this;
  }

  //overloaded array access operator
  double&  operator[] (int ind) {
    return this->elems[ind];
  }


void print() const {
    cout<<"[";
    for (int i = 0; i < curr_size; i++) {
      cout<<elems[i];
      if (i < curr_size-1)
	cout<<", ";
    }
    cout<<"]"<<endl;
}


private:
  //data (each object has a copy)
  double* elems;
  int curr_size;
  int capacity;

  //static fields (shared by all objects)
  unsigned const static int INIT_CAPACITY = 5; //initial capacity
  unsigned const static int INCR_CAPACITY = 10; //capacity increase quantity
};  


ostream& operator<<(ostream& os, const simvd& x) {
  os<<"[";
  for (int i = 0; i < x.get_size(); i++) {
    os<<x.at(i);

    if (i != x.get_size()-1)
      os<<", ";
  }
  os<<"]";
  
  return os;
}


int main() {
  {
    simvd x0(2);
  }
  simvd x1;

  x1.append(3.4);
  x1.append(-9.0);
  x1.append(10.2);
  x1.append(33.45);
  x1.append(92.21);
  
  x1.append(3.4);  

  cout<<"x1's size: "<<x1.get_size()<<endl;
  cout<<"x1's capacity: "<<x1.get_capacity()<<endl;
  cout<<"x1.at(3): "<<x1.at(3)<<endl;
  //cout<<"x1.at(100): "<<x1.at(100)<<endl;

  x1.set(9.2, 100);
  x1.print();

  cout<<endl;
  simvd x2(8);
  cout<<"x2's size: "<<x2.get_size()<<endl;
  cout<<"x2's capacity: "<<x2.get_capacity()<<endl;

  simvd x3(x1);
  cout<<"x3: ";
  x3.print();

  x3.set(-5.5, 2);
  cout<<"x3's size: "<<x3.get_size()<<endl;
  cout<<"x3's capacity: "<<x3.get_capacity()<<endl;
  cout<<"x3: "; x3.print();
  cout<<"x1: "; x1.print();

  simvd x4 = {1.4, -100.2, 54};
  cout<<"x4: "; x4.print();

  cout<<endl<<endl;
  simvd x5;
  x5 = x3;
  cout<<"x3: "; x3.print();
  cout<<"x5: "; x5.print();

  cout<<"[[set x3[0] to -11.5]]"<<endl;
  x3.set(-11.50, 0);
  cout<<"x3: "; x3.print();
  cout<<"x5: "; x5.print();    

  cout<<endl<<endl;
  cout<<"Test = op: "<<endl;
  cout<<"x1: "; x1.print();
  cout<<"x2: "; x2.print();
  cout<<"x5: "; x5.print();
    
  cout<<"[[x5 = x2 = x1]]"<<endl;
  x5 = x2 = x1; 
  cout<<"x1: "; x1.print();
  cout<<"x2: "; x2.print();
  cout<<"x5: "; x5.print();    

  //printing with overloaded <<
  cout<<endl;
  cout<<"x1: "<<x1<<endl;

  //array access operator
  cout<<x5[0]<<endl;
  x5[0] = 1001;
 cout<<x5[0]<<endl;
   
  return 0;
}