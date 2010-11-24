cc=gcc
distdir=X:/Program/Commands

all : echo.exe

clean : 
	rm -v echo.o echo.exe
install :
	mv -v echo.exe $(distdir)/echo.exe
uninstall :
	rm -v $(distdir)/echo.exe
echo.exe : echo.o
	$(cc) echo.o -o echo.exe

echo.o	: echo.c
	$(cc) -c echo.c -o echo.o

echo.c	:


