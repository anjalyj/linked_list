#include <stdio.h>
#include "linkedList.c"
#include <assert.h>

void test_createList(){
	LinkedList list = createList();
	assert(0==list.length);
}

void test_add_to_list(){
	LinkedList list = createList();
	int num = 10;
	int result = add_to_list(&list,&num);
	assert(*(int *)list.head->value==10);
	assert(1==result);
}

void test_get_first_element(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	int * result = get_first_element(list);
	assert(10==*result);
}

void test_get_last_element(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	int * result = get_last_element(list);
	assert(8==*result);
}

void increment(void *ele){
	(*(int *)ele) += 1;
}

void test_forEach(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	forEach(list,&increment);
	assert(11==*(int *)list.head->value);
	assert(9==*(int *)list.tail->value);
}

void test_getElementAt(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8,num3 = 7;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	add_to_list(&list,&num3);
	int * result = getElementAt(list,1);
	assert(9==*result);
	int * result1 = getElementAt(list,3);
	assert(7==*result1);

}






