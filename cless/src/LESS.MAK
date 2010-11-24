.AUTODEPEND

#		*Translator Definitions*
CC = bccx +LESS.CFG
TASM = TASM
TLINK = tlinkx


#		*Implicit Rules*
.c.obj:
  $(CC) -c {$< }

#		*List Macros*


EXE_dependencies =  \
  brac.obj \
  ch.obj \
  charset.obj \
  cmdbuf.obj \
  command.obj \
  decode.obj \
  edit.obj \
  filename.obj \
  forwback.obj \
  help.obj \
  ifile.obj \
  input.obj \
  jump.obj \
  line.obj \
  linenum.obj \
  lsystem.obj \
  main.obj \
  mark.obj \
  optfunc.obj \
  option.obj \
  opttbl.obj \
  os.obj \
  output.obj \
  popen.obj \
  position.obj \
  prompt.obj \
  regex.obj \
  screen.obj \
  search.obj \
  setargv.obj \
  signal.obj \
  tags.obj \
  ttyin.obj \
  version.obj \
  wildcard.obj

#		*Explicit Rules*
all: less.exe lesskey.exe

lesskey.exe: less.cfg lesskey.obj
  $(TLINK) /x/c/P-/LC:\BC\LIB c0s.obj lesskey.obj,lesskey,,cs.lib
  lzexe lesskey
  erase lesskey.old

less.exe: less.cfg $(EXE_dependencies)
  $(TLINK) /x/c/P-/LC:\BC\LIB @&&|
c0s.obj+
brac.obj+
ch.obj+
charset.obj+
cmdbuf.obj+
command.obj+
decode.obj+
edit.obj+
filename.obj+
forwback.obj+
help.obj+
ifile.obj+
input.obj+
jump.obj+
line.obj+
linenum.obj+
lsystem.obj+
main.obj+
mark.obj+
optfunc.obj+
option.obj+
opttbl.obj+
os.obj+
output.obj+
popen.obj+
position.obj+
prompt.obj+
regex.obj+
screen.obj+
search.obj+
setargv.obj+
signal.obj+
tags.obj+
ttyin.obj+
version.obj+
wildcard.obj
less
		# no map file
cs.lib
|
  lzexe less
  erase less.old

#		*Individual File Dependencies*
brac.obj: brac.c 

ch.obj: ch.c 

charset.obj: charset.c 

cmdbuf.obj: cmdbuf.c 

command.obj: command.c 

decode.obj: decode.c 

edit.obj: edit.c 

filename.obj: filename.c 

forwback.obj: forwback.c 

help.obj: help.c 

ifile.obj: ifile.c 

input.obj: input.c 

jump.obj: jump.c 

line.obj: line.c 

lesskey.obj: lesskey.c

linenum.obj: linenum.c 

lsystem.obj: lsystem.c 

main.obj: main.c 

mark.obj: mark.c 

optfunc.obj: optfunc.c 

option.obj: option.c 

opttbl.obj: opttbl.c 

os.obj: os.c 

output.obj: output.c 

popen.obj: popen.c 

position.obj: position.c 

prompt.obj: prompt.c 

regex.obj: regex.c 

screen.obj: screen.c 

search.obj: search.c 

setargv.obj: setargv.c 

signal.obj: signal.c 

tags.obj: tags.c 

ttyin.obj: ttyin.c 

version.obj: version.c 

wildcard.obj: wildcard.c

#		*Compiler Configuration File*
less.cfg: less.mak
  copy &&|
-f-
-ff-
-j100
-g0
-O
-Z
-k-
-d
-wpin
-wamb
-wamp
-w-par
-wasm
-wcln
-wdef
-w-pia
-wsig
-wstv
-wucp
-wuse
-IC:\BC\INCLUDE
-LC:\BC\LIB
-DTURBOC
-DMSDOS
-P-.C
| less.cfg


