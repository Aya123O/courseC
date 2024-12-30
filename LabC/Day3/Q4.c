#include <stdio.h>

/*int main() {
    int arr[100] = {0};
    int rows, size, col;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the size of Arr (max 100): ");
    scanf("%d", &size);


    if (size > 0 && size <= sizeof(arr) / sizeof(arr[0])) {
        if (rows > 0) {
            col = size / rows;

            printf("Number of rows: %d\n", rows);
            printf("Number of columns: %d\n", col);


            for (int i = 0; i < size; i++) {
                arr[i] = i + 1;
            }


            printf("Array as a table:\n");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < col && (i * col + j) < size; j++) {
                    printf("%d ", arr[i * col + j]);
                }

            }
        } else {
            printf("Invalid number of rows.\n");
        }
    } else {
        printf("Invalid size for the array.\n");
    }

    return 0;
}
*/
