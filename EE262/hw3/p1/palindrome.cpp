// Nathan Nguyen
#include <iostream>
#include <cstring>
using namespace std;

// check cstring if it is a palindrome or not
bool isPalindrome(const char*);


int main(int argc, char *argv[]){  

  //need to check number of command line arguments    
  if(argc != 2){
    cerr<<"usage: palindrome string_to_check"<<endl;
    return -1;
  }


  if(isPalindrome(argv[1])){ // [0] is the directory path of exe
    cout<<"yes"<<endl;
  }
  else{
    cout<<"no"<<endl;
  }

  return 0;
}


bool isPalindrome(const char* testWord){
  int testLen = strlen(testWord); //"includes \0 if you consider the first letter to be 0"
  
  for(int i=0; i<testLen; i++){
    if(testWord[i] != testWord[(testLen-1)-i]){
      return false;
    }
  }

  return true;
}