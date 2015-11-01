/*
 * ext.c
 *
 *  Created on: 2015年10月11日
 *      Author: root
 */
#include "ext.h"

/**
 * create List
 */
List * createList(void){
	List *list = (List *)malloc(sizeof(List));
	if(list==NULL){
		return NULL;
	}
	memset(list,0,sizeof(List));
	list->size=0;
	return list;
}

Node * createNode(void){
	Node *node = (Node *)malloc(sizeof(Node));
	if(node==NULL){
		return NULL;
	}
	memset(node,0,sizeof(List));
	return node;
}

Node * add2List(Node *node,List *list){
	if(list==NULL || node==NULL)return NULL;
	node->next = NULL;
	if(list->size==0){
		list->top = node;
		list->last = node;
		list->size++;
	}else{
		list->last->next = node;
		list->last = node;
		list->size++;
	}
	return node;
}

Node * remove2List(int index,List *list){
	if(list==NULL)return NULL;
	if(index<0 || index>=list->size)return NULL;
	int curIndex = 0;
	Node *tmp = NULL;
	Node *pre = NULL;
	for(;;){
		if(curIndex==0){
			tmp = list->top;
		}else{
			pre = tmp;
			tmp =tmp->next;
		}

		if(curIndex==index){
			if(pre==NULL){
				list->top = tmp->next;
			}else{
				pre->next = tmp->next;
			}
			if(list->last==tmp){
					list->last = NULL;
			}
			list->size--;
			return tmp;
		}
		curIndex++;
	}
	return NULL;
}

Node * insert2List(int index,Node *node,List *list){
	if(list==NULL||NULL==node)return NULL;
	if(index<0 || (index>=list->size&&list->size>0))return NULL;
	int curIndex = 0;
	node->next = NULL;
	Node *tmp = NULL;
	Node *pre = NULL;
	for(;;){
		if(curIndex==0){
			tmp = list->top;
		}else{
			pre = tmp;
			tmp =tmp->next;
		}
		if(curIndex==index){
			if(pre==NULL){
				node->next = list->top;
				list->top = node;
				if(tmp==NULL){
					list->last=node;
				}
			}else{
				pre->next = node;
				node->next = tmp;
			}
			list->size++;
			return node;
		}
		curIndex++;
	}
	return NULL;
}


/**
 * loop all element
 */
void loopList(List *list,void* (*fn) (Node *)){
	if(list==NULL||list->size==0){
		return;
	}
	Node *cur = list->top;
	fn(cur);
	while(1){
		cur = cur->next;
		if(cur==NULL){
			break;
		}
		fn(cur);
	}
}

Node * getNodeByIndex(int index,List *list){
	if(list==NULL)return NULL;
	if(index<0 || index>=list->size)return NULL;
	int curIndex = 0;
	Node *tmp = NULL;
	for(;;){
		if(curIndex==0){
			tmp = list->top;
		}else{
			tmp =tmp->next;
		}
		if(curIndex==index){
			return tmp;
		}
		curIndex++;
	}
	return NULL;
}

Array * createArray(int size)
{
	Array *arr = (Array *)malloc(sizeof(Array));
	if(arr==NULL){
		return NULL;
	}
	int len = sizeof(void *);
	len = len*size;
	void *p = malloc(len);
	memset(p,0,len);
	if(p==NULL){
		return arr;
	}
	arr->length = size;
	arr->list=p;
	return arr;
}
