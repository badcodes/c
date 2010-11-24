#include <graph.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <fcntl.h>
#include <share.h>
#include <stdlib.h>
#include "files.h"

#define CPUTS(S) cputs((char _far*)(S))
#define gotoxy(col,row) _settextposition(row,col)
#define OUT_PRINTF_BEGIN sprintf(BUFFER,
#define OUT_PRINTF_END   );_outtext(BUFFER);
#define PRINTF_HEAD gotoxy(1,1);printf
#define PRINTF_FOOT gotoxy(1,COLS);printf
char BUFFER[1024];
char HEAD_BUFFER[81];
char FOOT_BUFFER[81];
//unsigned long PAGES[1024];
unsigned short int ROWS=0;
unsigned short int COLS=0;

int process(int argc,char** argv);
char read_key(void) {
//    cputs("Any key to continue...");
//    while(!_kbhit())
//        ;
    return getch();
}

void set_video_mode(struct videoconfig* out) {
    int mode;
    struct videoconfig vc;
    _getvideoconfig( &vc );
    switch( vc.adapter ) {
    case _VGA :
    case _SVGA :
        mode = _VRES16COLOR;
        break;
    case _MCGA :
        mode = _MRES256COLOR;
        break;
    case _EGA :
        if( vc.monitor == _MONO ) {
            mode = _ERESNOCOLOR;
        } else {
            mode = _ERESCOLOR;
        }
        break;
    case _CGA :
        mode = _MRES4COLOR;
        break;
    case _HERCULES :
        mode = _HERCMONO;
        break;
    default :
        mode = -1;
        cputs( "No graphics adapter\n" );
        break;
    }
    if(mode == -1) {
        _getvideoconfig(out);
    }
    else if(_setvideomode( mode ) ) {
        _getvideoconfig( out );
    }
}
void print_videoconfig(const struct videoconfig* vc) {
    sprintf(BUFFER,"x-axis:%d\ny-axis:%d\ntextcols:%d\ntextrows:%d\ncolors:%d\n"
        "bits:%d\nvideopages:%d\nmode:%d\nadapter:%d\nmonitor:%d\nmemory:%dk\n",
        vc->numxpixels,
        vc->numypixels,
        vc->numtextcols,
        vc->numtextrows,
        vc->numcolors,
        vc->bitsperpixel,
        vc->numvideopages,
        vc->mode,
        vc->adapter,
        vc->monitor,
        vc->memory
        );
    cputs(BUFFER);

}

int main(int argc,char** argv) {
    int old_apage;
    int old_vpage;
    int new_apage;
    int new_vpage;
    struct videoconfig vc;
    int ret;
    if(argc==1) {
        cputs("用法:\n\tcread 文件名\n");
        return 0;
    }

//    set_video_mode(&vc);

//    ROWS=_setvideomoderows(_TEXTC80,_MAXTEXTROWS);
    _getvideoconfig(&vc);
    ROWS = vc.numtextrows;
    COLS = vc.numtextcols;

    old_apage = _getactivepage();
    old_vpage = _getvisualpage();
    if(vc.numvideopages>1) {
        if(old_apage >=1) {
            new_apage = 0;
        }
        else {
            new_apage = 1;
        }
    }
    else {
        new_apage = old_apage;
    }

    if(old_apage != new_apage) {
        _setvisualpage(new_apage);
        _setactivepage(new_apage);
        _clearscreen(_GCLEARSCREEN);
    }

    print_videoconfig(&vc);
    OUT_PRINTF_BEGIN
        "old_visualpage=%d\nold_active_page=%d\n",
        old_vpage,
        old_apage
    OUT_PRINTF_END
    new_vpage = _getvisualpage();
    new_apage = _getactivepage();
    OUT_PRINTF_BEGIN
        "new_visualpage=%d\nnew_active_page=%d\n",
        new_vpage,
        new_apage
    OUT_PRINTF_END

    ret = process(argc,argv); 

    _setactivepage(old_apage);
    _setvisualpage(old_vpage);
//  _setvideomode( _DEFAULTMODE );
    return ret;
}

unsigned short int is_cchar(const int c) {
    if(c<0 || c>127) 
        return 1;
    return 0;
}

#define PRINTF_INFO(S) { \
    struct rccoord old_pos; \
    old_pos = _gettextposition();\
    _settextposition( ROWS,1 );\
    _outtext(S);\
    _settextposition( old_pos.row, old_pos.col );\
}

#define PAGE_BUFFER_SIZE = 1024;

long show_page(FILE* fhnd,const long start) {
    char page_buffer[PAGE_BUFFER_SIZE];
    char* line = malloc(sizeof(char)*COLS+1);
    size_t len_read;
    long next_page = start;
    if(fseek(fhnd,start,SEEK_SET)==0) {
        while(!feof(fhnd)) {
            len_read = fread(fhnd,page_buffer,1,PAGE_BUFFER_SIZE-1);
            next_page
            if(fread(fhnd,page_buffer,PAGE_BUFFER_SIZE-1,1)!=1)
                break;
        }
    }
    else {
        return -1;
    }
    lseek

    do {
    }
    while(_dos_read(handle,BUFFER,1023,&len_read)==0 && len_read>0) {
        int ib =0;
        BUFFER[len_read]=0;
        for(ib=0;ib<len_read;ib++) {
            line[il++]=BUFFER[ib];
            if(BUFFER[ib]>127 && count==0) {
                count=1;
            }
            else {
                count=0;
            }
            if(BUFFER[ib]=='\n') {
                line[il]=0;
                _outtext(line);
                cur++;
                il=0;
            }
            else if(il>=COLS-1) {
                if(count==1) {
                    cleft = line[il-1];
                    line[il-1] = '\n';
                    line[il]=0;
                    _outtext(line);
                    line[0]=cleft;
                    il=1;
                }
                else {
                    line[il++]='\n';
                    line[il++]=0;
                    _outtext(line);
                    line[0]=0;
                    il=0;
                }
                cur++;
            }
            if(cur>=ROWS) {
                read_key();
                _clearscreen(_GCLEARSCREEN);
                sprintf(HEAD_BUFFER,"%-30s",filename);
                PRINTF_INFO(HEAD_BUFFER);
                //gotoxy(1,1);
                cur=2;
            }
        }
    }

}


int process(int argc,char** argv) {
    FILE* fhnd;
    int handle;
    char* filename;
    unsigned len_read;
    unsigned short il = 0;
    unsigned short cur = 0;
    unsigned short ip = 0;
    unsigned short count = 0;
    long fz=0;
    short cleft = 0;
    unsigned char done_read=0;

    read_key();
    _setbkcolor(1);
    _settextcolor(15);
    filename = argv[1];
    _setbkcolor(1);
    _clearscreen(_GCLEARSCREEN);

    fhnd = fopen(filename,"r");
    if(fhnd == NULL) {
           cputs("Unable to open file\n");
           goto exit_process;
    }
    fz = ffilesize(fhnd);
    sprintf(HEAD_BUFFER,"%s\t%Ld bytes",filename,fz);
    PRINTF_INFO(HEAD_BUFFER);

    gotoxy(1,1);
    cur=2;
    PAGES[0]=0;
    PAGES[1] = show_page(fhnd,0);

    line[il++]=0;
    _outtext(line);
    BUFFER[0]=0;
    _dos_close(handle);
exit_process:
    read_key();
    return 0;
}
