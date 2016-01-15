typedef struct element{
	void *value;
	struct element *next;
} Element;

typedef struct list{
	Element * head;
	Element * tail;
	int length;
} LinkedList;


LinkedList createList(void);

int add_to_list(LinkedList *,void *);

void *get_first_element(LinkedList list);

void *get_last_element(LinkedList list);

typedef void (*ElementProcessor)(void *);

void forEach(LinkedList, ElementProcessor e);

void * getElementAt(LinkedList, int );

int indexOf(LinkedList, void *);

void * deleteElementAt(LinkedList *, int);

int asArray(LinkedList, void **, int maxElements);

typedef int MatchFunc (void *, void *);

int isEven(void* hint, void* item);

int isDivisible(void* hint, void* item);

LinkedList  filter(LinkedList, MatchFunc, void * );

LinkedList reverse(LinkedList);

typedef void ConvertFunc (void *, void *,void *);

void increment1(void* hint, void* sourceItem, void* destinationItem);

LinkedList map(LinkedList, ConvertFunc, void * );

typedef void* Reducer( void* , void*, void*);

void* sum(void* hint, void* previousItem, void* item);

void * reduce(LinkedList, Reducer, void *hint, void *initialValue);











