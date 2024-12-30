#include <stdio.h>
#include <stdlib.h>
void DisplayArray(int *ptr,int row,int col);


/*typedef struct Emp{
 int age ;

}Emp;
Emp enterstruct(){
Emp e;
printf("Enter your age");
scanf("%d",&e.age);
printf("print Age from Function %d\n",e.age);
return e;
}
void enterstruct2(Emp *e){
printf("Enter your age");
scanf("%d",&((*e).age));
printf("print Age from Function %d\n",(*e).age);

}
*/
/*typedef union data{
   int x;
   float y ;
   char z;


}U;
typedef struct data2{
   int x;
   float y ;
   char z;


}S;
*/

int main()
{
 /*Emp e ;
  enterstruct2(&e);
  printf("%d",e.age);\*/
  /*U t1={0};
  printf("%d\n",sizeof(t1));
  S t2={0};
  printf("%d\n",sizeof(t2));
  t1.y=10.5;
  printf("%f",t1.y);
  */
 /* int arr[10]={1,9,2,3,4,5};
  int *ptr= arr;
  printf("%d\n",*ptr++);
  ptr=arr;
   printf("%d\n",*arr);
  printf("%d\n",*++ptr);
  ptr=arr;
  printf("%d\n",++*ptr);

 /* printf("%d\n",*(arr+1));

  printf("%d\n",*ptr-1);
  *ptr++=5;
  printf("%d \n %d \n %d \n %d \n",ptr,*ptr,arr[0],arr[1]);

*/

/*int arr [2][3]={{1,2,3},{4,5,6}};
DisplayArray(arr,2,3);
void DisplayArray(int *ptr,int row,int col){
 for(int i=0 ;i<6;i++){
  printf("%d",ptr[i]);
 }



}
*/
int x=5 ,y=10 ;
int *ptrx =&x ,*ptry=&y;
printf("%d",*ptrx++);

    return 0;
}
