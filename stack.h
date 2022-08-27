// stack.h
// array stack

#ifndef __STACK_H__
#define __STACK_H__

#define TRUE 1
#define FALSE 0

#define Len 100

typedef int Sdata;
typedef struct __stack
{
  Sdata stack_arr[Len];
  int top;
} Stack;

void stackInit(Stack* pstack);
int stackisEmpty(Stack* pstack);
void Push(Stack* pstack, Sdata data);
Sdata Pop(Stack* pstack);
Sdata Peek(Stack* pstack);

#endif
