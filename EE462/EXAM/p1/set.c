#include<stdio.h>
#include<stdlib.h>
#include "set.h"
#include "set.h"


//local helper function
//@ postcondition: returns 1 if elem is in the intSet, returns 0 otherwise
static int contains(intSetPtr x, int element);


//@  precondition: maxSize > 0
intSetPtr initIntSet(int maxSize)
{
  intSetPtr iset = (intSetPtr) malloc(sizeof(intSet));
  iset->max_size = maxSize;
  iset->numElements = 0;
  return iset;
}


int addToSet(intSetPtr x, int num)
{  
  if (x->numElements == 0) {
    x->elems = (int*) malloc(x->max_size*sizeof(int));
  }
  
  if (x->numElements == x->max_size) {
    fprintf(stderr, "Unable to add %d to intSet\n", num);
    return 1;
  }

  if (contains(x, num) == 0) {
    x->elems[x->numElements] = num;
    x->numElements++;
  }

  return 0;
}


static int contains(intSetPtr x, int element)
{
  for (int i = 0; i < x->numElements; i++) {
    if (x->elems[i] == element)
      return 1;
  }

  return 0;
}


//print set comma-separated, enclosed in []
//note: alternatively, enclosed in {}
void print(intSetPtr x)
{
  printf("{");
  for (int i = 0; i < x->numElements; i++) {
    printf("%d", x->elems[i]);
    if (i < x->numElements-1)
      printf(", ");
  }
  printf("}\n");
}
