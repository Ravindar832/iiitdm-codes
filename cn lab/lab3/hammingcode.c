#include <stdio.h>
#include <conio.h>

#include <math.h>
void main()
{
    int data[20];
    int dataafterham[20], c, c1, c2, c3,c4, i;

    //data bits = 7 , parity bits 4

    printf("Enter the data bits one by one\n");
    scanf("%d", &data[10]);

    scanf("%d", &data[9]);
    scanf("%d", &data[8]);
    scanf("%d", &data[6]);
    scanf("%d", &data[5]);
    scanf("%d", &data[4]);
    scanf("%d", &data[2]);

    // Calculation of even parity
    data[0] = data[2] ^ data[4] ^ data[6] ^ data[8] ^ data[10];

    data[1] = data[2] ^ data[5] ^ data[6] ^ data[9] ^ data[10];

    data[3] = data[4] ^ data[5] ^ data[6];

    data[7] = data[8] ^ data[9] ^ data[10];

    printf("\nEncoded data is\n");
    for (i = 0; i < 11; i++)
        printf("%d", data[i]);

    printf("\n\nEnter received data bits one by one\n");
    for (i = 0; i < 11; i++)
        scanf("%d", &dataafterham[i]);

    

    c1=dataafterham[0]^dataafterham[2]^dataafterham[4]^dataafterham[6]^dataafterham[8]^dataafterham[10];
    c2=dataafterham[0]^dataafterham[1]^dataafterham[4]^dataafterham[5]^dataafterham[8]^dataafterham[9];
    c3=dataafterham[4]^dataafterham[5]^dataafterham[6]^dataafterham[7];
    c4=dataafterham[0]^dataafterham[1]^dataafterham[2]^dataafterham[3];
    c=c4*8+c3*4+c2*2+c1 ;

    if (c == 0)
    {
        printf("\nNo error while transmission of data\n");
    }
    else
    {
        printf("\nError on position %d", c);

        printf("\nData sent : ");
        for (i = 0; i < 11; i++)
            printf("%d", data[i]);

        printf("\nData received : ");
        for (i = 0; i <11; i++)
            printf("%d", dataafterham[i]);
        printf("\nCorrect message is\n");

        // if errorneous bit is 0 we complement it else vice versa
        if (dataafterham[11 - c] == 0)
            dataafterham[11 - c] = 1;
        else
            dataafterham[11 - c] = 0;
        for (i = 0; i < 11; i++)
        {
            printf("%d", dataafterham[i]);
        }
    }
}