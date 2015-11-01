#include "common.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int initNet(const char *host,int port);
ssize_t cwrite(int fd,void *buff,size_t size);
ssize_t cread(int fd,void *buff,size_t length);
void cclose(int fd);
