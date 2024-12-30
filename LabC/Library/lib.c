
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

// strcat
void newStract(char destination[], char source[], int DestinationSize) {
    if (destination == NULL || source == NULL) {
        printf("Error: NULL input detected.\n");
        return;
    }

    int i = 0, j = 0, k = 0;

    while (destination[i] != '\0') i++;
    while (source[k] != '\0') k++;

    if (DestinationSize - i > k) {
        printf("Valid\n");
        while (source[j] != '\0') {
            destination[i] = source[j];
            j++;
            i++;
        }
        destination[i] = '\0';
        printf("Resulting string: %s\n", destination);
    } else {
        printf("Not valid: Destination size is too small.\n");
    }
}


int newStrlen(char array[]) {
    if (array == NULL) {
        printf("Error: NULL input detected.\n");
        return -1; // Return an error code
    }

    int i = 0;
    while (array[i] != '\0') i++;
    return i;
}


int newStrCmp(char arr1[], char arr2[]) {
    if (arr1 == NULL || arr2 == NULL) {
        printf("Error: NULL input detected.\n");
        return -2; // Error code for NULL inputs
    }

    int i = 0;
    while (arr1[i] != '\0' && arr2[i] != '\0') {
        if (arr1[i] > arr2[i]) return 1;
        if (arr1[i] < arr2[i]) return -1;
        i++;
    }

    if (arr1[i] == '\0' && arr2[i] == '\0') return 0;
    return (arr1[i] == '\0') ? -1 : 1;
}

// uppercase
void newUpperCase(char arr1[]) {
    if (arr1 == NULL) {
        printf("Error: NULL input detected.\n");
        return;
    }

    int j = 0;
    while (arr1[j] != '\0') {
        if (arr1[j] >= 'a' && arr1[j] <= 'z') {
            arr1[j] -= 32;
        }
        j++;
    }
    printf("Uppercase string: %s\n", arr1);
}

// lowercase
void newLowerCase(char arr1[]) {
    if (arr1 == NULL) {
        printf("Error: NULL input detected.\n");
        return;
    }

    int j = 0;
    while (arr1[j] != '\0') {
        if (arr1[j] >= 'A' && arr1[j] <= 'Z') {
            arr1[j] += 32;
        }
        j++;
    }
    printf("Lowercase string: %s\n", arr1);
}

// strcpy
void newStrcp(char target[], char source[], int targetSize) {
    if (target == NULL || source == NULL) {
        printf("Error: NULL input detected.\n");
        return;
    }

    int j = 0;
    while (source[j] != '\0') j++;

    if (targetSize > j) {
        printf("Valid\n");
        for (int i = 0; i <= j; i++) {
            target[i] = source[i];
        }
        printf("Copied string: %s\n", target);
    } else {
        printf("Invalid: Target size is too small.\n");
    }
}
