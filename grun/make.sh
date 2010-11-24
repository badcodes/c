#/bin/sh
gcc -mwindows -Wall grun.c -o grun.exe `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
