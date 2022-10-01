#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int data[SIZE], data_size, temp[SIZE], parity[SIZE];
int i, j, blocks;

void LRC()
{
    int k = 0;
    blocks = data_size / 4;

    for (i = 0; i < data_size; i += 4)
    {
        int count = 0;
        for (j = i; j < i + 4; j++)
        {
            if (data[j] == 1)
            {
                count++;
            }
        }

        if (count % 2 == 1)
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
    for (i = 0; i < data_size; i++)
    {
        if (data[i] != temp[i])
        {
            return 1;
        }

        else
            continue;
    }

    return 0;
}
void VRC()
{
    blocks = data_size / 4;

    for (i = 0; i < blocks; i++)
    {
        int count = 0;
        for (j = 4 * i; j < 4 * (i + 1); j++)
        {
            if (data[j] == 1)
            {
                count++;
            }
        }

        if (count % 2 == 1)
        {
            parity[i] = 1;
        }
        else
        {
            parity[i] = 0;
        }
    }

    int option;
    while (1)
    {
        printf("\n\n1. Send a message.");
        printf("\n2. Check received message.");
        printf("\n3. Exit\n");
        printf("\nEnter your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the size of the bits in the multiples of 4 : ");
            scanf("%d", &data_size);

            if (data_size % 4 != 0)
            {
                printf("\nPlease enter the size of the bits in multiples of 4\n");
                break;
            }

            printf("Enter the  bits : ");
            for (i = 0; i < data_size; i++)
            {
                scanf("%d", &data[i]);
            }

            LRC();

            for (i = 0; i < data_size; i++)
            {
                temp[i] = data[i];
            }

            for (i = 0; i < data_size; i++)
            {
                printf("%d ", temp[i]);
            }

            for (i = 0; i < blocks; i++)
            {
                printf("%d ", parity[i]);
            }

            break;

        case 2:

            printf("Enter the size of the bits (data bits + VRC code bits): ");
            scanf("%d", &data_size);

            printf("Enter the  bits : ");
            for (i = 0; i < data_size; i++)
            {
                scanf("%d", &data[i]);
            }

            if (verify() == 1)
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
}
void hamming()
{
    int data[20];
    int dataafterham[20], c, c1, c2, c3, c4, i;

    // data bits = 7 , parity bits 4

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

    c1 = dataafterham[0] ^ dataafterham[2] ^ dataafterham[4] ^ dataafterham[6] ^ dataafterham[8] ^ dataafterham[10];
    c2 = dataafterham[0] ^ dataafterham[1] ^ dataafterham[4] ^ dataafterham[5] ^ dataafterham[8] ^ dataafterham[9];
    c3 = dataafterham[4] ^ dataafterham[5] ^ dataafterham[6] ^ dataafterham[7];
    c4 = dataafterham[0] ^ dataafterham[1] ^ dataafterham[2] ^ dataafterham[3];
    c = c4 * 8 + c3 * 4 + c2 * 2 + c1;

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
        for (i = 0; i < 11; i++)
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
void sender()
{
    char sum[20], complement[20];
    int i, length;
    char a[8];
    char b[8];
    // int n;
    for (int i = 0; i < 2; i++)
    {
        printf("enter the data block\n");
        for (int j = 0; j < 2; j++)
        {
            printf("", b[j]); /* code */
            scanf(" %s", &b[j]);
            scanf("%s", &a[i]);
        }
    }

    if (strlen(a) == strlen(b))
    {
        length = strlen(a);
        char carry = '0';

        for (i = length - 1; i >= 0; i--)
        {
            if (a[i] == '0' && b[i] == '0' && carry == '0')
            {
                sum[i] = '0';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '0' && carry == '1')
            {

                sum[i] = '1';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '1' && carry == '0')
            {
                sum[i] = '1';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '1' && carry == '1')
            {
                sum[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '0' && carry == '0')
            {
                sum[i] = '1';
                carry = '0';
            }
            else if (a[i] == '1' && b[i] == '0' && carry == '1')
            {
                sum[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '1' && carry == '0')
            {
                sum[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '1' && carry == '1')
            {
                sum[i] = '1';
                carry = '1';
            }
            else
                break;
        }

        printf("\nSum=%c%s", carry, sum);
        for (i = 0; i < length; i++)
        {
            if (sum[i] == '0')
                complement[i] = '1';
            else
                complement[i] = '0';
        }

        if (carry == '1')
            carry = '0';
        else
            carry = '1';

        printf("\nChecksum=%c%s", carry, complement);
    }
}
void reciever()
{
    char sum[20], complement[20];
    int i, length;
    char a[8];
    char b[8];
    // int n;
    for (int i = 0; i < 3; i++)
    {
        printf("enter the data block\n");
        for (int j = 0; j < 2; j++)
        {
            printf("", b[j]); /* code */
            scanf(" %s", &b[j]);
            scanf("%s", &a[i]);
        }
    }

    if (strlen(a) == strlen(b))
    {
        length = strlen(a);
        char carry = '0';

        for (i = length - 1; i >= 0; i--)
        {
            if (a[i] == '0' && b[i] == '0' && carry == '0')
            {
                sum[i] = '0';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '0' && carry == '1')
            {

                sum[i] = '1';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '1' && carry == '0')
            {
                sum[i] = '1';
                carry = '0';
            }
            else if (a[i] == '0' && b[i] == '1' && carry == '1')
            {
                sum[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '0' && carry == '0')
            {
                sum[i] = '1';
                carry = '0';
            }
            else if (a[i] == '1' && b[i] == '0' && carry == '1')
            {
                sum[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '1' && carry == '0')
            {
                sum[i] = '0';
                carry = '1';
            }
            else if (a[i] == '1' && b[i] == '1' && carry == '1')
            {
                sum[i] = '1';
                carry = '1';
            }
            else
                break;
        }

        printf("\nSum=%c%s", carry, sum);
        for (i = 0; i < length; i++)
        {
            if (sum[i] == '0')
                complement[i] = '1';
            else
                complement[i] = '0';
        }

        if (carry == '1')
            carry = '0';
        else
            carry = '1';

        printf("\nChecksum=%c%s", carry, complement);
    }
}

void main()
{
    int i, j, keylen, msglen;
    char input[100], key[30], temp[30], quot[100], rem[30], key1[30];
    clrscr();
    printf("Enter Data: ");
    gets(input);
    printf("Enter Key: ");
    gets(key);
    keylen = strlen(key);
    msglen = strlen(input);
    strcpy(key1, key);
    for (i = 0; i < keylen - 1; i++)
    {
        input[msglen + i] = '0';
    }
    for (i = 0; i < keylen; i++)
        temp[i] = input[i];
    for (i = 0; i < msglen; i++)
    {
        quot[i] = temp[0];
        if (quot[i] == '0')
            for (j = 0; j < keylen; j++)
                key[j] = '0';
        else
            for (j = 0; j < keylen; j++)
                key[j] = key1[j];
        for (j = keylen - 1; j > 0; j--)
        {
            if (temp[j] == key[j])
                rem[j - 1] = '0';
            else
                rem[j - 1] = '1';
        }
        rem[keylen - 1] = input[i + keylen];
        strcpy(temp, rem);
    }
    strcpy(rem, temp);
    printf("\nQuotient is ");
    for (i = 0; i < msglen; i++)
        printf("%c", quot[i]);
    printf("\nRemainder is ");
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);
    printf("\nFinal data is: ");
    for (i = 0; i < msglen; i++)
        printf("%c", input[i]);
    for (i = 0; i < keylen - 1; i++)
        printf("%c", rem[i]);
    getch();
}

int main()
{
    int option;
    while (1)
    {
        printf("\n\n1. Send a message.");
        printf("\n2. Check received message.");
        printf("\n3. Exit\n");
        printf("\nEnter your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the size of the bits in the multiples of 4 : ");
            scanf("%d", &data_size);

            if (data_size % 4 != 0)
            {
                printf("\nPlease enter the size of the bits in multiples of 4\n");
                break;
            }

            printf("Enter the  bits : ");
            for (i = 0; i < data_size; i++)
            {
                scanf("%d", &data[i]);
            }

            LRC();

            for (i = 0; i < data_size; i++)
            {
                temp[i] = data[i];
            }

            for (i = 0; i < data_size; i++)
            {
                printf("%d ", temp[i]);
            }

            for (i = 0; i < blocks; i++)
            {
                printf("%d ", parity[i]);
            }

            break;

        case 2:

            printf("Enter the size of the bits (data bits + VRC code bits): ");
            scanf("%d", &data_size);

            printf("Enter the  bits : ");
            for (i = 0; i < data_size; i++)
            {
                scanf("%d", &data[i]);
            }

            if (verify() == 1)
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