#include <stdio.h>

void filecopy(FILE *fpFrom,FILE *fpTo);

int main(int argc,char *argv[])
{
    FILE *f;
    if(argc<2)
        filecopy(stdin,stdout);
    else
        while(--argc){
            argv++;
            if((f=fopen(*argv,"r"))!=NULL){
                filecopy(f,stdout);
                fclose(f);
            }
            else {
                printf("cat:can't open %s\n",*argv);
            }
        }
        return 0;
}

void filecopy(FILE *fpFrom,FILE *fpTo)
{
    int c;
    while((c=fgetc(fpFrom))!=EOF)
        fputc(c,fpTo);
}

