#include <stdio.h>
#include <stdlib.h>


void gotoxy(int col, int row) {
    printf("\033[%d;%dH", row, col);
}
int main()


{
//Question One
 int size, row, col;


    printf("Please Enter Size: ");
    scanf("%d", &size);


    if (size % 2 == 0 && size >0) {
        printf("Please Enter an Odd Size.\n");
        return 1;
    }

    // Clear the screen
    printf("\033[2J");

    // Initialize the first position
    row = 1; // Row index starts from 1
    col = (size + 1) / 2; // Center column for the first number

    // Display the magic square


    // Place the first number
    gotoxy((col - 1) * 4 + 1, row);
    printf("1");


    for (int num = 2; num <= size * size; num++) {

        int newRow = row - 1;
        int newCol = col - 1;


        if (newRow < 1) newRow = size;
        if (newCol < 1) newCol = size;


        if ((num - 1) % size == 0) {
            newRow = row + 1;
            newCol = col;
        }

        // Update the current position
        row = newRow;
        col = newCol;

        // Move to the calculated position and print the number
        gotoxy((col - 1) * 4 + 1, row); // Adjust column for spacing
        printf("%d ", num);
        fflush(stdout);
        sleep(1);
    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 // Question Two
  /*int num, sum = 0;
    while (sum < 100) {
        printf("Enter a number: ");
        scanf("%d", &num);
        sum += num;
    }

    printf("Sum reached or exceeded 100. Final sum: %d\n", sum);
    return 0;

*/

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Question Three

  /*int item ;
  printf(" our menu \n  1- Menu One \t  2- Menu One \t  3- Menu There \n  ");

  printf("Enter menu Number :");
 scanf("%d",&item);
 switch (item){
  case 1 :
    printf("Menu One");
   break;

 case 2 :
   printf("Menu Two");
   break;


case 3 :
 printf("Menu Three");
 break ;

 default :
 printf("Not Exsist");

 }
 */

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Question FOur

/*for (int i=1; i<=10 ;i++){
printf("Multiplication %d" ,i);
for (int j=1 ;j<=12;j++){
 printf("%d  * %d  =%d \n",i,j,i*j);
  printf("\n");
}
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Question Five

/*for (int i=10 ; i>0 ;i--){
printf("Multiplication %d \n" ,i);
for (int j=1 ;j<=12;j++){
 printf("%d  * %d  =%d \n",i,j,i*j);
  printf("\n");
}
}
*/



    return 0;
}



