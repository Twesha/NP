#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<arpa/inet.h>

int main()
{
    int server_socket,comm_fd1,comm_fd;
    char N1[4],N2[4];
    //string num1, num2;
    
    const char* str1, str2;
    server_socket = socket(AF_INET,SOCK_STREAM,0);
    
    struct sockaddr_in servaddr,servaddr1;
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9002);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(server_socket,(struct sockaddr*)&servaddr,sizeof(servaddr));
    listen(server_socket,2);
    
    
    while(1){
        comm_fd = accept(server_socket,(struct sockaddr*)NULL,NULL);
        comm_fd1 = accept(server_socket,(struct sockaddr*)NULL,NULL);
        bzero(N1,4);
        bzero(N2,4);
        recv(comm_fd,N1,4,0);
        recv(comm_fd1,N2,4,0);
        
        //num1 = N1;
        //num2 = N2;
        
        str1 = N1;
        str2 = N2;
        
        
        int x,y,z;
        //x=atoi(N1);
        //y=atoi(N2);
        //z=x+y;
        
        sscanf(str1, "%d", &x);
        sscanf(str2, "%d", &y);
        //x = stoi(num1);
       // y = stoi(num2);
        printf("Message from client1 : %s",N1);
        printf("Message from client2 : %s",N2);
        
        printf("nandini");
        z=x+y;
        printf("sum : %d",z);
        send(comm_fd,&z,4,0);
        send(comm_fd1,&z,4,0);
        close(comm_fd); 
        close(comm_fd1);  
    } 
    return 0;   
}
