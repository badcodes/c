#include "compiler.h"


#ifdef __WATCOMC__
#include <stdlib.h>
struct videoconfig _video;
int directvideo;
static char SEARCHPATH_BUFFER[_MAX_PATH];
struct {
    unsigned short o_activepage;
    unsigned short o_visualpage;
//    unsigned short n_activepage;
//    unsigned short n_visualpage;
    unsigned short changed;
} term_stat;

char* searchpath(const char* filename) {
	_searchenv(filename,"PATH",SEARCHPATH_BUFFER);
	return SEARCHPATH_BUFFER;
}
void clreol(void) {
	struct rccoord old_pos;
	int i;
	old_pos = _gettextposition();
	i = old_pos.col;
	_settextposition(old_pos.row,i);
        cprintf("%*s",_video.numtextcols - i ," ");
        /*
	while(i<=_video.numtextcols) {
		i++;
		_outtext(" ");
	}
        */
	_settextposition(old_pos.row,old_pos.col);
}
void init_term() {
    int n=0;
    if(_video.numvideopages>1) {
        term_stat.changed = 1;
        term_stat.o_activepage = _getactivepage();
        term_stat.o_visualpage = _getvisualpage();
        if(term_stat.o_activepage==0) 
            n = 1;
        _setactivepage(n);
        _setvisualpage(n);
    }
}
void deinit_term() {
    if(term_stat.changed) {
        _setactivepage(term_stat.o_activepage);
        _setvisualpage(term_stat.o_visualpage);
    }
}

#include <bios.h>
unsigned short read_keyb() {
	return _bios_keybrd(_KEYBRD_READ);
}
#endif
