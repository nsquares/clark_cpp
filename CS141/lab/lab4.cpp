
#include <iostream>
using namespace std;

double calc_MPG(double liters, double miles);

const double oneLiterToGallon = 0.264179;

int main (){
  char userLoop;

  do {

    double liters, miles;

    cout<<"Please enter the number of liters and the number of miles:\n";
    cin>>liters>>miles;

    cout<<"Miles per gallon: "<<calc_MPG(liters, miles)<<endl;

    cout<<"Again (Y/N)?\n";
    cin>>userLoop;

  }while((userLoop == 'Y')||(userLoop == 'y'));


  return 0;
}


double calc_MPG(double liters, double miles){
  double gallons;

  gallons=liters*oneLiterToGallon;

  return(miles/gallons);
}
