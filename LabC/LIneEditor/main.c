#include <stdio.h>
#include <string.h>
#include "conio.h"
#define RIGHT 67
#define INSERT 126
#define LEFT 68
#define HOME 72
#define END 70


#define RESET_COLOR "\033[0m"
#define GREEN_COLOR "\033[32m"

int main()
{
    char text[100] = {0}; // Buffer to store the text
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

        if (ch == 27) // ESC key (special keys)
        {
            ch = getch();
            if (ch == 91)
            {
                ch = getch();
                if (ch == 50) // Insert key (27 91 50 126)
                {
                    ch = getch(); // Wait for the last byte
                    if (ch == INSERT )
                    {
                        insert_mode = !insert_mode; // Toggle insert mode
                    }
                }
                else if (ch == RIGHT) // Right arrow
                {
                    if (current_pos < index)
                    {
                        current_pos++;
                    }
                }
                else if (ch == LEFT) // Left arrow
                {
                    if (current_pos > 0)
                    {
                        current_pos--;
                    }
                }
                else if (ch == HOME) // Home key
                {
                    current_pos = 0;
                }
                else if (ch == END) // End key
                {
                    current_pos = index;
                }
            }
        }
        else if (ch == '\n') // Enter key
        {
            done = 1;
        }
        else if (ch == 127) // Backspace
        {
            if (current_pos > 0)
            {
                for (int i = current_pos - 1; i < index - 1; i++)
                {
                    text[i] = text[i + 1];
                }
                index--;
                current_pos--;
            }
        }
        else if (ch == 49) // Delete key
        {
            if (current_pos < index)
            {
                for (int i = current_pos; i < index - 1; i++)
                {
                    text[i] = text[i + 1];
                }
                index--;
            }
        }

        else if (index < 100) // Character input
        {
            if (insert_mode)
            {
                for (int i = index; i > current_pos; i--)
                {
                    text[i] = text[i - 1];
                }
                text[current_pos] = ch;
                index++;
                current_pos++;
            }
            else
            {
                text[current_pos] = ch;
                if (current_pos == index)
                {
                    index++;
                }
                current_pos++;
            }
        }

        // Limit bounds
        if (index > 100)
        {
            index = 100;
        }
        if (current_pos > index)
        {
            current_pos = index;
        }

        // Display text
        printf("\r\033[K"); // Clear current line
        for (int i = 0; i < index; i++)
        {
            printf(GREEN_COLOR "%c" RESET_COLOR, text[i]);
        }

        // Ensure cursor is at the correct position even for empty text
        printf("\r");
        for (int i = 0; i < current_pos; i++)
        {
            printf("\033[C"); // Move cursor right
        }

        fflush(stdout);
    }

    text[index] = '\0'; // Null-terminate the string
    printf("\n**********************************\n");
    printf("You entered: " GREEN_COLOR "%s" RESET_COLOR "\n", text);

    return 0;
}
