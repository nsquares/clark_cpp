//Nathan Nguyen
//Lab 9
//last modified: 3/25/21

#include <iostream>
using namespace std;

const int SIZE=5;

int main(){

  int array[SIZE]={10,12,15,19,6};
  int min = array[0];
  int max = array[0];
  int sum = 0;


  //finding minimum value and the max value in array at the same time
  //and adding all the array elements into one variable "sum"
  for (int i=0; i<SIZE; i++){

    if(array[i]<min){
      min=array[i];
    }

    if(array[i]>max){
      max=array[i];
    }

    sum+=array[i];

  }
  cout<<">>> Min value = "<<min<<endl;
  cout<<">>> Max value = "<<max<<endl;
  cout<<">>> Average = "<<(sum/SIZE)<<endl;


  return 0;
}
