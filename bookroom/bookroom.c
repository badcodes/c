#include <string.h>
#include <stdio.h>
#include <direct.h>
#include <stdlib.h>
#include <windows.h>

#define MAXROOMNAME 80

typedef struct {
	char name[MAXROOMNAME];
	char folder[_MAX_PATH];
	char book[_MAX_FNAME];
} lib,*plib;

save
