#include <stdio.h>
#include "ch7_convchar.h"

int ch7_convchar(enum CASETYPE opt)
{
    int c;
    if (opt==LOWER)
       while((c=getchar())!=EOF)
            putchar(tolower(c));
    else
       while((c=getchar())!=EOF)
            putchar(toupper(c));
    return 0;                               
}
