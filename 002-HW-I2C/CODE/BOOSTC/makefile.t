# Makefile for Boostc test

#--- If neccessary Change these for each program -------------------------------

TARGETNAME=wombat    # Name of targets

TARGETDIR=            # Where to put targets

MAINBAS=fb-main-29    # name of main bas file. DO NOT include .bas extension

#-------------------------------------------------------------------------------
EXEFILE=$(EXEDIR)$(EXENAME)

FBC=fbc    # the freebasic compiler. Exe must be in the path
RM=rm      # executable to delete files. Exe must be in the path

INCS=$(wildcard INC/*.h)
SRCS=$(wildcard SRC/*.cpp)
OBJS=$(patsubst SRC/%.cpp,OBJ/%.o,$(SRCS))

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

