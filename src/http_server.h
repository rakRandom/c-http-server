#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <winsock2.h>
#include <Windows.h>
#include <stdlib.h>

typedef struct HTTP_Server {
	SOCKET socket;
	struct sockaddr_in addr;
} HTTP_Server;

HTTP_Server * init_server(u_short port);

#endif // HTTP_SERVER_H
