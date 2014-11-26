ifdef ICC_DEFINED
CC=icpc
else
CC=g++
endif

OBJDIR = $(GARFIELD_HOME)/Object
SRCDIR = $(GARFIELD_HOME)/Source
INCDIR = $(GARFIELD_HOME)/Include
HEEDDIR = $(GARFIELD_HOME)/Heed
LIBDIR = $(GARFIELD_HOME)/Library

# Compiler flags
#CFLAGS = -Wall -Wextra -Wno-long-long \
#	`root-config --cflags` \
#	-O3 -fno-common -c \
#	-I$(INCDIR) -I$(HEEDDIR)

CFLAGS = -Wall -Wextra -Wno-long-long \
          `$(ROOTSYS)/bin/root-config --cflags` \
         -O3 -fno-common -c \
         -I$(INCDIR) -I$(HEEDDIR)

# Debug flags
 CFLAGS += -g

LDFLAGS = `root-config --glibs` -lGeom -lgfortran -lm
LDFLAGS += -L$(LIBDIR) -lGarfield
LDFLAGS += -g
LDFLAGS += `$(ROOTSYS)/bin/root-config --libs` -lThread -lGui

gasfile: example1.C 
	$(CC) $(CFLAGS) example1.C
	$(CC) -o example1 example1.o $(LDFLAGS)
	rm example1.o
