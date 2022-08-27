// gmain.c
// gcc gmain.c func_list.c func_stack.c func_graph2.c -o gmain2

#include "graph2.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
  Graph graph;
  graphInit(&graph, 5);

  addEdge(&graph, A, B);
  addEdge(&graph, A, C);
  addEdge(&graph, B, E);
  addEdge(&graph, C, B);
  addEdge(&graph, E, D);

  showGraph(&graph);

  printf("\n");

  showDFS(&graph, A);
  showDFS(&graph, C);

//  printf(">>>%p\n", (graph.vertex)+1);
/*
  printf("return memory before\n");
  for(int i=0; i<5; i++)
  {
    printf("vertex[A] arrow %d\n", (graph.vertex+i)->head->next->data);
    // same upper. 
//    printf("vertex[A] arrow %d\n", graph.vertex[i].head->next->data);
  }*/
//  showAdd(&graph);

  graphDestroy(&graph);
  
//  showAdd(&graph);

  return 0;
}
