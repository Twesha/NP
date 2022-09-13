#include<stdio.h>
#include<stdlib.h>

#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>

int main()
{
    int server_socket;
    char N2[4],N[4];
    server_socket = socket(AF_INET,SOCK_STREAM,0);
    
    struct sockaddr_in servaddr;
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9002);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.2");
    
    connect(server_socket,(struct sockaddr*)&servaddr,sizeof(servaddr));
    
    while(1){
        
        bzero(N2,4);
        bzero(N,4);
        fgets(N2,4,stdin);
        send(server_socket,N2,4,0);
        recv(server_socket,N,4,0);
        printf("%s",N);
    }
    return 0;
}
