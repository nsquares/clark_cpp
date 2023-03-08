#ifndef SET_H
#define SET_H


typedef struct {
  int max_size;
  int numElements;
  int* elems;
} intSet;

typedef intSet* intSetPtr;


//initialie the intSet
//create a set of integers with a possible maximum size
//@  precondition: maxSize > 0
intSetPtr initIntSet(int maxSize);

//add an element to the intSet S
//@ postcondition: returns 0 if elem is successfully added, otherwise returns 1
int addToSet(intSetPtr S, int elem);


//print elements of the intSet S
void print(intSetPtr S);

#endif
