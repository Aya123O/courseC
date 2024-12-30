#include <stdio.h>
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

// Function to get a single character without echoing it to the console
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

// Function to clear input buffer
void clearBuffer() {
    while (getchar() != '\n');
}

// Function to display the menu
void DisplayMenu(int currentPostion, int row, int col) {
    printf("\033[H\033[J"); // Clear screen

    // "New" option
    gotoxy(col / 2 - 10, 5);
    printf("*----------------------*");
    gotoxy(col / 2 - 10, 6);
    if (currentPostion == 0) {
        printf("* %s-> New%s           *", GREEN_COLOR, RESET_COLOR);
    } else {
        printf("* %sNew%s              *", BLUE_COLOR, RESET_COLOR);
    }
    gotoxy(col / 2 - 10, 7);
    printf("*----------------------*");

    // "Display" option
    gotoxy(col / 2 - 10, 10);
    printf("*----------------------*");
    gotoxy(col / 2 - 10, 11);
    if (currentPostion == 1) {
        printf("* %s-> Display%s       *", GREEN_COLOR, RESET_COLOR);
    } else {
        printf("* %sDisplay%s          *", BLUE_COLOR, RESET_COLOR);
    }
    gotoxy(col / 2 - 10, 12);
    printf("*----------------------*");

    // "Modify" option
    gotoxy(col / 2 - 10, 15);
    printf("*----------------------*");
    gotoxy(col / 2 - 10, 16);
    if (currentPostion == 2) {
        printf("* %s-> Modify%s        *", GREEN_COLOR, RESET_COLOR);
    } else {
        printf("* %sModify%s          *", BLUE_COLOR, RESET_COLOR);
    }
    gotoxy(col / 2 - 10, 17);
    printf("*----------------------*");

    // "Exit" option
    gotoxy(col / 2 - 10, 20);
    printf("*----------------------*");
    gotoxy(col / 2 - 10, 21);
    if (currentPostion == 3) {
        printf("* %s-> Exit%s          *", GREEN_COLOR, RESET_COLOR);
    } else {
        printf("* %sExit%s             *", BLUE_COLOR, RESET_COLOR);
    }
    gotoxy(col / 2 - 10, 22);
    printf("*----------------------*");
}

struct Employee {
    int code;
    char name[50];
    int salary;
};

// Function to check if the employee code is unique
int isUniqueCode(struct Employee e[], int employeeCount, int code) {
    for (int i = 0; i < employeeCount; i++) {
        if (e[i].code == code) {
            return 0;  // Code is not unique
        }
    }
    return 1;  // Code is unique
}

// Function to modify employee details
void ModifyEmployee(struct Employee e[], int employeeCount) {
    int code, found = 0;

    // Clear screen before modifying
    printf("\033[H\033[J");

    printf("Enter the employee code to modify: ");
    scanf("%d", &code);

    for (int i = 0; i < employeeCount; i++) {
        if (e[i].code == code) {
            found = 1;
            printf("Employee found. Modifying details:\n");

            // Modify Name
            printf("Enter new name for employee: ");
            scanf(" %[^\n]s", e[i].name);

            // Modify Salary
            printf("Enter new salary for employee: ");
            scanf("%d", &e[i].salary);
            break;
        }
    }

    if (!found) {
        printf("%sEmployee code not found.%s\n", RED_COLOR, RESET_COLOR);
    }


    printf("\033[H\033[J");
    printf("Employee details modified. Updated list:\n");

    /*for (int i = 0; i < employeeCount; i++) {
        printf("Employee %d:\n", i + 1);
        printf(" Code: %d\n", e[i].code);
        printf(" Name: %s\n", e[i].name);
        printf(" Salary: %d\n", e[i].salary);
        printf("-----------------------------------------------------\n");
    }
    */

    printf("\nPress Enter to return to the menu...");
    while (getch() != 10);
}

int main(void) {
    int row = 80, col = 100, currentPostion = 0, ch, flag = 1, employeeCount = 0;
    struct Employee e[SIZE] = {{0, "", 0}};

    DisplayMenu(currentPostion, row, col);

    while (flag) {
        ch = getch();
        if (ch == 27) { // Arrow key
            ch = getch();
            if (ch == 91) {
                ch = getch();
                if (ch == UP) {
                    currentPostion = (currentPostion - 1 + 4) % 4;
                } else if (ch == DOWN) {
                    currentPostion = (currentPostion + 1) % 4;
                }
            }
        }

        if (ch == 10) { // Enter key
            if (currentPostion == 0) { // "New" option
                printf("\033[H\033[J");
                gotoxy(col / 2 - 10, 3);
                printf(" %sNew Page%s \n", RED_COLOR, RESET_COLOR);

                // Loop for entering employees
                while (employeeCount < SIZE) {
                    printf("Employee %d:\n", employeeCount + 1);
                    printf("--------------------------------\n");

                    // Validate code for uniqueness
                    int valid = 0;
                    while (!valid) {
                        printf("Enter The Code: ");
                        if (scanf("%d", &e[employeeCount].code) != 1 || e[employeeCount].code <= 0) {
                            printf("%sInvalid Code! Must be a positive number.%s\n", RED_COLOR, RESET_COLOR);
                            clearBuffer();
                        } else if (!isUniqueCode(e, employeeCount, e[employeeCount].code)) {
                            printf("%sError! Code must be unique.%s\n", RED_COLOR, RESET_COLOR);
                            clearBuffer();
                        } else {
                            valid = 1;
                        }
                    }

                    // Validate Name
                    valid = 0;
                    while (!valid) {
                        printf("Enter The Name of Employee: ");
                        scanf(" %[^\n]s", e[employeeCount].name);

                        valid = 1;
                        for (int j = 0; e[employeeCount].name[j] != '\0'; j++) {
                            if (!isalpha(e[employeeCount].name[j]) && e[employeeCount].name[j] != ' ') {
                                valid = 0;
                            }
                        }

                        if (e[employeeCount].name[0] == '\0') {
                            valid = 0;
                        }

                        if (!valid) {
                            printf("%sInvalid Name! Must contain only letters and spaces.%s\n", RED_COLOR, RESET_COLOR);
                        }
                    }


                    valid = 0;
                    while (!valid) {
                        printf("Enter The Salary: ");
                        if (scanf("%d", &e[employeeCount].salary) != 1 || e[employeeCount].salary < 1000 || e[employeeCount].salary > 100000) {
                            printf("%sInvalid Salary! Must be between 1000 and 100000%s\n", RED_COLOR, RESET_COLOR);
                            clearBuffer();
                        } else {
                            valid = 1;
                        }
                    }

                    employeeCount++;
                    if (employeeCount == SIZE) {
                        clearBuffer();
                        printf("Press Enter to go to Menu");
                        ch = getch();
                        printf("-----------------------------------------------------\n");
                    } else {
                        clearBuffer();
                        printf("\n Press Enter to go to Menu, or press '1' to add another employee: ");
                        ch = getch();
                        printf("-----------------------------------------------------\n");
                    }

                    if (ch == 10) {
                        break;
                    } else if (ch == 49) {
                        continue;
                    } else {
                        break;
                    }
                }
            } else if (currentPostion == 1) {
                printf("\033[H\033[J");
                gotoxy(col / 2 - 10, 3);
                printf(" %sDisplay Page%s \n", RED_COLOR, RESET_COLOR);

                // Check if there are employees to display
                if (employeeCount == 0) {
                    printf("No employees to display.\n");
                } else {
                    for (int i = 0; i < employeeCount; i++) {
                        printf("Employee %d:\n", i + 1);
                        printf(" Code: %d\n", e[i].code);
                        printf(" Name: %s\n", e[i].name);
                        printf(" Salary: %d\n", e[i].salary);
                        printf("-----------------------------------------------------\n");
                    }
                }

                printf("\nPress Enter to return to the menu...");
                while (getch() != 10);
            } else if (currentPostion == 2) {
                ModifyEmployee(e, employeeCount);
            } else if (currentPostion == 3) {
                flag = 0;
            }
        }

        if (flag) {
            DisplayMenu(currentPostion, row, col);
        }
    }

    return 0;
}
