#include <stdio.h>
#include <stdlib.h>

int main() {

    int integer_number= 10;
    float float_number = 3.14159;
    char Name = 'A';


    // Using Integer Formate
    printf("Integer: %d\n", integer_number);

    // Using Floating format
    printf("Float: %.2f\n", float_number );
    printf("Float: %.5f\n", float_number );

    //  Using String format
    printf("Name:%c\n", Name);
    //#####################################################################################################

    char ch ;
    printf("Enter character :");
    scanf("%c", &ch);
    printf("char= %c\n", ch);
    printf("Ascii Code = %d\n", ch);
    //####################################################################################################
    int num;


    printf("Enter  integer: ");
    scanf("%d", &num);


    printf("Octal: %o\n", num);

    printf("Hexadecimal: %x\n", num);


    return 0;
}
