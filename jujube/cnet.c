/*
 * cnet.c
 *
 *  Created on: 2015年10月18日
 *      Author: root
 */
#include "cnet.h"

int initNet(const char *host,int port)
{
	int fd = -1;
		fd = socket(AF_INET,SOCK_STREAM,0);
		if(fd==-1)
		{
			printf("socket wrong");
			return -1;
		}
		struct sockaddr_in server;
		bzero(&server,sizeof(server));
		server.sin_family=AF_INET;
		server.sin_port=htons(port);
		inet_pton(AF_INET,host,&server.sin_addr);
		int con = connect(fd,(struct sockaddrr *)&server,sizeof(server));
		if(con!=0)
		{
			printf("connect wrong\n");
			return -1;
		}
		printf("connect accussce!\n");
	return fd;
}

ssize_t cwrite(int fd,void *buff,size_t size)
{
		return write(fd,buff,size);
}
ssize_t cread(int fd,void *buff,size_t length)
{
		return read(fd,buff,length);
}

void cclose(int fd)
{
	close(fd);
}
