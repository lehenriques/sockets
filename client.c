#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

void error(const char *msg)
{
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[])
{
  int sock, n, m;
  unsigned int length;
  struct sockaddr_in server, from;
  struct hostent *hp;
  char buffer[256];
  char buf[1024];

  sock= socket(AF_INET, SOCK_DGRAM, 0);
  if (sock < 0) error("socket");

  server.sin_family = AF_INET;
  hp = gethostbyname("127.0.0.1");
  if (hp==0) 
    error("Unknown host");

  bcopy((char *)hp->h_addr, (char *)&server.sin_addr, hp->h_length);
  server.sin_port = htons( PORT );
  length=sizeof(struct sockaddr_in);
  
  while (1) {
    printf("Digite sua mensagem: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    
    n=sendto(sock,buffer,strlen(buffer),0,(const struct sockaddr *)&server,length);
    if (n < 0) {
      error("ERROR: enviar para");
    }else{
      printf("Mensagem enviada...\n");
    } 

    m = recvfrom(sock,buffer,256,0,(struct sockaddr *)&from, &length);
    if (m < 0) 
      error("ERROR: Receber de");
    write(1,buffer,m);
  }
  close(sock);
  return 0;
}
