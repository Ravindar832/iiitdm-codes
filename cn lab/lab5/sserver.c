#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, v_read;
    struct sockaddr_in address;
    int opt = 1;
    int add_len = sizeof(address);
    char buffer[1024] = {0};
    char *msg = "Message from Server.";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(server_fd, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&add_len)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    v_read = read(new_socket, buffer, 1024);
    printf("%s\n", buffer);
    send(new_socket, msg, strlen(msg), 0);
    printf("Message sent\n");
    
    int tf=0, w_s=0,n_w=1;
    printf("Enter the Total No of Frames");
    scanf("%d", &tf);
    send(new_socket, (char *)&tf, sizeof(tf), 0);
    printf("Enter the Window Size");
    scanf("%d", &w_s);
    send(new_socket, (char *)&w_s, sizeof(w_s), 0);
    
    int f[20];
    int ack[20];
    int b[20];
    
    int l,i=0,j,k;
    j = 0;
    l = 0;
    int m=0, n=0;

    while (l < tf)
    {
        printf("\nSending the %d Window with frames:", n_w);
        for(m = 0; m < j; m++)
        {
            printf("%d  ", b[m]);
            f[m] = b[m];
        }
        while(j < w_s && i < tf)
        {
            printf("%d  ", i);
            f[j] = i;
            i++;
            j++;
        }
        send(new_socket, (char *)&f, sizeof(f), 0);
        printf("\nWaiting for the acknowledgement.\n");
        v_read = read(new_socket, (char *)&ack, sizeof(ack));
        j = 0;
        k = 0;
        m = 0;
        n = l;
        while (m < w_s && n < tf)
        {
            if (ack[m] == -1)
            {
                printf("\nNegative acknowledgement received for frame: %d\n", f[m]);
                k = 1;
                b[j] = f[m];
                j++;
            }
            else
            {
                l++;
            }
            m++;
            n++;
        }
        if (k == 0)
        {
            printf("\nPositive acknowledgement received for all frames within the window: %d\n", n_w);
        }
        n_w++;
        printf("\n ---------------- Proceeding to next set of frames ----------------\n");
    }
    printf("\nAll Frames hav been sent to reciever Successfully.");
    close(new_socket);
    printf("\nConnection Closed\n");
    shutdown(server_fd, SHUT_RDWR);
    return 0;
}