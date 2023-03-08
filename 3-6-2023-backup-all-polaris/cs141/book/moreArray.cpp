#include <iostream>
using namespace std;

int main(){


  double a[5]={1.1,4.4,3.3,5.5,6.6};
  for (int index=0;index<20;index++){

    if(a[index]>a[index+1]){
      cout<<"array elements "<<index<<" and "<<(index+1)<<" are out of order."<<endl;
      cout<<a[index+1]<<endl;
    }
}


  return 0;
}
