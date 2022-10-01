
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

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
    int clientsocket;
    struct sockaddr_in serveraddr;
    socklen_t len;
    struct hostent *server;
    struct frame f1;
    int windowsize, totalpackets, totalframes, i = 0, j = 0, framesreceived = 0, k, buffer, l;
    struct ack acknowledgement;
    char req[50];
    clientsocket = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(5018);
    server = gethostbyname("127.0.0.1");

    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, sizeof(server->h_addr));
   
    sendto(clientsocket, "HI I AM CLIENT.", sizeof("HI I AM CLIENT."), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("\nWaiting for reply.");
    recvfrom(clientsocket, req, sizeof(req), 0, (struct sockaddr *)&serveraddr, &len);
    printf("\nThe server has send:\t%s", req);
    
    printf("\nEnter the window size:\t");
    scanf("%d", &windowsize);
    printf("\n\nSending the window size.");
    sendto(clientsocket, (char *)&windowsize, sizeof(windowsize), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("\nWaiting for the server response.");
    recvfrom(clientsocket, (char *)&totalpackets, sizeof(totalpackets), 0, (struct sockaddr *)&serveraddr, &len);
    printf("\nThe total packets are:\t%d", totalpackets);
    sendto(clientsocket, "RECEIVED.", sizeof("RECEIVED."), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    recvfrom(clientsocket, (char *)&totalframes, sizeof(totalframes), 0, (struct sockaddr *)&serveraddr, &len);
    printf("\nThe total frames/windows are:\t%d", totalframes);
    sendto(clientsocket, "RECEIVED.", sizeof("RECEIVED."), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    printf("\nStarting the process of receiving.");
    while (i < totalpackets)
    {
        printf("\nInitialising the receive buffer.");
        printf("\nThe expected frame is %d with packets:  ", framesreceived);
        j = 0;
        buffer = i;
        while (j < windowsize && i < totalpackets)
        {
            printf("%d  ", i);
            i++;
            j++;
        }
        printf("\n\nWaiting for the frame.");
        recvfrom(clientsocket, (char *)&f1, sizeof(f1), 0, (struct sockaddr *)&serveraddr, &len);
        printf("\nReceived frame %d\nEnter -1 to send negative acknowledgement for the following packets.", framesreceived);
        j = 0;
        l = buffer;
        k = 0;
        while (j < windowsize && l < totalpackets)
        {
            printf("\nPacket: %d\n", f1.packet[j]);
            scanf("%d", &acknowledgement.acknowledge[j]);
            if (acknowledgement.acknowledge[j] == -1)
            {
                if (k == 0)
                {
                    i = f1.packet[j];
                    k = 1;
                }
            }
            j++;
            l++;
        }
        framesreceived++;
        sendto(clientsocket, (char *)&acknowledgement, sizeof(acknowledgement), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    }
    printf("\nAll frames received successfully.\nClosing connection with the server.");
    close(clientsocket);
}