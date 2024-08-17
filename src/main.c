#include <winsock2.h>
#include <Windows.h>
#include <stdio.h>
#include "http_server.h"

int main()
{
	HTTP_Server * server = init_server(8080);

    while (1) {
        SOCKET client = accept(server->socket, 0, 0);

        char request[512] = {0};
        recv(client, request, 512, 0);

        // GET index
        if (memcmp(request, "GET / ", 6) == 0) {
            FILE* f = fopen("static/index.html", "r");

            char buffer[1024] = {0};
            fread(buffer, 1, 1024, f);
            send(client, buffer, 1024, 0);

            fclose(f);
        }

        // GET (close the server)
        if (memcmp(request, "GET /close-the-server ", 22) == 0) {
            send(client, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n", 43, 0);
            closesocket(client);
            break;
        }

        closesocket(client);
    }
	

    free(server);
}
