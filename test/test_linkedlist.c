#include "unity.h"
#include "linkedlist.h"
#include "student.h"

void setUp(void)
{
}

void tearDown(void)
{
}


void test_listInit_ensure_initialized_to_NULL_and_0(void)
{
  LinkedList list =
  {
    (Item *)-1,
    (Item *)-1,
    10
  };
  listInit(&list);
  
  TEST_ASSERT_NULL(list.head);
  TEST_ASSERT_NULL(list.tail);
  TEST_ASSERT_EQUAL(0,list.len);
}

/**
 *        Initial           After adding Ali
 *
 *      tail----+             tail----+
 *      head----+             head----+
 *              |                     |
 *            NULL                   next-----+
 *                                   data--+  |
 *                                         |  NULL
 *                                        ALI
 *
 *Given an empty linked list. Add Ali(student). Expect the linked list contains Ali.
 **/
void test_listAdd_given_an_empty_linked_list_then_add_ali_expect_1_item_in_list(void)
{
  LinkedList list;
  struct Student ali =
  {
    "Ali",23,72.35,1.78   //name,age,weight,height
  };
  
  Item item = 
  {
    (Item *)-1,   //next
    (void *)&ali //data
  };
  
  printf("Address of item: %p\n", &item);
  
  listInit(&list);
  listAdd(&list, &item);
  
  TEST_ASSERT_EQUAL_PTR(&item, list.head);
  TEST_ASSERT_EQUAL_PTR(&item, list.tail);
  TEST_ASSERT_EQUAL(1, list.len);
  TEST_ASSERT_NULL(item.next);
  TEST_ASSERT_EQUAL_PTR(&ali, item.data);
}

