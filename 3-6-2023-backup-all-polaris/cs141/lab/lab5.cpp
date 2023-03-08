// Nathan Nguyen
// Lab 5 (ref parameters)
// CS141 
// 2/26/2021

#include <iostream>
using namespace std;

void timeInput(int &cHour, int &cMin, int &wHour, int &wMin);
//ask user to input current time in 24 hours and time to wait

void timeOutput(int hour, int min);
//print the time in 24 hours format it will be after waiting

void addTime(int &cHour, int &cMin, int wHour, int wMin);
//add wait time to current time


int main(){

  char userLoop;
  int currentHour, currentMin, waitHour, waitMin;

  do{

    timeInput(currentHour, currentMin, waitHour, waitMin);
    addTime(currentHour, currentMin, waitHour, waitMin);
    timeOutput(currentHour, currentMin);

    cout<<"Want to calculate another time (Y/N) ?\n";
    cin>>userLoop;

  }while((userLoop=='y')||(userLoop=='Y'));

  return 0;
}


void timeInput(int &cHour, int &cMin, int &wHour, int &wMin){

  cout<<"Current hour: \n";
  cin>>cHour;

  cout<<"Current minute: \n";
  cin>>cMin;


  cout<<"Hours to wait: \n";
  cin>>wHour;

  cout<<"Minutes to wait: \n";
  cin>>wMin;
}


void timeOutput(int hour, int min){

  cout<<"After waiting, the time should be: "<<hour<<":"<<min<<endl;
}

void addTime(int &cHour, int &cMin, int wHour, int wMin){
  cHour+=wHour;
  cMin+=wMin;

  if(cHour>23){
    cHour=cHour-24;
  }


  if(cMin>59){
    cHour++;
    cMin-=60;
  }
}
