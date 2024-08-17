#include <winsock2.h>
#include <Windows.h>
#include <stdio.h>
#include "http_server.h"

int main()
{
	HTTP_Server * server = init_server(8080);

	SOCKET client = accept(server->socket, 0, 0);

	char request[512] = {0};
	recv(client, request, 512, 0);

	// GET /[file] ...
	if (memcmp(request, "GET / ", 6) == 0) {
		FILE* f = fopen("static/index.html", "r");

		char buffer[512] = {0};
		fread(buffer, 1, 512, f);
		send(client, buffer, 512, 0);

        fclose(f);
	}

    free(server);
}
