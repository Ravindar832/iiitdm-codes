
#include <stdio.h>
int main()
{
    int windowsize, sent = 0, ack, i;
    printf("enter window size\n");
    scanf("%d", &windowsize);
    while (1)
    {
        for (i = 0; i < windowsize; i++)
        {
            printf("Frame %d has been transmitted.\n", sent);
            sent++;
            if (sent == windowsize)
                break;
        }
        printf("\nPlease enter the last Acknowledgement received.\n");
        scanf("%d", &ack);

        if (ack == windowsize)
            break;
        else
            sent = ack;
    }
    return 0;
}
// Name: V Nagasai
// Roll: CS20B1016
// Q: Write program for Go Back N protocol

#include <stdio.h>
#include <stdlib.h>

int framesCount, windowSize, droppingFrame, totalFrames = 0;

int main()
{
    printf("Enter the size of senders window: ");
    scanf("%d", &windowSize);
    printf("Enter the number of frames sent by sender: ");
    scanf("%d", &framesCount);
    printf("Enter the dropping bit index: ");
    scanf("%d", &droppingFrame);
    int presentFrame = 1;

    while (presentFrame <= framesCount)
    {
        if (framesCount - presentFrame < windowSize - 1)
        {
            if ((totalFrames + 1) % droppingFrame == 0)
            {
                totalFrames = totalFrames + framesCount - presentFrame + 1;
            }
            else
            {
                presentFrame++;
                totalFrames++;
            }
        }
        else
        {
            if ((totalFrames + 1) % droppingFrame == 0)
            {
                totalFrames = totalFrames + windowSize;
            }
            else
            {
                presentFrame++;
                totalFrames++;
            }
        }
    }
    printf("Number of Frames Sent: %d\n", totalFrames);
    return 0;
}