// func_list.c

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void listInit(List* plist)
{
  plist->head = (Node*)malloc(sizeof(Node));
  plist->head->next = NULL;
  plist->bef = NULL;
  plist->cur = NULL;
  plist->num = 0;
  plist->comp = NULL;
}

void setRule(List* plist, func comp_rule)
{
  plist->comp = comp_rule;
}

// Insert help func.

void headInsert(List* plist, Ldata data)
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  
  newNode->next = plist->head->next;
  plist->head->next = newNode;
  (plist->num)++;
}

void ruleInsert(List* plist, Ldata data)
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  Node* pred = plist->head;

  while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
  {
    pred = pred->next;
  }

  newNode->next= pred->next;
  pred->next = newNode;
  (plist->num)++;
}

void listInsert(List* plist, Ldata data)
{
  if(plist->comp == NULL)
    headInsert(plist, data);
  else
    ruleInsert(plist, data);
}

int firstSearch(List* plist, Ldata* rval)
{
  if(plist->head->next == NULL)
  {
    printf("There's no Node\n");
    return FALSE;
  }
  else
  {
    plist->bef = plist->head;
    plist->cur = plist->head->next;
    *rval = plist->cur->data;
    return TRUE;
  }
}

int nextSearch(List* plist, Ldata* rval)
{
  if(plist->cur->next == NULL)
  {
//    printf("   >>EOD<<\n");
    return FALSE;
  }
  else
  {
    plist->bef = plist->cur;
    plist->cur = plist->cur->next;
    *rval = plist->cur->data;
    return TRUE;
  }
}

Ldata listDelete(List* plist)
{
  Node* temp = plist->cur;
  Ldata temp_data = plist->cur->data;
  
  plist->bef->next = plist->cur->next;
  plist->cur = plist->bef;
  free(temp);
  (plist->num)--;
  return temp_data;
}

Ldata getNum(List* plist)
{
  return plist->num;
}
