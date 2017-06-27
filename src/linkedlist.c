#include "linkedlist.h"
#include "student.h"
#include <stdio.h>
#include <string.h>

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

void listRemoveAli(LinkedList *list, char* name)
{
  Student *student;
  student = (Student*)(list->head->data);
  //let student contain the data
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

void listRemoveHead(LinkedList *list)
{
	list->head = list->head->next;
    list->len--;
}

void listRemoveByName(LinkedList *list, char* name)
{
  Item *current;
  Item *pervious;
  pervious = NULL;
  current = list->head;
  // compare the remove student name is correct or not. correct = 0.
  
  if(current == NULL)
	  // if no data matched in the list,return NULL
	  return NULL;
  else
  {
	// keep find the name from the list until what we want
	while(strcmp(((Student*)current->data)->name, name)!=0 )
	{
		pervious = current;
		current = current->next;
	}
	
	//remove 1st item from the list(head)
	if(current == list->head)
	{
		if(list->head == list->tail)
		{
			listInit(list); //if there are only 1 data.
		}
		else
		{
			listRemoveHead(list);
		}
	}
	
	//remove last item from the list(tail)
	else if(current == list->tail)
	{
		list->tail = pervious;
		list->tail->next = NULL;
		list->len --;
	}
	//remove middle item from the list
	else
	{
		pervious->next = current->next;
		list->len--;
	}
  }
  

  
}
