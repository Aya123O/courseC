/*#include <stdio.h>
#include <ctype.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#endif

#define UP 65
#define DOWN 66
#define SIZE 5

// ANSI color codes
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define BLUE_COLOR "\033[34m"
// Function to move the cursor to a specific position
void gotoxy(int x, int y) {
#ifdef _WIN32
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    printf("\033[%d;%dH", y, x);
#endif
}
int getch(void) {
#ifdef _WIN32
    return _getch();
#else
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#endif
}

void displayMenu(int position) {

      printf("\033[H\033[J");
    if (position == 0) {
        printf("%s-> New%s\n", GREEN_COLOR, RESET_COLOR);
    } else {
        printf("   New\n");
    }

    if (position == 1) {
        printf("%s-> Display%s\n", GREEN_COLOR, RESET_COLOR);
    } else {
        printf("   Display\n");
    }

    if (position == 2) {
        printf("%s-> Modify%s\n", GREEN_COLOR, RESET_COLOR);
    } else {
        printf("   Modify\n");
    }

    if (position == 3) {
        printf("%s-> Delete%s\n", GREEN_COLOR, RESET_COLOR);
    } else {
        printf("   Delete\n");
    }

    if (position == 4) {
        printf("%s-> Exit%s\n", GREEN_COLOR, RESET_COLOR);
    } else {
        printf("   Exit\n");
    }
}


int main(void) {
 char ch ; int position=0;

 displayMenu(position);
  while(1){
      ch=getch();
      if(ch==27){
        ch=getch();
        if(ch==91){
         ch=getch();
          if(ch==66){

            position = (position + 1) % SIZE;

          }



        }
           displayMenu(position);


      }


 }

















return 0;





}
*/
