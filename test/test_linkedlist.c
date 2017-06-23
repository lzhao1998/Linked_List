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
   
   struct Student abu = 
   {
     "Abu",24,80.75,1.77
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
  
  Item itemAbu =
  {
    (Item *)-1,     //next
    (void *)&abu   //abu punya data
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
  TEST_ASSERT_EQUAL_PTR(&ali, itemAli.data);
}

/**
 *        Initial          After adding Ali              After adding Baba
 *
 *      tail----+            tail----+-------+            tail----+
 *      head----+            head----+       |            head----+         
 *              |                    |       |                    |         
 *            NULL                  next-----+                  next-------next--------+
 *                                  data--+  |                  data--+    data--+     |
 *                                        |  NULL                     |          |    NULL
 *                                       Ali                         Ali        Baba
 *
 *Given an empty linked list. Add Ali(student). Expect the linked list contains Ali.
 **/
 
 /**
 *        Initial           After adding Abu                                Removing Ali from the list
 *
 *      tail----+         tail----+                                           tail------------------+
 *      head----+         head----+                                           head------------------+
 *              |                 |                                                                |
 *            NULL              next-------next------next-------+                     next      next------next------+
 *                              data--+    data--+   data--+   |                      data--+   data--+   data--+   |
 *                                    |          |         |   NULL                         |         |         |   NULL
 *                                  Ali        Baba       Abu                             Ali        Baba     Abu
 *
 *Given an empty linked list. Add Ali(student). Expect the linked list contains Ali.
 **/

void test_initialized_Ali_and_Baba_and_Abu(void)
{
  LinkedList list;

  printf("Address of Ali: %p\n", &itemAli);
  printf("Address of Baba: %p\n", &itemBaba);
  printf("Address of Abu: %p\n", &itemAbu);
    
  listInit(&list);
  listAdd(&list, &itemAli);
  listAdd(&list, &itemBaba);
  listAdd(&list, &itemAbu);
  
  TEST_ASSERT_EQUAL_PTR(&itemAli, list.head);
  TEST_ASSERT_EQUAL_PTR(&itemAbu, list.tail);
  TEST_ASSERT_EQUAL(3, list.len);
  TEST_ASSERT_NULL(itemAbu.next);
  TEST_ASSERT_NULL(itemAli.next);
  TEST_ASSERT_EQUAL_PTR(&baba, itemBaba.data);
  TEST_ASSERT_EQUAL_PTR(&abu, itemAbu.data);
}

void test_removing_ali(void)
{
  LinkedList list;
  listInit(&list);
  listAdd(&list, &itemAli);
  listAdd(&list, &itemBaba);
  listAdd(&list, &itemAbu);
  
  
  
}

