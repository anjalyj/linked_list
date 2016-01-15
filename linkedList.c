#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createList(void){
	LinkedList list;
	list.length=0;
	list.head = NULL;
	list.tail = NULL;
	return list;
}

int add_to_list(LinkedList *list,void *data){
	Element *ele = (Element *)malloc(sizeof(Element));
	ele->value=data;
	ele->next=NULL;
	if(list->length==0){
		list->tail=list->head=ele;
	}
	else{
		list->tail->next=ele;
		list->tail=ele;
	}
	list->length++;
	return list->length;
}

void *get_first_element(LinkedList list){
	return list.head->value; 
}

void *get_last_element(LinkedList list){
	return list.tail->value;
}

void forEach(LinkedList list, ElementProcessor e){
	Element *ele = list.head;
	while(ele!=NULL){
		e(ele->value);
		ele= ele->next;
	}
}

void * getElementAt(LinkedList list, int index){
	int count=0;
		Element *ele = list.head;
	while(ele!=NULL){
		if(count==index)
			return ele->value;
		ele= ele->next;
		count++;
	}
	return NULL;
}

int indexOf(LinkedList list, void *value){
	int count = 0;
	Element *ele = list.head;
	while(ele!=NULL){
		if(ele->value==value)
			return count;
		ele= ele->next;
		count++;
	}
	return -1;
}

void * deleteElementAt(LinkedList *list, int index){
	void * value;
	Element *ele = list->head,*preEle;
	if(index >= list->length || index < 0) return NULL;
	else if(index == 0){
		value = ele->value;
		preEle = ele->next;
		list->head = preEle;
		free(ele);
		return value;
	}
	int *num = getElementAt(*list,index);
	while(ele->value!=num){
		preEle = ele;
		ele = ele->next;
	}
	if(ele->next==NULL){
		value = ele->value; 
		preEle->next = NULL;
		list->tail=preEle;
		free(ele);
		return value;
	}
	else{
		value = ele->value; 
		preEle->next = ele->next;
		free(ele);
		return value;
	}
}


int asArray(LinkedList list, void ** array, int maxElements){
	int count = 0; 
	Element *ele = list.head;
	int length = maxElements > list.length ? list.length : maxElements;
	for(int i=0;i<length;i++){
		array[i]=ele->value;
		count++;
		ele = ele->next;
	}
	return count;
}

int isEven(void* hint, void* item){
	return (*(int *)item %2 == 0);
}

int isDivisible(void* hint, void* item){
	int num = *(int *)item;
	int  diviser = *(int *)hint;
	return num % diviser == 0;
}

LinkedList  filter(LinkedList list, MatchFunc match, void * hint){
	Element *ele = list.head;
	LinkedList new_list = createList();
	while(ele != NULL){
		if(match(hint,ele->value))
			add_to_list(&new_list,ele->value);
		ele= ele->next;
	}
	return new_list;
}

LinkedList reverse(LinkedList list){
	int length = list.length;
	LinkedList new_list = createList();
	int *value;
	for(int i=length-1;i>=0;i--){
		value = getElementAt(list,i);
		add_to_list(&new_list,value);
	}
	return new_list;
}

void increment1(void* hint, void* sourceItem, void* destinationItem){
	*(int *)destinationItem = *(int *)sourceItem + *(int *)hint;
}

LinkedList map(LinkedList list, ConvertFunc convert, void * hint){
	LinkedList new_list = createList();
	Element *ele = list.head;
	for(int i=0;i<list.length;i++){
		void *new_ele = malloc(sizeof(void ()));
		convert(hint,ele->value,new_ele);
		add_to_list(&new_list,new_ele);
		ele = ele->next;

	}
	return new_list;
}

void *sum(void* hint, void* previousItem, void* item){
	*(int*)item= *(int*)previousItem + *(int*)item;
	return (int*)item;
}

void *reduce(LinkedList list, Reducer reducer, void* hint, void* initialValue){
	Element *ele = list.head;
	for(int i=0;i<list.length;i++){
		initialValue = reducer(hint,initialValue,ele->value);
		ele = ele->next;
	}
	return initialValue;
}






