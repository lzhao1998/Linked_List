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

  struct Student ali =
  {
    "Ali",23,72.35,1.78   //name,age,weight,height
  };
  
  struct Student baba =
  {
    "Baba",22,67.32,1.75
  };
   
  Item itemAli = 
  {
    (Item *)-1,     //next
    (void *)&ali    //ali punya data
  };
  
  Item itemBaba =
  {
    (Item *)-1,     //next
    (void *)&baba   //baba punya data
  };
  
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
 
 void test_initialized_Ali_in_empty_linked_list(void)
{
  LinkedList list;
  printf("Address of Ali: %p\n", &itemAli);
    
  listInit(&list);
  listAdd(&list, &itemAli);
  
  TEST_ASSERT_EQUAL_PTR(&itemAli, list.head);
  TEST_ASSERT_EQUAL_PTR(&itemAli, list.tail);
  TEST_ASSERT_EQUAL(1, list.len);
  TEST_ASSERT_NULL(itemAli.next);
  TEST_ASSERT_EQUAL_PTR(&ali, itemAli.data);
}

/**
 *        Initial          After adding Ali              After adding Baba
 *
 *      tail----+            tail----+-------+            tail--------------+
 *      head----+            head----+       |            head----+         |
 *              |                    |       |                    |         |
 *            NULL                  next-----+                  next-------next--------+
 *                                  data--+  |                  data--+    data--+     |
 *                                        |  NULL                     |          |    NULL
 *                                       Ali                         Ali        Baba
 *
 *Given an empty linked list. Add Ali(student). Expect the linked list contains Ali.
 **/

void test_initialized_Ali_and_Baba(void)
{
  LinkedList list;

  printf("Address of Ali: %p\n", &itemAli);
  printf("Address of Baba: %p\n", &itemBaba);
    
  listInit(&list);
  listAdd(&list, &itemAli);
  listAdd(&list, &itemBaba);
  
  TEST_ASSERT_EQUAL_PTR(&itemAli, list.head);
  TEST_ASSERT_EQUAL_PTR(&itemBaba, list.tail);
  TEST_ASSERT_EQUAL(2, list.len);
  TEST_ASSERT_NULL(itemBaba.next);
  TEST_ASSERT_EQUAL_PTR(&baba, itemBaba.data);
}

