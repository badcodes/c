#include <io.h>

long filesize(const int handle) {
    return filelength(handle);
}

long ffilesize(const FILE* fhnd) {
    return filelength(fileno(fhnd));
}

long nfilesize(const char* path) {
    long fz;
    int hnd = open(path,O_RDONLY);
    if(hnd != -1) {
        fz = filelength(hnd);    
        return fz;
    }
    return -1;
}
