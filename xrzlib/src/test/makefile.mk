INCS = ../src
LIBS = ../
CFLAGS += -I{$(INCS)}
CFLAGS += -L{$(LIBS)}
CC += $(CFLAGS)

list : tlist.exe

tlist.exe : tlist.obj ; $(CC) -e$@ $< ../xrzlib.lib

tlist.obj : ; $(CC) -otlist.obj -c list.c


clean :  
[ 
    del *.obj 
    del *.exe
]

