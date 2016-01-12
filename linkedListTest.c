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




