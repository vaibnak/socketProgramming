#include<stdio.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>

int main(int argc, char* argv[]){

    int socket_desc;
    char *message, server_reply[2000];
    struct sockaddr_in server;
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_desc == -1){
      printf("cannot create the socket");
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8887);

    if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server))<0){
        puts("connect error");
        return 1;
     }

    puts("connected");
    message = "i think i got it";
    if(send(socket_desc, message, strlen(message), 0) < 0)
    {
      puts("send failed");
      return 1;
    }
    puts("data send");

    if(recv(socket_desc, server_reply, 2000, 0)<0){
       puts("receive failed");
     }
    puts("reply received");
    puts("server reply");


return 0;

}
