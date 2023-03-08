#include <iostream>
using namespace std;

int main(){

  double a[3]={1.1, 2.2, 3.3};
  cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
  a[1]=a[2];  //both should be 3.3?
  cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;

  return 0;
}
