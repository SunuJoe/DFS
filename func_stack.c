// func_stack.c

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stackInit(Stack* pstack)
{
  pstack->top = -1;
}

int stackisEmpty(Stack* pstack)
{
  if(pstack->top == -1)
  {
  //  printf("Stack is empty\n");
    return TRUE;
  }
  else
    return FALSE;
}

void Push(Stack* pstack, Sdata data)
{
  if(pstack->top == Len-1)
  {
    printf("Stack is full\n");
    return;
  }
  else
  {
    (pstack->top)++;
    pstack->stack_arr[pstack->top] = data;
  }
}

Sdata Pop(Stack* pstack)
{
  if(pstack->top == -1)
  {
    printf("stack is empty\n");
    exit(-1);
  }
  else
  {
    Sdata temp = pstack->stack_arr[pstack->top];
    (pstack->top)--;
    return temp;
  }
}

Sdata Peek(Stack* pstack)
{
  return pstack->stack_arr[pstack->top];
}
