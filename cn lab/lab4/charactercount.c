#include <stdio.h>
#include <string.h>
int main()
{
    char data[50], stuff[50], destuff[50];
    int i, j, file_size, no_of_frames, total_frames, data_size, s;

    printf("enter the data :");
    scanf("%s", &data);

    data_size = strlen(data);

    printf("enter file size  :");
    scanf("%d", &file_size);
    s = file_size;

    total_frames = file_size - 1;
    no_of_frames = (data_size / total_frames) + 1;

    j = 0;
    for (i = 0; i < (data_size + no_of_frames); i++)
    {
        if (i % file_size == 0)
        {
            if ((data_size - j) < file_size)
            {
                file_size = data_size - j + 1; /* code */
            }

            stuff[i] = (char)(48 + file_size); /* code */
            file_size = s;
        }
        else
        {
            stuff[i] = data[j];
            j++;
            /* code */
        }

        /* code */
    }
    stuff[data_size + no_of_frames] = '\0';
    printf("stuffed data = %s ", stuff);

    // destuff
    j = 0;
    for (i = 0; i < (data_size + no_of_frames); i++)
    {
        if (i % file_size != 0)
        {
            destuff[j] = stuff[i];
            j++;
        }
    }
    printf("\n\ndestuffed data = %s ", destuff);
    return 0;
}