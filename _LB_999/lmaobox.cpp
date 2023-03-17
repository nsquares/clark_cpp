#include <iostream>

using namespace std; 

int main()
{
  int N = 255;      //--N max counter value (8 bits)
  int f1 = 500;     //--f1 is lower frequency (Hz)
  int f2 = 1500;    //--f2 is higher freq (Hz)
  int f = 50000000; //--core clk 50MHz assumption
  cout<<f<<endl;
  int a = 1;        //--ADC's 8-bit data
  
  int bottom = ((a * (f2 - f1)) + (f1 * N));
  int cnt = ((f/2)/bottom)*N;

  cout<<bottom<<endl;
  cout<<cnt<<endl;
  
  return 0;
}


// using namespace std; bad practice btw when doing school work



//std::cout

  //int x = 5, y = 2, w = 0;

 /*
 for(int i=0; i<25; i++){
   cout<<i<<endl;
 }
 */
  //cout<<x<<" "<<y<<" "<<w<<" ";
