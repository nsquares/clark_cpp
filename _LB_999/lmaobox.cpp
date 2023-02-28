#include <iostream>

using namespace std; // bad practice btw when doing school work

int main()
{
  int N = 255;
  int f1 = 500;
  int f2 = 1500;
  int f = 50000000;
  cout<<f<<endl;
  int a = 1;
  
  int bottom = (2*( (a*(f2-f1)) + (f1*N) ));

  int cnt = (f*N) / bottom;

  cout<<bottom<<endl;

  cout<<cnt<<endl;
  
  
  
  
  
  //std::cout

  //int x = 5, y = 2, w = 0;

 /*
 for(int i=0; i<25; i++){
   cout<<i<<endl;
 }
 */
  //cout<<x<<" "<<y<<" "<<w<<" ";
  return 0;
}