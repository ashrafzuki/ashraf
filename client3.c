#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER "192.168.87.128"
#define BUFLEN 1000
#define PORT 7777


int main(void)
{
   struct sockaddr_in si_other;
   int s,i,slen=sizeof(si_other);
   char buf[BUFLEN];
   char message[BUFLEN];


   if((s=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP))==-1)
   {
      puts("socket created");
   }

   memset((char *)&si_other,0,sizeof(si_other));
   si_other.sin_family = AF_INET;
   si_other.sin_port = htons(PORT);

   if(inet_aton(SERVER,&si_other.sin_addr)==0)
   {
      fprintf(stderr, "inet_aton() failed\n");
   }

   while(1)
   {
      printf("Enter message: ");
      gets(message);

 
    if(sendto(s,message,strlen(message),0,(struct sockaddr *)&si_other,slen)==-1)
    {
        puts("sendto()");
    }

    memset(buf,'\0',BUFLEN);

    if(recvfrom(s,buf,BUFLEN,0,(struct sockaddr *)&si_other,&slen)==-1)
    {
        puts("recvfrom()");
    }

     puts(buf);

  }

close(s);
return 0;
}


     #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER "192.168.87.128"
#define BUFLEN 1000
#define PORT 7777


int main(void)
{
   struct sockaddr_in si_other;
   int s,i,slen=sizeof(si_other);
   char buf[BUFLEN];
   char message[BUFLEN];


   if((s=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP))==-1)
   {
      puts("socket created");
   }

   memset((char *)&si_other,0,sizeof(si_other));
   si_other.sin_family = AF_INET;
   si_other.sin_port = htons(PORT);

   if(inet_aton(SERVER,&si_other.sin_addr)==0)
   {
      fprintf(stderr, "inet_aton() failed\n");
   }

   while(1)
   {
      printf("Enter message: ");
      gets(message);

 
    if(sendto(s,message,strlen(message),0,(struct sockaddr *)&si_other,slen)==-1)
    {
        puts("sendto()");
    }

    memset(buf,'\0',BUFLEN);

    if(recvfrom(s,buf,BUFLEN,0,(struct sockaddr *)&si_other,&slen)==-1)
    {
        puts("recvfrom()");
    }

     puts(buf);

  }

close(s);
return 0;
}


     