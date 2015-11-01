#include "common.h"
#define TRUE 1
#define FALSE 0
typedef struct _node
{
	void * data;
	struct _node *next;
}Node;
typedef struct _list
{
	int size;
	Node * top;
	Node *last;
}List;
typedef struct _array
{
		int length;
		void ** list;
}Array;


List * createList(void);
Node * createNode(void);
Node * add2List(Node *node,List *list);
void loopList(List *list,void* (*fn) (Node *));
Node * insert2List(int index,Node *node,List *list);
Node * remove2List(int index,List *list);
Node * getNodeByIndex(int index,List *list);


Array * createArray(int size);
