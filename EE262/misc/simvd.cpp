#include "simvd.h"

//need to add a namespace and #ifndef //if not defined variable with no value to be an include guard, wait do I need this in the implementation/source file or just only in the header, I know for sure the header will need this no matter what for best practice

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
