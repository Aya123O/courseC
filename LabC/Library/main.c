#include <stdio.h>
#include "lib.h"

int main() {
    // Declare test variables
    char test1[10] = "Aya";
    char test2[20] = "osama";
    char test3[10] = "-1xCd";
    char test4[10] = "LALA";
    char emptyStr[1] = "";

    // Test strcat
    printf("\n--- Testing newStract ---\n");
    newStract(test2, test1, 20);
    newStract(test2, test3, 20);
    newStract(test2, test3, 5);


    // Test strlen
    printf("\n--- Testing newStrlen ---\n");
    printf("Length: %d\n", newStrlen(test1));
    printf("Length: %d\n", newStrlen(emptyStr));


    // Test strcmp
    printf("\n--- Testing newStrCmp ---\n");
    printf("Comparison Result: %d\n", newStrCmp(test1, test2));
    printf("Comparison Result: %d\n", newStrCmp(test1, emptyStr));


    // Test uppercase
    printf("\n--- Testing newUpperCase ---\n");
    newUpperCase(test3);


    // Test lowercase
    printf("\n--- Testing newLowerCase ---\n");
    newLowerCase(test4);


    // Test strcpy
    printf("\n--- Testing newStrcp ---\n");
    newStrcp(test1, test3, 10);
    newStrcp(test1, test3, 3);


    return 0;
}
