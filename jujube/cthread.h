/*
 * cthread.h
 *
 *  Created on: 2015年10月24日
 *      Author: root
 */

#include "common.h"
#include <pthread.h>
/**
 * thread result
 */
typedef struct {
	int result;/*0 */
	pthread_t tid;
}  thread_result_t;

typedef struct{
	size_t max;
	size_t core;
}cthreadPool;
thread_result_t * startFn(void *(*start_routine)(void *), void *arg);

//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_lock(&lock);
//pthread_mutex_unlock(&lock);
void cjoin(thread_result_t  *result);
