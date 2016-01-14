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

void test_indexOf(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8,num3 = 7;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	add_to_list(&list,&num3);
	int result = indexOf(list,&num2);
	assert(2==result);
	int result1 = indexOf(list,&num1);
	assert(1==result1);
}

void test_deleteElementAt_beg(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8,num3 = 7;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	add_to_list(&list,&num3);
	assert(10==*(int *)list.head->value);
	int result = *(int *)deleteElementAt(&list,0);
	assert(10==result);
	assert(9==*(int *)list.head->value);
}

void test_deleteElementAt(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8,num3 = 7;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	add_to_list(&list,&num3);
	int * result1 = getElementAt(list,1);
	assert(9==*result1);
	int result = *(int *)deleteElementAt(&list,1);
	assert(9==result);
	int * result2 = getElementAt(list,1);
	assert(8==*result2);
	int * result6 = getElementAt(list,1);
	assert(8==*result6);
}

void test_deleteElementAt_end(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8,num3 = 7;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	add_to_list(&list,&num3);
	assert(7==*(int *)list.tail->value);
	int result = *(int *)deleteElementAt(&list,3);
	assert(7==result);
	assert(8==*(int *)list.tail->value);
}

void test_asArray(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8,num3 = 7;
	int arr[] = {10,9,8,7};
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	add_to_list(&list,&num3);
	void *array =calloc(4,5);
	int result = asArray(list,array,5);
	assert(4==result);
	for(int i=0;i<result;i++){
		assert(arr[i]==**(int **)array);
		array+=8;
	}
}

void test_filter_isEven(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8,num3 = 7;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	add_to_list(&list,&num3);
	LinkedList result = filter(list,isEven,NULL);
	assert(2 == result.length);
	assert(10==*(int *)result.head->value);
	assert(8==*(int *)result.tail->value);
}

void test_filter_isDivisible(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8,num3 = 7;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	add_to_list(&list,&num3);
	int number = 3;
	LinkedList result = filter(list,isDivisible,&number);
	assert(1 == result.length);
	assert(9==*(int *)result.head->value);
	assert(9==*(int *)result.tail->value);
}

void test_reverse(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8,num3 = 7;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	add_to_list(&list,&num3);
	LinkedList result = reverse(list);
	assert(7==*(int *)result.head->value);
	assert(10==*(int *)result.tail->value);
}






