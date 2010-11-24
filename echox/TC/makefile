#Turbo C  Version 2.01  Copyright (c) 1987, 1988 Borland International
#Syntax is: TCC [ options ] file[s]       * = default; -x- = turn switch x off
#  -1      80186/286 Instructions          -A      Disable non-ANSI extensions
#  -B      Compile via assembly            -C      Allow nested comments
#  -Dxxx   Define macro                    -Exxx   Alternate assembler name
#  -G      Generate for speed              -Ixxx   Include files directory
#  -K      Default char is unsigned        -Lxxx   Libraries directory
#  -M      Generate link map               -N      Check stack overflow
#  -O      Optimize jumps                  -S      Produce assembly output
#  -Uxxx   Undefine macro                  -Z      Optimize register usage
#  -a      Generate word alignment         -c      Compile only
#  -d      Merge duplicate strings         -exxx   Executable file name
#  -f    * Floating point emulator         -f87    8087 floating point
#  -gN     Stop after N warnings           -iN     Maximum identifier length N
#  -jN     Stop after N errors             -k      Standard stack frame
#  -lx     Pass option x to linker         -mc     Compact Model
#  -mh     Huge Model                      -ml     Large Model
#  -mm     Medium Model                    -ms   * Small Model
#  -mt     Tiny Model                      -nxxx   Output file directory
#  -oxxx   Object file name                -p      Pascal calls
#  -r    * Register variables              -u    * Underscores on externs
#  -v      Source level debugging          -w      Enable all warnings
#  -wxxx   Enable warning xxx              -w-xxx  Disable warning xxx
#  -y      Produce line number info        -zxxx   Set segment names

#	Turbo Link  Version 2.0  Copyright (c) 1987, 1988 Borland International
#Syntax:  TLINK objfiles, exefile, mapfile, libfiles
#@xxxx indicates use response file xxxx
#Options: /m = map file with publics
#         /x = no map file at all
#         /i = initialize all segments
#         /l = include source line numbers
#         /s = detailed map of segments
#         /n = no default libraries
#         /d = warn if duplicate symbols in libraries
#         /c = lower case significant in symbols
#         /3 = enable 32-bit processing
#         /v = include full symbolic debug information
#         /e = ignore Extended Dictionary
#         /t = create COM file

CC = tcc
LINK = tlink
ASM = tasm
AFLAGS = /zn /w2
CFLAGS = -1 -DMSDOS -N -M -O -Z -mt -r -w -c -DUSE_WRITE
LFLAGS = /s/l/d/e/t/v/e
PROJECT = echox
SRCDIR = ..\src
BINDIR = ..\bin\dos
SRCS = echox.c arrcpy.c
OBJS = $(SRCS:.c=.obj)
LIBS = cs.lib
LIBPATH = x:\dos\app\tc201\lib
INCLUDE = x:\dos\app\tc201\include
OBJECTS = $(addprefix $(BINDIR)\,$(OBJS))
SOURCES = $(addprefix $(SRCDIR)\,$(SRCS))
CFLAGS += -I$(SRCDIR)

#$(error $(SRCS) : $(OBJS))

.SUFFIX : obj
.SUFFIX : c

vpath .c	$(SRCDIR)
vpath .exe 	$(DSTDIR)
vpath .obj	$(DSTDIR)
vpath .lib	$(LIBPATH)

$(PROJECT).com : $(OBJECTS) 
	echo $(LIBPATH)\c0t.obj+> tlink.cmd
	echo $(OBJECTS)>> tlink.cmd
	echo $(BINDIR)\$(PROJECT)>> tlink.cmd
	echo $(BINDIR)\$(PROJECT).map>> tlink.cmd
	echo $(LIBPATH)\$(LIBS)>> tlink.cmd
	$(LINK)	$(LFLAGS) @tlink.cmd

$(BINDIR)\echox.obj : $(SRCDIR)\echox.c $(MAKEFILE)
	$(CC) $(CFLAGS) -o$@ $<

$(BINDIR)\arrcpy.obj : $(SRCDIR)\arrcpy.c $(MAKEFILE)
	$(CC) $(CFLAGS) -o$@ $<


.PHONY : clean
clean :
	del $(BINDIR)\$(PROJECT).com
	del $(OBJECTS)

.PHONY : list
list :
	command.com /C dir $(BINDIR)
