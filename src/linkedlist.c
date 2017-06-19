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
  list->head = item;
  list->tail = item;
  list->len += 1;
  item->next = NULL;
}

