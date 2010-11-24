#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define PROMPT printf("%s",">")
#define DEBUGPR(name,value) printf("%s=%.3f\n",(name),(value))
#define PR(n) printf("%-.3f\n",n)
#define NIL '\0'
#define MAXSIZE 1024

typedef char* string;

int getline(string line);

int main()
{
  string line=(string)malloc(MAXSIZE);
  while (PROMPT,gets(line)&& line[0]) {
        char oper=NIL;
        double result=0;
        char *curr=line;
        int begincalc=0;
        while (*curr){
            double value=0;
            double power=1;
            //printf("%s=%c\n","curr",*curr);
            if (*curr=='+' || *curr=='-' || *curr=='*' || *curr=='/'){
               oper=*curr;
               curr++;
               continue;
               }
            else if (*curr && isdigit(*curr)) {
                    while(*curr && isdigit(*curr)){
                        value=10*value+*curr-'0';
                        curr++;
                    }
                    if(*curr=='.'){
                        curr++;           
                        while(*curr && isdigit(*curr)){
                           value=10*value+*curr-'0';
                           power=10*power;           
                           curr++;
                           }
                    value=value/power;   
                    }      
                if (begincalc)
                    switch (oper){
                    case '+':
                             result += value;
                             break;                             
                    case '-':
                             result -= value;
                             break;
                    case '*':
                             result *= value;
                             break;
                    case '/':
                             result /= value;
                             break;
                     }
                else {
                     begincalc=1;
                     result=value;
                     }                                
                 }
              else 
                   curr++;   
        }
        PR(result);
  }
  return 0;
}
