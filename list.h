// list.h

#ifndef __LIST_H__
#define __LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Ldata;
typedef struct __node
{
  Ldata data;
  struct __node* next;
} Node;

typedef int (*func)(Ldata d1, Ldata d2);
typedef struct __list
{
  Node* head;
  Node* cur;
  Node* bef;
  int num;
  func comp;
} List;

void listInit(List* plist);
void setRule(List* plist, func comp_rule);
void listInsert(List* plist, Ldata data);
int firstSearch(List* plist, Ldata* rval);
int nextSearch(List* plist, Ldata* rval);
Ldata listDelete(List* plist);
Ldata getNum(List* plist);

#endif
