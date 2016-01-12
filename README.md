Make sure you have a structure as follows:

linkedList.h  //Contains all definitions needed
linkedList.c  //Contains all the implementations of the methods below and any other methods you see fit
linkedListTest.c //Contains all your tests


LinkedList:

is a data type that holds the first and last element of a linked list(head and tail). It may also contain the number of elements in that list.


LinkedList createList(void);

create an empty LinkedList structure.


int add_to_list(LinkedList *,void *);

Given a reference to some data, add it to list. For now, add it to the end of the list. 


void *get_first_element(LinkedList list);

This function returns the first element in the list. 


void *get_last_element(LinkedList list);

This function returns the first element in the list. 


void forEach(LinkedList, ElementProcessor e)

where ElementProessor is a function pointer type with the following signature: 


void (*ElementProcessor)(void *)

Write a generic traverse function that can go through a list and process each element.


Note that testing forEach is not easy since it doesn't return a value. One simple, somewhat ugly way of doing it is for instance, is to have a list of integers and write a function that adds one to the data itself. Call traverse with this function as an argument and then verify that the list's first and last elements have been incremented. 

Example: 

void increment(void *){
// code
}
forEach(list,&increment);