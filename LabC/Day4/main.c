#include <stdio.h>
#define Row 3
#define Col 4

int main() {
    int arr[Row][Col] = {0};
    int sumRow = 0;
    float avgCol = 0.0;


    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Col; j++) {
            int valid = 0;
            while (!valid) {
                printf("Num [%d][%d] => ", i, j);
                if (scanf("%d", &arr[i][j]) == 1) {
                    valid = 1;
                } else {
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n');
                }
            }
        }
    }


    for (int i = 0; i < Row; i++) {
        sumRow = 0;
        for (int j = 0; j < Col; j++) {
            sumRow += arr[i][j];
        }
        printf("The summation of row %d: %d\n", i + 1, sumRow);
    }


    for (int j = 0; j < Col; j++) {
        avgCol = 0;
        for (int i = 0; i < Row; i++) {
            avgCol += arr[i][j];
        }
        printf("The average of column %d: %.2f\n", j + 1, avgCol / Row);
    }

    return 0;
}
