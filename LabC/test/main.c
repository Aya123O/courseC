#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x=1 ,y=1 ;
   if (y && x++)printf("Hello");
   printf("%d %d \n ",x,y); // 0 0



    return 0;
}
