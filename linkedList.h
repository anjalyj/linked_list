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


