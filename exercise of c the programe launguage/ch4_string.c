#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define LINDEBUG
#include "..\\linlib\\debug.h"

char *utoa1(unsigned int n,char *s)
{
	char *c;
	if (n>9){
		for (c=utoa1(n/10,s);*c;c++)
			;
		utoa1(n%10,c);					
	}
	else {
		s[0]=n+'0';
		s[1]='\0';
	}
	return s;		
}
int strlen1(const char* s)
{
     char *aux=(char*)s;
     while(*aux++)
        ;
     return aux-s-1;        
 }
char *strcpy1(char *to,const char *from)
{
     char *aux1=to;
     char *aux2=(char*)from;
     while(*aux1++=*aux2++) ;
     return to;
 }
char *strcat1(char *s,const char *a)
{
     char *aux=s+strlen(s);
     strcpy1(aux,a);
     return s;        
 }
int strcmp1(const char *s1,const char *s2)
{
    int i;
    for (i=0;s1[i] && s2[i] && s1[i]==s2[i];i++)
        ;    
    return ((unsigned int)s1[i]-(unsigned int)s2[i]);       
}
int strend1(char *s,const char *test)
{
    int ls=strlen(s);
    int lt=strlen(test);
    if (lt==0) return 1;
    for (;ls>=0 && lt>=0 && s[ls]==test[lt];ls--,lt--)
        ;
    if (lt==-1) return 1;   
    return 0;
} 
char *strncpy1(char *to,const char *from,int count)
{
     char *aux=to;
     while(count--)
         if(!(*to++=*from++))
           return aux;        
     return aux;                
 }
char *strncat1(char *to,const char *from,int count)
{
     char *aux=to;
     while(*to) 
          to++;
     while(count--)     
         if(!(*to++=*from++))
            return aux;
     *to='\0';    
     return aux;
 }
int strncmp1(const char *s1,const char *s2,int count)
{
    if (count<=0) return 0;
    for (;count>0 && *s1==*s2;count--) {
        s1++;
        s2++;
        }
    return (*(unsigned char *)s1-*(unsigned char*)s2);
}

int ch4_string()
{
	char *test=malloc(256);
	debugStr(utoa1(1132,test));
	char *test2="abcdefg";
	debugInt((int)strlen1(test2));
	debugStr(strcat1(test,test2));
	debugStr(strcpy1(test,test2));
	debugInt(strend1(test,"g"));
	debugInt(strcmp1("1","2"));
	debugStr(strncpy1(test,"affgdtwsysgfdgfddsfad",2));
	debugStr(strncat1(test,"ABCDEFG",4));
	debugInt(strncmp1("12","12223",4));
	system("PAUSE");
	return 0;
}
