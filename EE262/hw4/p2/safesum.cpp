//Nathan Nguyen
//HW 4 | p2
#include <iostream>
#include <climits>
#include <exception>
#include <stdexcept>
#include <string>
#include <sstream>

//todo: couldn't I just use using namespace std; ?
//yea, it is the same thing
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::ostringstream;

//precondition: n1 >= 0, n2 >= 0
//postcondition: return sum of n1 and n2 or throw an overflow error
int safeadd(int n1, int n2);

int main (void){
  cout<<"INT_MAX (on this machine): "<<INT_MAX<<endl;  //INT_MAX is defined in <climits>
  int bigNum1 = INT_MAX - 100;

  try{    
    cout<<"safeadd(7, 500): "<<safeadd(7,500)<<endl;

    cout<<"safeadd("<<bigNum1<<", 200): "<<std::flush;  
    //flush forces data in the buffer to be "flushed" to the external destination or be displayed on the screen
    
    cout<<safeadd(bigNum1, 200)<<endl;
  }
  catch(std::runtime_error exp){ //note: runtime_error is a superclass of overflow_error
    cerr<<endl<<"main: Caught exception at runtime: "<<exp.what()<<endl;
  }

  cout<<endl<<endl;
  cout<<"safeadd(300, 11): "<<safeadd(300,11)<<endl;

  ostringstream oss;       //ostringstream is a variable that stores a string stream that is made to be outputted
  oss<<"calling safeadd("<<bigNum1<<", 200): "<<std::flush;
  cout<<oss.str()<<std::flush;

  cout<<safeadd(bigNum1,200)<<endl;

  return 0;
}


int safeadd(int n1, int n2){   //could have casted variables to be type long and then compare naturally 
  if( n1 > (INT_MAX-n2) ){       
    //remember that this condition needs to be valid to be able to throw
    throw std::overflow_error("safeadd: overflow during integer addition.");  
    //also note that the string in the argument of the constructor will be stored in private data and accessed by the .what() member function 
    //(this is used earlier in this file)
  }

  return(n1+n2);
}