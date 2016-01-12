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
