#/bin/sh
gcc -Wall ghello.c -o ghello.exe `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
