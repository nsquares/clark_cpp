//Nathan Nguyen

#include <stdio.h>

// precondition : num >= 1
// prints factors of num
void printFactors (int num) {
  if (num<1) {  
    printf("precondition was not met, all bets are off, caller's fault");
    return; //precondition was not met, all bets are off, caller's fault
  }
  
  int i;
  for (i=1; i<=num; i++) {
    if ((num % i) == 0){ //factors should divide cleanly
      printf("%d ", i);
    }
  }
}




