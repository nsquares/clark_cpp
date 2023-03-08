//Nathan Nguyen

// precondition : x >=2
// if x is prime , returns 1 , otherwise returns 0
int isPrime (int x) {
  if (x<2) {
    return -1; //precondition was not met
  }

  int i;
  for (i=2; i<x; i++) { //should not try 1 and the itself x value
    if((x % i) == 0){ //if something divides cleanly, then there is a factor other than 1 an\
d itself
  return 0;
    }
  }

  return 1;
}
