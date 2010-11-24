PROJECT = echox
COPYRIGHT = xiaoranzzz@myplace 2009
APP_NAME := $(PROJECT)
TARGET_OS = dos
PROJECT_TYPE = com
SOURCE_DIR = ..\src
BINARY_DIR = ..\bin\$(TARGET_OS)
DIST_DIR = ..\dist\$(TARGET_OS)
SOURCE_NAMES = $(foreach fn,$(wildcard $(SOURCE_DIR)/*.c),$(notdir $(fn)))
SOURCE_NAMES_TEST = 
LIBS =
LOCAL_PREFIX = \workspace
DIST_INCLUDE = $(foreach fn,$(wildcard $(SOURCE_DIR)/*.h),$(notdir $(fn)))
DIST_SOURCE = 
DIST_BINARY = echox.com
DIST_LIB = 
DIST_FILES = 

SRCE=.c
OBJE=.obj
LIBE=.lib
EXEE=.exe

OBJECT_NAMES := $(SOURCE_NAMES:$(SRCE)=$(OBJE))
#PROJECT := $(BINARY_DIR)\$(PROJECT)
SOURCES := $(addprefix $(SOURCE_DIR)\,$(SOURCE_NAMES))
OBJECTS := $(addprefix $(BINARY_DIR)\,$(OBJECT_NAMES))
OBJLIST_FILE := $(PROJECT).cmd
FILES := $(PROJECT)$(EXEE)

ifeq ($(TARGET_OS),dos)
  FILES += $(PROJECT).com
endif
ifeq ($(PROJECT_TYPE),lib) 
  FILES := $(PROJECT)$(LIBE)
  INSTALL_DIR = $(LOCAL_PREFIX)\lib\$(TARGET_OS)
endif
ifdef INCLUDEDIR
  INCLUDE_DIRS := $(INCLUDEDIR);$(INCLUDEDIR)\$(TARGET_OS)
else
  INCLUDE_DIRS := $(INCLUDEDIR)
endif

ifdef LIBDIR
  LIB_DIRS := $(LIBDIR);$(LIBDIR)\$(TARGET_OS)
else
  LIB_DIRS := $(LIBDIR)
endif

#$(warning -I $(INCLUDE_DIRS) -L $(LIB_DIRS))



CC = wcc
LINK = wlink
LIBER = wlib
LIBFLAGS = -b -c -n -pa -q
CFLAGS = -w4 -e25 -zq 
SMALL_FLAGS = -osxa -zm
FAST_FLAGS = -ot -oi -oe -ol+ -on -or -zm
CFLAGS_DEBUG = -d2 -od -db -dDEBUG=1 
CFLAGS_RELEASE = -ol -oh -dNDEBUG=1 $(SMALL_FLAGS)
LFLAGS_DEBUG = DEBUG ALL
LFLAGS_RELEASE = OP EL
DOS_FLAGS = -bt=dos -ms
NT_FLAGS = -bt=nt -6r -mf
COM_FLAGS = LIBF cstart_t
LINK_CMD_PREFIX = FILE  
LINK_CMD_SUFFIX =
LIB_CMD_PREFIX := +'
LIB_CMD_SUFFIX := '

ifeq ($(TARGET_OS),dos)
  LSYS = SYS DOS
  LOP = maxe=25,q,symf,d
  CFLAGS += $(DOS_FLAGS)
endif
ifeq ($(TARGET_OS),nt)
  CC = wcc386
  LSYS = SYS NT 
  CFLAGS += $(NT_FLAGS)
endif
ifeq ($(TARGET_OS),nt_win)
  CC = wcc386
  LSYS = SYS NT 
  CFLAGS += $(NT_FLAGS)
endif

ifdef LOP
LFLAGS += OP $(LOP)
endif
ifdef LLIBF
LFLAGS += LIBF $(LLIBF)
endif
ifdef LIB_DIRS
LFLAGS += LIBPATH $(LIB_DIRS)
endif
ifdef LIBS
LFLAGS += LIBF $(LIBS)
endif
ifdef INCLUDE_DIRS
CFLAGS += -I$(INCLUDE_DIRS)
endif


vpath %$(SRCE) $(SOURCE_DIR)
vpath %.h $(SOURCE_DIR)
vpath % $(BINARY_DIR)

ECHO = echo \#

ifndef PROJECT
$(error "\"Project\" must be defined!!!")
endif

#DIST_BINARY += $(FILES)

.PHONY: $(PROJECT)
$(PROJECT) : debug

release : CFLAGS += $(CFLAGS_RELEASE)
release : LFLAGS := $(LFLAGS_RELEASE) $(LFLAGS)
release : pre_setup upx 

debug : CFLAGS += $(CFLAGS_DEBUG) 
debug : LFLAGS := $(LFLAGS_DEBUG) $(LFLAGS)
debug : pre_setup $(FILES)

.PHONY : pre_setup
pre_setup : 
	@$(ECHO) perform some cleaning...
	@-mkdir $(BINARY_DIR) 
upx : $(FILES)
	@$(ECHO) compress binary ...
	upx $(addprefix $(BINARY_DIR)\,$(FILES))
#	@echo @echo on>$(BINARY_DIR)\upx.bat
#	@echo $(foreach fn

$(PROJECT).exe : $(OBJECT_NAMES) 
	@echo $(LFLAGS) >$(BINARY_DIR)\linker.opt
	@echo $(foreach fn,$(OBJECTS),$(LINK_CMD_PREFIX)$(fn)$(LINK_CMD_SUFFIX)) >>$(BINARY_DIR)\linker.opt
	@echo OP MAP=$(BINARY_DIR)\$@.map>>$(BINARY_DIR)\linker.opt
	@$(ECHO) linking $@, options used:
	@$(ECHO)     $(LFLAGS) \ 
	@$(ECHO)     $(foreach fn,$(OBJECTS),$(LINK_CMD_PREFIX)$(fn)$(LINK_CMD_SUFFIX)) \ 
	@$(ECHO)     OP MAP=$(BINARY_DIR)\$@.map \ 
	$(LINK) NAME $(BINARY_DIR)\$@ $(LSYS) @$(BINARY_DIR)\linker.opt 
	@$(ECHO) $@ [ OK ]

$(PROJECT).com : $(OBJECT_NAMES)
	@echo $(LFLAGS) >$(BINARY_DIR)\linker.opt
	@echo $(foreach fn,$(OBJECTS),$(LINK_CMD_PREFIX)$(fn)$(LINK_CMD_SUFFIX)) >>$(BINARY_DIR)\linker.opt
	@echo OP MAP=$(BINARY_DIR)\$@.map>>$(BINARY_DIR)\linker.opt
	@echo $(COM_FLAGS)>>$(BINARY_DIR)\linker.opt
	@$(ECHO) linking $@, options used:
	@$(ECHO)     $(LFLAGS) \ 
	@$(ECHO)     $(foreach fn,$(OBJECTS),$(LINK_CMD_PREFIX)$(fn)$(LINK_CMD_SUFFIX)) \ 
	@$(ECHO)     OP MAP=$(BINARY_DIR)\$@.map \ 
	@$(ECHO)     $(COM_FLAGS)
	$(LINK) NAME $(BINARY_DIR)\$@ $(LSYS) COM @$(BINARY_DIR)\linker.opt 
	@$(ECHO) $@ [ OK ]

$(PROJECT)$(LIBE) : $(OBJECT_NAMES)
	@echo $(foreach fn,$(OBJECTS),$(LIB_CMD_PREFIX)$(fn)$(LIB_CMD_SUFFIX) ) >>$(BINARY_DIR)\lib.opt
	@$(ECHO) build library $@, options used:
	@$(ECHO)     $(foreach fn,$(OBJECTS),$(LIB_CMD_PREFIX)$(fn)$(LIB_CMD_SUFFIX) )
	$(LIBER) $(LIBFLAGS) -l=$(BINARY_DIR)\$(PROJECT) $(BINARY_DIR)\$@ @$(BINARY_DIR)\lib.opt
	@$(ECHO) $@ [OK]

%$(OBJE) : %$(SRCE) 
	@echo $(CFLAGS) $(CPPFLAGS) >$(BINARY_DIR)\compiler.opt
	@$(ECHO) compiling $@, options used
	@$(ECHO)     $(CFLAGS) $(CPPFLAGS) 
	$(CC) $(SOURCE_DIR)\$(^F) -fo=$(BINARY_DIR)\$@ @$(BINARY_DIR)\compiler.opt
	@$(ECHO) $@ [OK]

.PHONY: test
test: $(PROJECT).exe
	$(BINARY_DIR)\$(PROJECT).exe
	$(BINARY_DIR)\$(PROJECT).exe abcd
	$(BINARY_DIR)\$(PROJECT).exe a ba ce d 
	$(BINARY_DIR)\$(PROJECT).exe -e
	$(BINARY_DIR)\$(PROJECT).exe -e abcd
	$(BINARY_DIR)\$(PROJECT).exe -e a\tb\tc\nd
		
.PHONY: clean
clean:
	-$(RM) -v $(foreach w,*.cmd *.map *.lib *.mbr *.obj *.exe *.com,$(wildcard $(BINARY_DIR)/$(w)))

.PHONY: list
list:
	ls -l $(BINARY_DIR)
.PHONY: run
run: $(FILES)
	$< "i'm from makefile"

.PHONY: dist dist_dir dist_binary dist_include dist_source dist_lib dist_files
dist: dist_dir dist_binary dist_include dist_source dist_lib dist_files ;
.PHONY: dist_dir
dist_dir:
	$(if $(DIST_DIR),-rm -fdr $(DIST_DIR))
	mkdir $(DIST_DIR)
	mkdir $(DIST_DIR)\bin
	mkdir $(DIST_DIR)\include
	mkdir $(DIST_DIR)\include\$(TARGET_OS)
	mkdir $(DIST_DIR)\lib
	mkdir $(DIST_DIR)\lib\$(TARGET_OS)
	mkdir $(DIST_DIR)\src
dist_binary: $(DIST_BINARY)
#	$(if $(DIST_BINARY), -mkdir $(DIST_DIR)\bin)
	$(if $(DIST_BINARY),-cp -av -- $^ $(DIST_DIR)\bin\)
dist_include: $(DIST_INCLUDE)
	$(if $(DIST_INCLUDE),-mkdir $(DIST_DIR)\include\$(TARGET_OS)\$(APP_NAME))
	$(if $(DIST_INCLUDE),-cp -av -- $^ $(DIST_DIR)\include\$(TARGET_OS)\$(APP_NAME)\)
dist_source: $(DIST_SOURCE)
	$(if $(DIST_SOURCE),-mkdir $(DIST_DIR)\src\$(APP_NAME))
	$(if $(DIST_SOURCE),-cp -av -- $^ $(DIST_DIR)\src\$(APP_NAME)\)
dist_lib: $(DIST_LIB)
	$(if $(DIST_LIB),-cp -av -- $^ $(DIST_DIR)\lib\$(TARGET_OS)\)
dist_files: $(DIST_FILES)
	$(if $(DIST_FILES),cp -av -- $^ $(DIST_DIR)\)

.PHONY: distzip
distzip: dist
	-cd $(DIST_DIR)&&rm -f ..\$(APP_NAME)_$(TARGET_OS).zip&&zip -r9 -X -D ..\$(APP_NAME)_$(TARGET_OS).zip .

.PHONY: install
install: dist 
	$(if $(DIST_DIR),-cd $(DIST_DIR)&&cp -arv * $(LOCAL_PREFIX)\)
	
distclean: clean
	-rm -fdr $(DIST_DIR) $(DIST_DIR)\$(APP_NAME)_$(TARGET_OS).*

	
