// func_graph2.c

#include "graph2.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int rule(Ldata val1, Ldata val2)
{
  if(val1 > val2)
    return 1;
  else
    return 0;
}

void graphInit(Graph* pg, int numV)
{
  pg->numV = numV;
  pg->numE = 0;
  pg->vertex = (List*)malloc(sizeof(List)*numV);
  
  for(int i=0; i<numV; i++)
  {
    listInit((pg->vertex)+i);
    setRule(&(pg->vertex[i]), rule);
  }
  pg->visitInfo = (int*)malloc(sizeof(int)*numV);
  memset(pg->visitInfo, 0, sizeof(int)*numV);
}

// all node free.
void graphDestroy(Graph* pg)
{
  List* temp[5];
  Node* nemp[5];

  for(int i=0; i<5; i++)
  {
    temp[i] = &(pg->vertex[i]);
    nemp[i] = ((pg->vertex)+i)->head->next; 
  }
   
  if(pg->vertex != NULL)
  {
    Ldata rval;
    
    // free all aloccated nodes.
    for(int i=0; i<pg->numV; i++)
    {
      if(firstSearch(&(pg->vertex[i]), &rval))
      {
        rval = listDelete((pg->vertex)+i);
        printf("vertex[%c]'s deleted node : %c\n", i+65, rval+65);
        while(nextSearch((pg->vertex)+i, &rval))
        {
          rval = listDelete((pg->vertex)+i);
          printf("vertex[%c]'s deleted node : %c\n", i+65, rval+65);
        }
      }
    }
    // free graph allocated lists.
    free(pg->vertex);
/*  
  // check malloc space.
  for(int i=0; i<5; i++)
  {
  //  printf("%d\n", temp[i]->head->next->data);
    printf("freed graph lists : bellow >>\n");
    printf("%d\n", nemp[i]->data);
  }
  printf("%p\n", pg->vertex[1].head);
  printf("%p\n", temp[1]->head);
*/ 
  }
}

void addEdge(Graph* pg, int from, int to)
{
  if(from >= pg->numV && to >= pg->numV)
  {
    printf("overwrite vertex error\n");
    return;
  }
  else
  {
    //undirected graph.
    listInsert(&(pg->vertex[from]), to);
    listInsert((pg->vertex)+to, from);
    (pg->numE)++;
  }
}

void showGraph(Graph* pg)
{
  printf(">>>>>>>> show Graph <<<<<<<<<\n");
  Ldata rval;

  for(int i=0; i<pg->numV; i++)
  {
    if(firstSearch((pg->vertex)+i, &rval))
    {
      printf("%c connect : %c", i+65, rval+65);
      while(nextSearch((pg->vertex)+i, &rval))
      {
        printf(", %c", rval+65);
      }
    }
    printf("\n");
  }
}

//help func for DFS.
// check visit history in array.

int checkVisit(Graph* pg, int visitV)
{
  if(pg->visitInfo[visitV] == 0)
  {
    printf("%c is visited\n", visitV+65);
    pg->visitInfo[visitV] = 1;
    return TRUE;
  }
  else
    return FALSE;
}

void showDFS(Graph* pg, int startV)
{
  Stack stack;
  int visitV = startV;
  int nextV;
  stackInit(&stack);

  printf(">>>>>>> show DFS route <<<<<<\n");
  printf("Start Vertex : %c\n", startV+65);
  checkVisit(pg, visitV);

  while(firstSearch((pg->vertex)+visitV, &nextV))
  {
    int flag = FALSE;
    if(checkVisit(pg, nextV))
    {
      Push(&stack, visitV);
      visitV = nextV;
      flag = TRUE;
    }
    else
    {
      while(nextSearch((pg->vertex)+visitV, &nextV))
      {
        if(checkVisit(pg, nextV))
        {
          Push(&stack, visitV);
          visitV = nextV;
          flag = TRUE;
          break;
        }
      }
    }
    if(flag == FALSE)
    {
      if(stackisEmpty(&stack))
        break;  
      else
        visitV = Pop(&stack);  
    }
  }
  printf("\n");
  memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}

void showAdd(Graph* pg)
{
  List* temp[5];

  printf(">>>> Address <<<<\n");
  for(int i=0; i<pg->numV; i++)
  {
    temp[i] = &(pg->vertex[i]);
    printf("%p\n", &(pg->vertex[i]));
    printf("%p\n", temp[i]);
    //printf("%d\n", pg->vertex->head->next->data);
  }
}





























