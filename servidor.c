#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>

#define PORT 8080

void error(const char *msg)
{
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[])
{
  int sock, length, n, m;
  socklen_t fromlen;
  struct sockaddr_in server;
  struct sockaddr_in from;
  char buffer[256];
  char buf[1024];

  // if (argc < 2) {
  //   fprintf(stderr, "ERROR, no port provided\n");
  //   exit(0);
  // }
  
  sock=socket(AF_INET, SOCK_DGRAM, 0);

  if (sock < 0) error("Opening socket");
    length = sizeof(server);

  bzero(&server,length);
  
  server.sin_family=AF_INET;
  server.sin_addr.s_addr=INADDR_ANY;
  server.sin_port=htons( PORT );

  if (bind(sock,(struct sockaddr *)&server,length)<0) 
    error("Erro ao fazer bind");

  fromlen = sizeof(struct sockaddr_in);

  while (1) {
    n = recvfrom(sock,buf,1024,0,(struct sockaddr *)&from,&fromlen);
    if (n < 0) 
      error("ERROR: Receber de");

    write(1,"Mensagem recebida: ",19);
    write(1,buf,n);

    bzero(buffer,256);
    fgets(buffer,255,stdin);
    
    m=sendto(sock,buffer,strlen(buffer),0,(const struct sockaddr *)&from,fromlen);
    if (m < 0) {
      error("ERROR: enviar para");
    }else{
      printf("Mensagem enviada...\n");
    }    
    
    // n = sendto(sock,"Sua mensagem foi recebida.\n",28,0,(struct sockaddr *)&from,fromlen);
    // if (n  < 0) 
    //   error("ERROR: enviar para");
  }
  return 0;
}