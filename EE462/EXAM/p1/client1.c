//Nathan Nguyen  

//44 lines this c file, 22 lines makefile, 31 lines c file

//#include ""
#include "stack.h"
#include <stdio.h>


int main(void){
  
  printf("\n");
  printf("initializing intSet s1\n");
  
  intSetPtr s1 = initIntSet(3);

  addToSet(s1, -31);
  addToSet(s1, -13);
  addToSet(s1, 1);

  printf("contents of s1: ");
  print(s1);
  //printf("\n");

  addToSet(s1, 119);
  printf("\n");
  printf("\n");




  printf("initializing intSet s2\n");
  intSetPtr s2 = initIntSet(5);  

  addToSet(s2, 10);
  addToSet(s2, 20);
  addToSet(s2, 30);
  addToSet(s2, 50);

  printf("contents of s2: ");
  print(s2);
  printf("\n");
  printf("\n");




  printf("initializing istStack xst\n");
  istStackPtr xst = initStack(3);
  
  push(xst, s1);
  push(xst, s2);

  
  printf("ToS of xst: ");
  printTopOfStack(xst);
  
  intSetPtr s22 = pop(xst);

  printf("ToS of xst: ");
  printTopOfStack(xst);
  
  return 0;

}