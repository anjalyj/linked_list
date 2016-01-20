#include <stdio.h>
#include "linkedList.c"
#include <assert.h>
#include <string.h>

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

void test_add_to_list_char(){
	LinkedList list = createList();
	char letter[] = "a";
	char letter1[] = "b";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	assert(strcmp((char *)list.head->value,"a")==0);
	assert(strcmp((char *)list.tail->value,"b")==0);
}

void test_add_to_list_string(){
	LinkedList list = createList();
	char letter[] = "anjaly";
	char letter1[] = "babitha";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	assert(strcmp((char *)list.head->value,"anjaly")==0);
	assert(strcmp((char *)list.tail->value,"babitha")==0);
}

void test_add_to_list_float(){
	LinkedList list = createList();
	float a = 15.7,b=20.0;
	add_to_list(&list,&a);
	add_to_list(&list,&b);
	float head=*(float *)list.head->value;
	float tail=*(float *)list.tail->value;
	assert(head==a);
	assert(tail==b);
}

void test_get_first_element(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	int result = *(int *)get_first_element(list);
	assert(10==result);
}

void test_get_first_element_char(){
	LinkedList list = createList();
	char letter[] = "a";
	char letter1[] = "b";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	assert(strcmp((char *)get_first_element(list),"a")==0);
}

void test_get_first_element_string(){
	LinkedList list = createList();
	char letter[] = "anjaly";
	char letter1[] = "babitha";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	assert(strcmp((char *)get_first_element(list),"anjaly")==0);
}

void test_get_first_element_emptystring(){
	LinkedList list = createList();
	char letter[] = "";
	char letter1[] = "babitha";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	assert(strcmp((char *)get_first_element(list),"")==0);
}

void test_get_first_element_float(){
	LinkedList list = createList();
	float a = 15.7,b=20.0;
	add_to_list(&list,&a);
	add_to_list(&list,&b);
	float first = *(float *)get_first_element(list); 
	assert(first==a);
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

void test_get_last_element_char(){
	LinkedList list = createList();
	char letter[] = "a";
	char letter1[] = "b";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	assert(strcmp((char *)get_last_element(list),"b")==0);
}

void test_get_last_element_string(){
	LinkedList list = createList();
	char letter[] = "anjaly";
	char letter1[] = "babitha";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	assert(strcmp((char *)get_last_element(list),"babitha")==0);
}

void test_get_last_element_emptystring(){
	LinkedList list = createList();
	char letter1[] = "babitha";
	char letter[] = "";
	add_to_list(&list,letter1);
	add_to_list(&list,letter);
	assert(strcmp((char *)get_last_element(list),"")==0);
}

void test_get_last_element_float(){
	LinkedList list = createList();
	float a = 15.7,b=20.0;
	add_to_list(&list,&a);
	add_to_list(&list,&b);
	float first = *(float *)get_last_element(list); 
	assert(first==b);
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

void test_getElementAt_for_char(){
	LinkedList list = createList();
	char letter[] = "a";
	char letter1[] = "b";
	char letter2[] = "c";
	char letter3[] = "d";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	add_to_list(&list,letter2);
	add_to_list(&list,letter3);
	assert(strcmp((char *)getElementAt(list,1),letter1)==0);
	assert(strcmp((char *)getElementAt(list,0),letter)==0);
	assert(strcmp((char *)getElementAt(list,2),letter2)==0);
	assert(strcmp((char *)getElementAt(list,3),letter3)==0);
}

void test_getElementAt_for_string(){
	LinkedList list = createList();
	char letter[] = "anjaly";
	char letter1[] = "babitha";
	char letter2[] = "chithra";
	char letter3[] = "diya";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	add_to_list(&list,letter2);
	add_to_list(&list,letter3);
	assert(strcmp((char *)getElementAt(list,1),letter1)==0);
	assert(strcmp((char *)getElementAt(list,0),letter)==0);
	assert(strcmp((char *)getElementAt(list,2),letter2)==0);
	assert(strcmp((char *)getElementAt(list,3),letter3)==0);
}

void test_getElementAt_for_empty_string(){
	LinkedList list = createList();
	char letter[] = "a";
	char letter1[] = "";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	assert(strcmp((char *)getElementAt(list,1),letter1)==0);
}

void test_getElementAt_for_float(){
	LinkedList list = createList();
	float a = 15.7,b=20.0;
	add_to_list(&list,&a);
	add_to_list(&list,&b);
	assert(*(float *)getElementAt(list,1)==b);
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

void test_indexOf_char(){
	LinkedList list = createList();	
	char letter[] = "a";
	char letter1[] = "b";
	char letter2[] = "c";
	char letter3[] = "d";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	add_to_list(&list,letter2);
	add_to_list(&list,letter3);
	int result = indexOf(list,letter2);
	assert(2==result);
	int result1 = indexOf(list,letter1);
	assert(1==result1);
}

void test_indexOf_string(){
	LinkedList list = createList();	
	char letter[] = "anjaly";
	char letter1[] = "babitha";
	char letter2[] = "chithra";
	char letter3[] = "diya";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	add_to_list(&list,letter2);
	add_to_list(&list,letter3);
	int result = indexOf(list,letter);
	assert(0==result);
	int result1 = indexOf(list,letter3);
	assert(3==result1);
}

void test_indexOf_empty_string(){
	LinkedList list = createList();	
	char letter[] = "anjaly";
	char letter1[] = "babitha";
	char letter2[] = "";
	char letter3[] = "diya";
	add_to_list(&list,letter);
	add_to_list(&list,letter1);
	add_to_list(&list,letter2);
	add_to_list(&list,letter3);
	int result = indexOf(list,letter2);
	assert(2==result);
}

void test_indexOf_float(){
	LinkedList list = createList();	
	float a = 15.7,b=20.0;
	add_to_list(&list,&a);
	add_to_list(&list,&b);
	int result = indexOf(list,&a);
	assert(0==result);
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

void test_map(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8,num3 = 7;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	add_to_list(&list,&num3);
	int number = 3;
	LinkedList result = map(list,increment1,&number);
	assert(4==result.length);
	assert(13==*(int *)result.head->value);
	assert(10==*(int *)result.tail->value);
}

void test_reduce(){
	LinkedList list = createList();
	int num = 10,num1 = 9,num2 = 8,num3 = 7;
	add_to_list(&list,&num);
	add_to_list(&list,&num1);
	add_to_list(&list,&num2);
	add_to_list(&list,&num3);
	int hint = 0;
	int initial_value = 0;
	int result = *(int *)reduce(list,sum,&hint,&initial_value);
	assert(34==result);
}






