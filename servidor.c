#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>

int puerto = 7202;

int main(void)
{
   unsigned int num[3];
   int s, res, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr,aux_addr;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   
   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   //printf("%ld\n", &server_addr.sin_port);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
   char recv[16];
   while(1) {
      recvfrom(s, (char *) &num, 3*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
      inet_ntop(AF_INET,&msg_to_client_addr.sin_addr,recv,sizeof(recv));
      printf("Recibo de %s port: %d\n",recv,ntohs(msg_to_client_addr.sin_port));
      //msg_to_client_addr.
      printf("%u %u\n",num[0],num[1] );
      int p=0;
      for (int i = num[0]; i < num[1]; i++)
      {
      if(num[2]%i==0){
         p++;
         break;
      }
      }
      /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
      sendto(s, (char *)&p, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
}

