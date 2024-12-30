int sizeOfString (char arr []){
char i=0 ;
while (arr[i]!='\0'){
     i++;
    }
    printf("%d\n",i);
    return i ;
}

void copyString(char des[],char source[],int size){ //size of Destination
  char i=0 ;
  if(sizeOfString(source) <= size-1){
     while (source[i]!='\0'){
     des[i]=source[i];
     i++;
    }

  }else{
   printf("source > Destination");

  }
}
void strcatString(char des[],char source[]){
  char i=0 ,j=0;
  while (des[i]!='\0'){
     i++;
    }
    while (source[j]!='\0'){

     des[i]=source[j];
     i++;
     j++;
    }
    des[i]='\0';
}





