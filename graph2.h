// graph2.h
// Depth First Search.

#ifndef __GRAPH_H__
#define __GRAPH_H__
#include "list.h"

enum {A, B, C, D, E, F, G, H, I};

typedef struct __graph
{
  int numV;
  int numE;
  List* vertex;
  int* visitInfo;
} Graph;

void graphInit(Graph* pg, int numV);
void graphDestroy(Graph* pg);
void addEdge(Graph* pg, int from, int to);
void showGraph(Graph* pg);
void showDFS(Graph* pg, int startV);
void showAdd(Graph* pg);

#endif
