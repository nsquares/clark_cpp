#include <iostream>
#include <assert.h>
#include <initializer_list>

using namespace std;

//need to add a namespace and #ifndef //if not defined variable with no value to be an include guard


//link lists help ppl change data anyway in an "array" without moving all the data elements to the next array slot
//data is not continous, each element has a pointer address to the next element (so elements are called nodes instead?), so it is a less expensive process to add data (insert) anyway in the "list"
//the process of inserting will just be changing the pointers of each element instead of moving everything to a different address location
//link lists have data placed at addresses that are not contiunous like an array

class simvd{

public: //definiton of public member functions are not part of the interface of the object, nobody should rely on it
  simvd();
  simvd(int initialCap);
  simvd(const simvd& orig); //you have to pass by const reference
  ~simvd();
  simvd(const initializer_list<double>&);

  simvd& operator=(const simvd& orig);

  int find(double element);
  int get_size() const;
  int get_capacity() const;
  void append(double);
  void print() const;

  double at(int loc) const;
  void set(double elem, int pos); //not const because will change values


//todo: make a get accessor member func and check size before get is done

private:
  int size;
  int capacity;
  double* data; //dynamic array

  const static int INITIAL_CAPACITY = 5; //static because this should only be declared once and all objects can share it 
  //shared among all objects

};