
// LRC in C Program.


#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int data[SIZE], data_size, temp[SIZE], parity[SIZE];
int i, j, blocks;

void LRC()
{
    int k =0;
    blocks = data_size/4;

    for(i = 0; i < data_size; i+=4)
    {
        int count = 0;
        for(j = i; j < i+4; j++)
        {
            if(data[j] == 1)
            {
                count++;
            }
        }

        if(count % 2 == 1)
        {
            parity[k] = 1;
            k++;
        }
        else
        {
            parity[k] = 0;
            k++;
        }
    }
}

int verify()
{
    for(i = 0; i < data_size; i++)
    {
        if(data[i] != temp[i])
        {
            return 1;
        }

        else
            continue;
    }

    return 0;
}

int main()
{
    int option;
    while(1)
    {
        printf("\n\n1. Send a message.");
        printf("\n2. Check received message.");
        printf("\n3. Exit\n");
        printf("\nEnter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Enter the size of the bits in the multiples of 4 : ");
                scanf("%d", &data_size);

                if(data_size % 4 != 0)
                {
                    printf("\nPlease enter the size of the bits in multiples of 4\n");
                    break;
                }

                printf("Enter the  bits : ");
                for(i = 0; i < data_size; i++)
                {
                    scanf("%d", &data[i]);
                }

                LRC();

                for(i = 0; i < data_size; i++)
                {
                    temp[i] = data[i];
                }

                for(i = 0; i < data_size; i++)
                {
                    printf("%d ", temp[i]);
                }


                for(i = 0; i < blocks; i++)
                {
                    printf("%d ", parity[i]);
                }

                break;

            case 2:
                
                printf("Enter the size of the bits (data bits + VRC code bits): ");
                scanf("%d", &data_size);

                printf("Enter the  bits : ");
                for(i = 0; i < data_size; i++)
                {
                    scanf("%d", &data[i]);
                }

                if(verify() == 1)
                    printf("\nData transmitted is not corrupted - ACCEPTED\n");

                else
                    printf("\nData transmitted is corrupted - REJECTED\n");
                
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("\nEnter a correct option.\n");
        }
    }
    return 0;
}
