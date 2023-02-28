//Nathan Nguyen

#include <stdio.h>

int isPrime (int x);
int main(void){


  int a = isPrime(2);
  printf("AAAYYYYYOOOOOOOOOOO\n");
  printf("%d", (a));
  
  return 0;
}



// precondition : x >=2
// if x is prime , returns 1 , otherwise returns 0
int isPrime (int x) {
  if (x<2) {
    return -1; //precondition was not met
  }

  for (int i=2; i<x; i++) {
    if((x % i) == 0){ //if something divides cleanly, then there is a factor other than 1 and itself
      return 0;
    }
  }

  return 1;
}
