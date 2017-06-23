#include "linkedlist.h"
#include <stdio.h>

void listInit(LinkedList *list)
{
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;  // Len is how many item in the list
}

void listAdd(LinkedList *list, Item *item)
{
  if(list->len == 0)
  {
    list->head = item;
    list->tail = item;
  }
  else
  {
    list->tail = item;
    item->next = NULL;
  }
  list->len += 1;
}

void listRemove(LinkedList *list, Item *item)
{
  
}
