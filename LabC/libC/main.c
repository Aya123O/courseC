#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "lib.h"
typedef struct container{
 char arr[20];

}container;
void displayArr1(char arr[],int size){
arr[1]=10;

}
void displayArr2(container a){
 a.arr[1]=10;

}
/*typedef struct BD{
int day;
int month;
int year;
}BD;

typedef struct Employee{
 char name[100];
 int id;
 int salary;
 BD b;
}Employee;
 void EnterEmployee (Employee e1[],int size){
      for(int i=0;i<2;i++){
     printf("Enter Name");
    scanf("%s",e1[i].name);
    printf(" Enter ID");
    scanf("%d",&e1[i].id);
    printf(" Enter Salary");
    scanf("%d",&e1[i].salary);
    printf(" Enter Birthday");
    scanf("%d %d %d",&e1[i].b.day,&e1[i].b.month,&e1[i].b.year);

}
}
void DisplayEmployee (Employee e1[],int size){
     for(int i=0;i<2;i++){
     printf(" The Name %s\n",e1[i].name);
    printf("The id %d\n",e1[i].id);
    printf("The salary%d\n",e1[i].salary);
    printf(" BirthDay%d\n",e1[i].b.day,e1[i].b.month,e1[i].b.year);



     }
}
*/


int main()
{

    //char str[100]="aya";
   /* Employee e1[2]={0};
    EnterEmployee ( e1,2);
    DisplayEmployee( e1,2);
    */

    //str[1]='l';
    //str[2]='i';
   // printf("the name before copy: %s\n",str);
    //strcpy(str,"ali");
    //printf("the name after copy: %s\n",str);
    //copyString(str,"mostafa",5);
   // printf("%s",str);
  /* printf("%d\n",strcmp("aya","aya"));
   printf("%d\n",strcmp("ali","ahmed"));
   printf("%d\n",strcmp("mostafa","sayed"));
   printf("%d\n",strcmp("Aya","aya"));
   printf("%d\n",strcmp("aya","Aya"))*/
   /*strcat(str," ali");
    printf("%s",str);
    */
    /*strcatString(str," Ahmed");/////////////issue
    printf("%s",str);\*/
    /*char *arr="ali";
    arr[0]='A';
    //printf("%s",arr);
    //scanf("%s",arr);
    printf("%s",arr);
    */
   /* char arr[3][5]={0};
    for (int i=0;i<3;i++){
      printf("Item[%d]",i+1);
      scanf("%s",arr[i]);
    }
     for (int i=0;i<3;i++){
      printf("Item[%d]",i+1);
      printf("%s\n",arr[i]);
    }
*/
/* unsigned int x=0xff00ff00;
 unsigned char *ptr=&x;
printf("%d %d\n",*ptr,x);
printf("%d %d\n",ptr,&x);
printf("size of pointer of char %d\n",sizeof(char *));
printf("size of pointer of integer %d\n",sizeof(int *));
printf( "%d\n",*(ptr+0));
printf("%d\n",*(ptr+1));
printf("%d\n",*(ptr+2));
printf("%x\n",*(ptr+3));
printf("%x\n",*(ptr+0));
printf("%x\n",*(ptr+1));
printf("%x\n",*(ptr+2));
printf("%x\n",*(ptr+3));
printf("******************************************************\n");
for(int i=0;i<4;i++){
printf( "%d\n",*(ptr+i));

}
printf("******************************************************\n");

for(int i=0;i<4;i++){
printf( "%d\n",ptr[i]);

}
printf("******************************************************\n");
*/
char arr[10]={0};
 container a={{0}};
displayArr2(a);
displayArr1(arr,20);



    return 0;
}
