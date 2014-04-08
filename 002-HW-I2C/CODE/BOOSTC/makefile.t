# Makefile for Boostc test

#--- If neccessary Change these for each program -------------------------------

EXENAME=fb-main-29.exe    # Executable name

EXEDIR=    # Where to put executables

MAINBAS=fb-main-29    # name of main bas file. DO NOT include .bas extension

#-------------------------------------------------------------------------------
EXEFILE=$(EXEDIR)$(EXENAME)

FBC=fbc    # the freebasic compiler. Exe must be in the path
RM=rm      # executable to delete files. Exe must be in the path

INCS=$(wildcard INC/*.bi)
SRCS=$(wildcard SRC/*.bas)
OBJS=$(patsubst SRC/%.bas,OBJ/%.o,$(SRCS))

#FBFLAGS=-g -exx
FBFLAGS=-exx -p LIB

all:$(EXEFILE)

$(EXEFILE):$(OBJS)
	$(FBC) $(FBFLAGS) $(OBJS) -x $(EXEFILE)

OBJ/%.o:SRC/%.bas $(INCS)
	$(FBC) $(FBFLAGS) -m $(MAINBAS) -c $< -o $@

clean:
	$(RM) -f -v $(OBJS)

cleanall:
	$(RM) -f -v $(OBJS)
	$(RM) $(EXEFILE)

