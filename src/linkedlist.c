#include "linkedlist.h"
#include "student.h"
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
	item->next = NULL;
  }
  else
  {
    list->tail->next = item;
    item->next = NULL;
	list->tail = item;
  }
  list->len += 1;
}

void listRemove(LinkedList *list, char* name)
{
  Student *student;
  student = (Student*)(list->head->data);
  //let student contain list.head data which is Ali.
  int temp = strcmp(student->name,name);
  // compare the remove student name is correct or not.
  if(temp == 0)
  {
	printf("remove ali\n"); 
	//printf use to test the code is working right or not when doing removing.
	list->head = list->head->next;
	list->len--;
  }
  else
  {
	  printf("no remove ali");
	  //printf use to test the code is working right or not.
  }

}
