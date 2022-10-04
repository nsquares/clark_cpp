#include <iostream>
#include <assert.h>
#include <initializer_list>

using namespace std;




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




//also avoid insert member function because we are not using linker lists, just arrays and will need to move all element values to different memory locations, very expensive process
#if 0 //avoid in this case
int simvd::find(double element){ //need to check within approx if an element occurs more than once in the container
  for(int i=0; i<size; i++){
    if(data[i] == element){

    }
  }
}
#endif

//these needs to be a c++ ref return type here, teacher doesnt know a way to show why you have to do this but this is best practice for what we are trying to do here and prevent bugs
simvd& simvd::operator=(const simvd& orig){ //copy assignment, you dont use a friend function here because friends are functions with two agruments, like + or -, equal assignement operation will always have a receiver which takes the values of the right hand side so this should not be a friend function because there is only one argument and the left hand side is a receiver

  //overwrite the reciever object; free memory //small subtly memory leak
  delete[] data;


  size = orig.size;
  capacity = orig.capacity;
  
  data = new double[capacity];

  for(int i=0; i<orig.size; i++){ //intention is orig.size, just to really make sure
    data[i] = orig.data[i];
  }

  return *this; //deference
  
}

simvd::simvd(){
  size = 0;
  capacity = INITIAL_CAPACITY;
  data = new double[capacity];
}

simvd::simvd(int initialCap): capacity(initialCap), size(0), data(new double[initialCap]) { //new style but dont worry for the exam
  //empty

  //memory alloc
}

simvd::simvd(const simvd& orig){
  size = orig.size;
  capacity = orig.capacity;
  //data = orig.data; //dont do this, this is called shallow copy here, we want a deep copy, where pointers are not pointing to the same memory location

  data = new double[capacity]; //need to allocate new memory specifically for this object

  for(int i=0; i<orig.size; i++){ //intention is orig.size, just to really make sure
    data[i] = orig.data[i];
  }
}


simvd::simvd(const initializer_list<double>& lst){
  size = lst.size();
  capacity = size*2;
  data = new double[capacity]; //if this is not written, there was a problem with the decsontructor (that is auto called) trying to delete something that does not exist
  //GC grabage collector deals with all this pointer shit , but i aint a com sci major
  
  int num = lst.size();
  initializer_list<double>::iterator it;


  //for(double e: lst){ //modern style that works as well
    //cout<<e<<endl;
  //}

#if 1
  for(auto it = lst.begin(); it != lst.end(); ++it){
    cout<<*it;
  }
#endif

}



simvd::~simvd(){ //when the object goes out of scope, the deconstructor is automatically called, programmer does not need to call this
 cout<<"im here"<<endl; 
  delete[] data; //we need to handle the heap but we dont need to handle the ints because int class will handle that
}



int simvd::get_size() const{
  return size;
}

int simvd::get_capacity() const{
  return capacity;
}

void simvd::append(double e){

  assert(size <= capacity);

  if(size == capacity){

    int newCap = capacity * 2;
    
    double* data2 = new double[newCap]; //make a temp and reassign

    for(int i=0; i<size; i++){
      data2[i] = data[i];
    }
    capacity = newCap;
    delete[] data; //delete/free/return old memory , memory leak if you dont delete, or run out of memory  
    data = data2;    
  }
  

  data[size++] = e; //because it will increment after it is used, neckbeard coding
//size++; //is different from ++size, this would increment before size is used

}

void simvd::print() const{

  for(int i=0; i<size; i++){
    cout<<data[i]<<" ";
  }
  cout<<endl;
}


double simvd::at(int loc) const{ //can return ints as it automatically promotes int to double
  
//  assert(loc > -1 && loc < size); //could do this, java style which is just exit the whole program
  
  if(loc < 0 || loc > size ){
    
    cerr<<"[simvd::at] array index out of bounds: value returned is not legal"<<endl;
    return -1;
    //in java, you just exit();
    
    //exit(1); //also valid

  } else{
    return data[loc]; 
  }
}

//pos has to be less than size, will not handle reallocating memory like the append func, 
void simvd::set(double elem, int pos){ //not const because will change values
  assert(pos > -1 && pos < size);

  data[pos] = elem;
}


int main(void){

  simvd x1;

  cout<<"cap: "<<x1.get_capacity()<<endl;
  cout<<x1.get_size()<<endl;
  
  x1.append(87);
  cout<<x1.get_size()<<endl;

  for(int i=0; i<12; i++){
    x1.append(i*3);
  }

  cout<<"cap: "<<x1.get_capacity()<<endl;
  cout<<"size: "<<x1.get_size()<<endl;
  cout<<"x1: ";
  x1.print();

  cout<<x1.at(1)<<endl;

  x1.set(56.5, 1);
  x1.print();

  simvd x2(8);
  cout<<x2.get_capacity()<<endl;

  simvd x3(x1); //if this is not defined, this can still work by an implicit constructor, but might not be the correct way
//implicit constructor (this is an auto generated constructer at complie time)
//default (zero arguments)

  x3.print();

  simvd x4={1.4, 5.2, 6.2};
  x4.print();



  
  simvd x5;
  x5 = x3; //this is another example of an implicit function that is generated by compiler, (implict copy assignment was made)
  //pointers are now pointing at each other through implicit function and one deconstructor will delete data of two objects at the same time and this is dangerous, runtime error should exist

  //need to overload user defined the = operator 

  x5 = x3 = x1; //this is valid if everything were ints  (go from right to left, to add)
  //we have a problem because we use a void return type, do we need to overload again but return simvd?


  x3.print();
  x5.print();
  


  return 0;
}