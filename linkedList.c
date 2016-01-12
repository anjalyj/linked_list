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