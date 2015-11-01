/*
 * cthread.c
 *
 *  Created on: 2015年10月24日
 *      Author: root
 */
#include "cthread.h"
 thread_result_t * startFn(void *(*start_routine)(void *), void *arg) {
	thread_result_t * result= (thread_result_t *)malloc(sizeof(thread_result_t));
    if(result==NULL)return NULL;
	result->result = pthread_create(&(result->tid), NULL, start_routine, arg);
	return result;
}
 void cjoin(thread_result_t  *result)
 {
	 if(result==NULL){
		 return;
	 }
	pthread_join(result->tid,NULL);
 }


