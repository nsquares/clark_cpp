#ifndef STACK_H
#define STACK_H

#include "set.h"

typedef struct {
  int max_stack_size;
  int topOfStack;
  intSetPtr* thestack;
} istStack;

typedef istStack* istStackPtr;


// initialize/create the stack
istStackPtr initStack(int maxStackSize);

// add/insert element E to (the top of) a stack
void push(istStackPtr X, intSetPtr E);

//remove elements from (the top of) a stack
intSetPtr pop(istStackPtr X);


// view the element at the top of a stack X
void printTopOfStack(istStackPtr X);

#endif
