#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"
#ifdef _WIN32
#include "conio.h"
#else
#include <unistd.h>
#include <termios.h>
#endif
#define RESET_COLOR "\033[0m"
#define GREEN_COLOR "\033[32m"
#define BLUE_COLOR "\033[34m"
#define BACKGROUND_COLOR "\033[44m"

int main()
{
    char text[10] = {0}; // Buffer to store the text
    int index = 0;       // Current number of characters
    int current_pos = 0; // Cursor position
    char ch;
    int done = 0;
    int insert_mode = 0; // Insert mode flag

    printf("**********************************\n");
    printf("Enter Your Message (Max 9 characters):\n");
    printf("**********************************\n");

    while (!done)
    {
        ch = getch();
        // printf("XXX%d\n\n", ch);
        if (ch == 27)
        {   // ESC key (special keys)
            //  printf("27\n");

            ch = getch();
            if (ch == 91)
            {
                //    printf("91\n");

                ch = getch();
                if (ch == 50)
                {                 // Insert key (27 91 50 126)
                    ch = getch(); // Wait for the last byte
                    if (ch == 126)
                    {                               // Insert key
                        insert_mode = !insert_mode; // Toggle insert mode
                    }
                }
                else if (ch == 67)
                { // Right arrow
                    if (current_pos < index)
                    {
                        current_pos++;
                    }
                }
                else if (ch == 68)
                { // Left arrow
                    if (current_pos > 0)
                    {
                        current_pos--;
                    }
                }
                else if (ch == 72)
                { // Home key
                    current_pos = 0;
                }
                else if (ch == 70)
                { // End key
                    current_pos = index;
                }
            }
        }
        else if (ch == '\n')
        { // Enter key
            done = 1;
        }
        else if (ch == 127)
{
    if (current_pos > 0)
    {
        for (int i = current_pos - 1; i < index - 1; i++)
        {
            text[i] = text[i + 1];
        }

        index--;

        current_pos--;
    }else{
        if (insert_mode){
            text[current_pos]='\0';
        }
    }
}

  else if (ch == 49)
{
    if (current_pos < index)
    {
        for (int i = current_pos + 1; i < index; i++)


        {
            text[i] = text[i + 1];
        }




        index--;
    }
}


        else
        {

            if (insert_mode && index < 9)
            {

                for (int i = index; i > current_pos; i--)
                {
                    // text[i] = text[i - 1];
                    // text[current_pos]
                }
                text[current_pos] = ch;
                current_pos++;
            }
            else if (!insert_mode && current_pos < 9)
{

    for (int i = index; i > current_pos; i--)
    {
        text[i] = text[i - 1];
    }

    text[current_pos] = ch;
    current_pos++;


    index++;
}

        }

        if (index > 9)
        {
            index = 9;
        }
        if (current_pos > index)
        {
            current_pos = index;
        }

        printf("\r\033[K");
        for (int i = 0; i < index; i++)
        {
            printf(GREEN_COLOR "%c", text[i]);
        }

        printf("\r");
        for (int i = 0; i < current_pos; i++)
        {
            printf("\033[C");
        }

        fflush(stdout);
    }

    text[index] = '\0';
    printf("************************************************************************************\n");

    printf("\nYou entered: " GREEN_COLOR "%s" RESET_COLOR "\n", text);

    return 0;
}
