CC = gcc

PACKAGE = tlist
INCSPATH = /myplace/include
LIBSPATH = /myplace/lib
LIBS = xrz
SRCS = list.c

EXESUF = .exe
OBJSUF = .o

OBJS = $(patsubst %.c,%$(OBJSUF),$(SRCS))

CFLAGS += $(patsubst %,-I%,$(INCSPATH))
CFLAGS += $(patsubst %,-L%,$(LIBSPATH))

LKFLAGS += $(patsubst %,-l%,$(LIBS))

CCEXE = $(CC) $(CFLAGS) -o
CCOBJ = $(CC) $(CFLAGS) -c

$(PACKAGE)$(EXESUF) : $(OBJS)
	$(CCEXE) $@ $^ $(LKFLAGS)

clean : 
	- rm *$(OBJSUF)
	- rm *$(EXESUF)

