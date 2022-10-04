// Nathan Nguyen
//from hw 3
#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;

// func def
bool isPalindrome(const char*);


int main(int argc, char *argv[]){ //so the first one [0] is the directory path of the exe, the second one [1] is what the user inputs if $ ./pali test

  //need to check number of command line arguments
  
  assert(argc == 1); //this is supposed to only be used in debugging according to documentation online
  //btw, argc is always +1 of the index numbers of elements in argv[], like any other array that you program
  
  #if 0
  if(argc != 2){
    cout<<"usage: palindrome string_to_check"<<endl;
    return -1;
  }
  #endif

  cerr<<"what"<<argv[0]<<endl; //the compiler on my PC will have the exe crash when it tries to access an out of bound array element while Polaris compiler would have just read the memory location and give it to me anyways with no error, either way my PC also does not show an error but just stops the program right there


  if(isPalindrome(argv[0])){
    cout<<"yes"<<endl;
  }
  else{
    cout<<"no"<<endl;
  }

  return 0;
}


bool isPalindrome(const char*){

  

  return false;
}