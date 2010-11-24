#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

int main(int argc, char *argv[])
{
  char args[1024];
  char append[256];
  int i=1;
  args[0]='\0';
  while(i<argc) {
    strcat(args,"\"");
    strcat(args,argv[i++]);
    strcat(args,"\"");
  }
  strcpy(append,readline());
  if(args[0] && append[0]) {
    strcat(args," ");
    strcat(args,append);
  }
  else if(append[0]) {
       strcpy(args,append);
  }
  if(args[0]) {
       printf("%s\n",args);
       return(system(args));              
  }
  else {
       printf("Usage:%s cmdlines\n",argv[0]);
  }
  return 0;
}

char* readline() {
  char* temp = malloc(256*sizeof(char));
  int i=0;
  int c;
  while(c=getchar()){
    if(c == '\n')
         break;
  //  putchar(c);
    temp[i++]=c;                    
  }
  temp[i]='\0';
  return temp;                        
}
