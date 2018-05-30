#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <time.h>
#include <unistd.h>
#include <net/if.h>

#define PORT 7777

int main()
{
   struct sockaddr_in si_me,si_other;
   int sock,i,slen=sizeof(si_other),recv_len;
   char buf[2000];
   char message[1024];


   if((sock=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP))==-1)
   {
      puts("socket fail created");
   }

   memset((char *)&si_me,0,sizeof(si_me));

   si_me.sin_family = AF_INET;
   si_me.sin_port = htons(PORT);
   si_me.sin_addr.s_addr = htonl(INADDR_ANY);

   if(bind(sock,(struct sockaddr*)&si_me,sizeof(si_me))==-1)
   {
      puts ("bind");
   }

   while(1)
   {
      printf("waiting for data... ");
      fflush(stdout);

 
    if((recv_len=recvfrom(sock,buf,2000,0,(struct sockaddr *)&si_other,slen))==-1)
    {
        puts("recvfrom()");
    }

    printf("received packet from %s:%d\n",inet_ntoa(si_other.sin_addr),ntohs(si_other.sin_port));

     printf("data: %s\n",buf);

    if(strcasecmp(buf,"time")==0)
    {
       time_t rawtime;
       struct tm *timeinfo;
       time(&rawtime);
    
       timeinfo = localtime(&rawtime);
       printf("current server date: %s",asctime(timeinfo));
    
       strcpy(buf,asctime(timeinfo));
    }


    sendto(sock,buf,2000,0,(struct sockaddr *)&si_other,slen);
    
  }

close(sock);
return 0;
}


     