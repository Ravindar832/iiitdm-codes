#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<ctype.h>
char arr_ip[4][4];

int split_ip(const char ip[], char arr_ip[4][4])
{
    char temp[4];
    int count = 0;
    for (int i = 0, j = 0, k = 0; i < strlen(ip); i++)
    {
        if (ip[i] == '.')
        {
            strcpy(arr_ip[j++], temp);
            k = 0;
            bzero(temp, 4);
            count++;
        }
        else
        {
            temp[k] = ip[i];
            k++;
        }
    }
    strcpy(arr_ip[3], temp);
    return count + 1;
}

int ip_valid(char arr_ip[4][4], int count)
{
    if (count > 4)
    {
        return 1;
    }
    int flag = 0;
    for (int i = 0; i < 4; i++)
    {
        if (atoi(arr_ip[i]) < 0 || atoi(arr_ip[i]) > 255)
        {

            flag = 1;
            return flag;
        }
    }
    return flag;
}
int ip_class(char firsByte[])
{
    int n = atoi(firsByte);

    if (n >= 0 && n <= 127)
    {
        printf("-->> Class 'A' IP\n");
        return 1;
    }
    else if (n >= 128 && n <= 191)
    {
        printf("-->> Class 'B' IP\n");
        return 2;
    }
    else if (n >= 192 && n <= 223)
    {
        printf("-->> Class 'C' IP\n");
        return 3;
    }
    else if (n >= 224 && n <= 239)
    {
        printf("-->> Class 'D' IP\n");
        return 4;
    }
    else if (n >= 240 && n <= 255)
    {
        printf("-->> Class 'E' IP\n");
        return 5;
    }
    else
    {
        printf("Invalid IP address\n");
        return -1;
    }
}

void to_Binary(int n)
{
    if (n == 0)
    {
        printf("0");
        return;
    }
    int binaryNum[32];

    int i = 0;
    while (n > 0)
    {

        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binaryNum[j]);
    }
}

void ip_binary(char arr_ip[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        if (i == 1 || i == 2 || i == 3)
            printf(".");

        to_Binary(atoi(arr_ip[i]));
    }
}

int main()
{
    char ip[30];
    printf("\nEnter the IP address: ");

    scanf("%s", ip);

    int count = split_ip(ip, arr_ip);

    int flag = ip_valid(arr_ip, count);
    if (flag == 0)
        printf("Valid IP!!\n");
    else
    {
        printf("Invalid IP!\n");
        exit(0);
    }

    int class = ip_class(arr_ip[0]);

    if (class < 4)
    {
        int sn;
        printf("\nEnter the number of subnets  in power of two: ");
        scanf("%d", &sn);
        if (ceil(log2(sn)) != floor(log2(sn)))
        {
            printf("Please enter the number of subnets in power-of-two");
            exit(0);
        }

        int tip;
        if (class == 1)
        {
            tip = pow(2, 24);
        }
        else if (class == 2)
        {
            tip = pow(2, 16);
        }
        if (class == 3)
        {
            tip = pow(2, 8);
        }

        printf("Total no. of IP addresses = %d\n", tip);

        int totalHost = (tip / sn) - 2;

        printf("Total no. of hosts per subnet = %d\n", totalHost);

        printf("Total no. of hosts in the network = %d\n", ((tip / sn) - 2) * sn);

        printf("\n\nRange of IP addresses:\n");

        printf("Subnet No\tStarting Host\tEnding Host\tDirect Broadcast\tLimited Broadcast\n");

        int noBit = log2(sn);
        int firstRange = 0;
        if (class == 1)
        {
            for (int i = 0; i < sn; i++)
            {
                printf("Subnet %d:\t", i + 1);
                for (int j = 0; j < 1; j++)
                {
                    printf("%s.", arr_ip[j]);
                }
                printf("%d.%d.%d\t", i * 256 / sn, 0, 1);
                for (int j = 0; j < 1; j++)
                {
                    printf("%s.", arr_ip[j]);
                }
                printf("%d.%d.%d\t", (i + 1) * 255 / sn, 255, 254);
                for (int j = 0; j < 1; j++)
                {
                    printf("%s.", arr_ip[j]);
                }
                printf("%d.%d.%d\t\t", (i + 1) * 255 / sn, 255, 255);
                printf("255.255.255.255\n");
            }
        }

        else if (class == 2)
        {
            for (int i = 0; i < sn; i++)
            {
                printf("Subnet %d:\t", i + 1);
                for (int j = 0; j < 2; j++)
                {
                    printf("%s.", arr_ip[j]);
                }
                printf("%d.%d\t", (i * 256 / sn), 1);
                for (int j = 0; j < 2; j++)
                {
                    printf("%s.", arr_ip[j]);
                }
                printf("%d.%d\t", ((i + 1) * 255 / sn), 254);
                for (int j = 0; j < 2; j++)
                {
                    printf("%s.", arr_ip[j]);
                }
                printf("%d.%d\t", ((i + 1) * 255 / sn), 255);
                printf("255.255.255.255\n");
            }
        }
        else if (class == 3)
        {
            //
            for (int i = 0; i < sn; i++)
            {
                printf("Subnet %d:\t", i + 1);
                for (int j = 0; j < 3; j++)
                {
                    printf("%s.", arr_ip[j]);
                }
                printf("%d\t", (i * 256 / sn) + 1);
                for (int j = 0; j < 3; j++)
                {
                    printf("%s.", arr_ip[j]);
                }
                printf("%d\t", ((i + 1) * 255 / sn) - 1);
                for (int j = 0; j < 3; j++)
                {
                    printf("%s.", arr_ip[j]);
                }
                printf("%d\t", ((i + 1) * 255 / sn));
                printf("255.255.255.255\n");
            }
        }
    }
    else
    {
        printf("The network cannot be divided into subnets.\n");
        exit(0);
    }

    return 0;
}