

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>

struct frame
{
    int packet[40];
};

struct ack
{
    int acknowledge[40];
};

int main()
{
    int serversocket;
    struct sockaddr_in serveraddr,clientaddr;
    socklen_t len;
    int windowsize,totalpackets,totalframes,framessend=0,i=0,j=0,k,buffer,l;
    struct ack acknowledgement;
    struct frame f1;
    char req[50];
    serversocket=socket(AF_INET,SOCK_DGRAM,0);
    bzero((char*)&serveraddr,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(5018);
    serveraddr.sin_addr.s_addr=INADDR_ANY;
    bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    bzero((char*)&clientaddr,sizeof(clientaddr));
    len=sizeof(clientaddr);
    printf("\nWaiting for client connection.");
    recvfrom(serversocket,req,sizeof(req),0,(struct sockaddr*)&clientaddr,&len);
    printf("\nThe client connection obtained.\t%s",req);
    printf("\nSending request for window size.");
    sendto(serversocket,"REQUEST FOR WINDOWSIZE.",sizeof("REQUEST FOR WINDOWSIZE."),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
    printf("\nWaiting for the windowsize.");
    recvfrom(serversocket,(char*)&windowsize,sizeof(windowsize),0,(struct sockaddr*)&clientaddr,&len);
    printf("\nThe windowsize obtained as:\t%d",windowsize);
    printf("\nObtaining packets from network layer.");
    printf("\nTotal packets obtained:\t%d",(totalpackets=windowsize*2));
    printf("\nTotal frames or windows to be transmitted:\t%d",(totalframes=5));
    printf("\nSending total number of packets.");
    sendto(serversocket,(char*)&totalpackets,sizeof(totalpackets),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
    recvfrom(serversocket,req,sizeof(req),0,(struct sockaddr*)&clientaddr,&len);
    printf("\nSending total number of frames.");
    sendto(serversocket,(char*)&totalframes,sizeof(totalframes),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
    recvfrom(serversocket,req,sizeof(req),0,(struct sockaddr*)&clientaddr,&len);
    printf("\nPRESS ENTER TO START THE PROCESS.");
    fgets(req,2,stdin);
    while( i<totalpackets)
    {
        bzero((char*)&f1,sizeof(f1));
        printf("\nInitialising the transmit buffer.");
        printf("\nThe frame to be send is %d with packets:\t",framessend);
        buffer=i;
        j=0;
        while(j<windowsize && i<totalpackets)
        {
            printf("%d  ",i);
            f1.packet[j]=i;
            i++;
            j++;
        }
        printf("\nSending frame %d",framessend);
        sendto(serversocket,(char*)&f1,sizeof(f1),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
        printf("\nWaiting for the acknowledgement.");
        recvfrom(serversocket,(char*)&acknowledgement,sizeof(acknowledgement),0,(struct sockaddr*)&clientaddr,&len);                         
        j=0;
        k=0;
        l=buffer;
        while(j<windowsize && l<totalpackets)
        {
            if(acknowledgement.acknowledge[j]==-1)
            {
                printf("\nNegative acknowledgement received for packet: %d",f1.packet[j]);
                printf("\nRetransmitting from packet: %d.",f1.packet[j]);
                i=f1.packet[j];
                k=1;
                break;
            }
            j++;
            l++;
        }
        if(k==0)
        {
            printf("\nPositive acknowledgement received for all packets within the frame: %d",framessend);
        }
        framessend++;
        printf("\nPRESS ENTER TO PROCEED……");
        fgets(req,2,stdin);
    }
    printf("\nAll frames send successfully.\nClosing connection with the client.");
    close(serversocket);
}
