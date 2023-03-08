#include<stdio.h>
 
long factorial(int);
 
int main() {
    int n = 0;
    printf("enter a (smallish) number > 0: ");
    scanf("%d", &n);
    long val=factorial(n);

    printf("answer: %ld\n", val);

    return 0;
}
 
long factorial(int x) {
  long result = 1;
  
  while (x-- > 0) {
        result *= x;
  }

  return result;
}

