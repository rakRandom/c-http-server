#include "http_server.h"

HTTP_Server * init_server(u_short port) {
    WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);

    HTTP_Server * http_server = (HTTP_Server*) malloc(sizeof(HTTP_Server));
	
	http_server->socket = socket(AF_INET, SOCK_STREAM, 0);

	http_server->addr.sin_family = AF_INET;
	http_server->addr.sin_addr.s_addr = 0;
	http_server->addr.sin_port = htons(port);

	bind(http_server->socket, (SOCKADDR *) &http_server->addr, sizeof(http_server->addr));

	listen(http_server->socket, 10);

    return http_server;
}