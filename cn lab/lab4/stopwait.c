#include <stdio.h>
int main()
{
    int window_size, sent = 0, ackowledgemet, i;
    printf("Enter Total No. of window_sizes to be transmitted: ");
    scanf("%d", &window_size);
    while (1)
    {
        /* code */
        for (int i = 0; i < window_size; i++)
        {
            printf("Frame %d has been transmitted\n", sent);
            sent++;
            if (sent == window_size)
            {
                break;
            }
        }
        printf("\nEnter the acknowledgement to be received: ");
        scanf("%d", &ackowledgemet);

        if (ackowledgemet < window_size)
        {
            sent = ackowledgemet;
        }
        else
        {
            break;
        }
    }

    printf("Total Frames Transmitted\n");
    return 0;
}