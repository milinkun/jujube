#include "ext.h"
#include "cnet.h"
#include "cthread.h"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *  dowork(Node * p){

	Node *node = p;
	static int count = 0;
	int i=0;
	for(;i<2000000;i++)
	{
		pthread_mutex_lock(&lock);
		count++;
		pthread_mutex_unlock(&lock);
		printf("%d\n",count);
	}
	return NULL;
}

int client()
{
	int fd = initNet("127.0.0.1",888);
	if(fd<0){
		return 1;
	}
	void *buff = malloc(1024);
	char * str = (char *)buff;
	int len = 0;
	while(TRUE){
		len = cread(fd,buff,50);
		str[len]='\0';
		printf("count:%d\n",len);
		printf("%s\n",str);
		if(strcmp(str,"BYE\n")==0){
			break;
		}
	}
	cclose(fd);
	return 0;
}

int main(int argc,char **args)
{
	Node *node = createNode();
	int a = 32;
	node->data=&a;
	 thread_result_t * result = startFn(dowork,node);
	 thread_result_t * result1 = startFn(dowork,node);
	 cjoin(result);
	 cjoin(result1);
	return 0;
}
