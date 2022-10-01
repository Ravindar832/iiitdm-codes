#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include<stdlib.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
    int sock = 0, v_read, client_fd;
    struct sockaddr_in serv_addr;
    char *msg = "Hi Message from Client. ";
    char buffer[2000] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\nError \n");
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address\n");
        return -1;
    }
    if ((client_fd = connect(sock, (struct sockaddr *)&serv_addr,sizeof(serv_addr))) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(sock, msg, strlen(msg), 0);
    printf("Message sent\n");
    v_read = read(sock, buffer, 2000);
    printf("%s\n", buffer);
    
    int choice;
    int j = 0, w_s, tf, n_w=1;
    int l = 0;
    int i=0;
    int m=0,k;
    int buff[20];
    int f[20], ack[20];
    read(sock, (char *)&tf, sizeof(tf));
    read(sock, (char *)&w_s, sizeof(w_s));
    while (l < tf)
    {
        printf("\n-----------Proceding to Next Window---------\n");
        printf("\nThe expected frame is %d with frames:  ", n_w);
        for (m = 0; m < j; m++)
        {
            printf("%d  ", buff[m]);
        }
        while(j < w_s && i < tf)
        {
            printf("%d  ", i);
            i++;
            j++;
        }
        printf("\n\nWaiting for the frame.\n");
        v_read = read(sock, (char *)&f, sizeof(f));
        j = 0;
        m = 0;
        k = l;
        while (m < w_s && k < tf)
        {
            printf("\nPress 1 for acknowledgment for %d to send.", f[m]);
            printf("\nPress -1 for acknowledgment for %d not to send.", f[m]);
            printf("\nEnter the choice: ");
            scanf("%d", &choice);
            if (choice == -1)
            {
                buff[j] = f[m];
                ack[m] = -1;
                printf("\nAcknowledge Not sent for %d ", f[m]);
                j++;
            }
            else
            {
                ack[m] = f[m];
                l++;
            }
            m++;
            k++;
        }
        n_w++;
        send(sock, (char *)&ack, sizeof(ack), 0);
    }
    // closing the connected socket
    printf("\n All Frames have been Recieved Successfully. \n");
    printf("Closing Connection \n");
    close(client_fd);
    return 0;
}