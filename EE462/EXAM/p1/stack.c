#include<stdlib.h>
#include<stdio.h>
#include "stack.h"
#include "set.h"


istStackPtr initStack(int maxStackSize)
{
  istStackPtr stk = (istStackPtr) malloc(sizeof(istStack));
  stk->max_stack_size = maxStackSize;
  stk->topOfStack = -1;

  return stk;
}



void push(istStackPtr x, intSetPtr s)
{
  if (x->topOfStack == -1) {
    x->thestack = (intSetPtr*) malloc(x->max_stack_size*sizeof(intSetPtr));
  }
  
  if (x->topOfStack < x->max_stack_size - 1) {
    x->topOfStack++;
    x->thestack[x->topOfStack] = s;
  } else {
    fprintf(stderr, "push: stack is full\n");
    exit(1);
  }
}


int isEmpty(istStackPtr x)
{
  return (x->topOfStack < 0);
}

intSetPtr pop(istStackPtr x)
{
  if (x->topOfStack >= 0) {
    intSetPtr val = x->thestack[x->topOfStack];
    x->topOfStack--;
    return val;
  }

  fprintf(stderr, "pop: stack empty\n");
  exit(1);
}



void printTopOfStack(istStackPtr x)
{
  if (!isEmpty(x)) {
    //printf("\t"); 
    print(x->thestack[x->topOfStack]);
  } else {
    fprintf(stderr, "push: stack is full\n");
  }
}
