# Project: rview
# Makefile created by Dev-C++ 4.9.9.2

CPP  = g++
CC   = gcc
WINDRES =
RES  = 
OBJ  = rview.o ../[Code]/filesystem.o $(RES)
LINKOBJ  = rview.o ../[Code]/filesystem.o $(RES)
LIBS =  -L"/usr/lib/mingw" -L"/usr/lib"  -lmsvcrt
INCS =  -I"/usr/include/mingw"  -I"/usr/include" 
BIN  = rview
CXXFLAGS = $(CXXINCS)  
CFLAGS = $(INCS)
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before rview all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o "rview.exe" $(LIBS)

rview.o: rview.c
	$(CC) -c rview.c -o rview.o $(CFLAGS)

../[Code]/filesystem.o: ../[Code]/filesystem.c
	$(CC) -c ../[Code]/filesystem.c -o ../[Code]/filesystem.o $(CFLAGS)
