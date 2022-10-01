// cs20b1085 gugulothu ravindar
// lab7 exercise

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char s[20], c;
    int fg = 0, i = 0;
    printf("\n enter the string ");
    gets(s);
    while (s[i] != '\0')
    {
        switch (fg)
        {
        case 0:
            c = s[i++];
            if (c == 'a')
            {
                fg = 1;
            }
            else if (c == 'b')
            {
                fg = 2;
            }
            else
                fg = 6;
            break;
        case 1:
            c = s[i++];
            if (c == 'a')
            {
                fg = 3;
            }
            else if (c == 'b')
            {

                fg = 4;
            }
            else
                fg = 6;
            break;
        case 2:
            c = s[i++];
            if (c == 'a')
            {
                fg = 6;
            }

            else if (c == 'b')
            {

                fg = 2;
            }
            else
                fg = 6;
            break;
        case 3:
            c = s[i++];
            if (c == 'a')
            {
                fg = 3;
            }
            else if (c == 'b')
            {

                fg = 2;
            }
            else
                fg = 6;
            break;
        case 4:
            c = s[i++];
            if (c == 'a')
            {
                fg = 6;
            }
            else if (c == 'b')
            {

                fg = 5;
            }
            else
                fg = 6;
            break;
        case 5:
            c = s[i++];
            if (c == 'a')
            {
                fg = 6;
            }
            else if (c == 'b')
            {
                fg = 2;
            }
            else
                fg = 6;
            break;
        case 6:
            printf("\n %s is not recognised.", s);
            exit(0);
        }
    }

    if ((fg == 1) || (fg == 3))
    {

        printf("\n %s is accepted under rule 'a*'", s);
    }
    else if ((fg == 2) || (fg == 4))
    {

        printf("\n %s is accepted under rule 'a*b+'", s);
    }
    else if (fg == 5)
        printf("\n %s is accepted under rule 'abb'", s);
}