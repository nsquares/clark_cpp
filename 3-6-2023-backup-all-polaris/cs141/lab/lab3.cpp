// Nathan Nguyen
// lab3.cpp (finds temperature that is the same in both Celsius and Fahrenheit)
// CS 141
// 2/5/2021

#include <iostream>
using namespace std;

int main(){

  int celsius, fahrenheit;

  cout<<"Set the initial value of Celsius: ";
  cin>>celsius;

  do {
    fahrenheit=((9*celsius)/5)+32;

    if (celsius==fahrenheit){
      cout<<"When Celsius = "<<celsius<<" fahrenheit will equal "<<fahrenheit<<" which is the same."<<endl;
      break;
    }
    celsius--; //I want to decrement after the check because what if the user inputted -40?
    //thus, there will be an if statement above so check can be done before input celsius is changed.

  } while(celsius!=fahrenheit);
    
  return 0;
    

  /* 
    Question 1:
    The condition that will end the loop is when the value or int variable celsius 
    is equal to the value or int variable of fahrenheit. 


    Question 2:
    I think I should check that condition at the end of the loop because if I 
    check it in the beginning, then it will be comparing variables where fahrenheit is null or has no value yet.
    This is because I do the calculation in the loop so I need to at least run through the calculation once.

    Question 3:
    I think the do while loop is the best because it performs the check after the first calculation so that fahrenheit
    will have a value. This is better over a for loop because I do not know how many times I will need to loop
    as the user could input any value away from -40 and I could not know that the answer was -40 at the beginning.
    Therefore, the number of times I have to loop is unknown.

  */
}
