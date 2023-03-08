//Nathan Nguyen  

//44 lines this c file, 22 lines makefile, 31 lines c file

#include "rndf.h"

#include <stdio.h>


int main(void){

  initializeRand(); //init random number generator

  int Ni = 300;
  int Nf = 7500;

  int i;
  int sum1 = 0;
  for(i=0; i<Ni; i++){

    sum1 = sum1 + (getIntRandom(31));  //range should be 0 to 30
  }

  printf("getIntRand sum: %d", sum1);


  int j;
  int sum2 = 0;
  for(j=0; j<Nf; j++){

    sum2 = sum2 + (getFloatRandom()); 
  }





  printf("getFloatRand sum: %.2f", sum2);

  return 0;
}