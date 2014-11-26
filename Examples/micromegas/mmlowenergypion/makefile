CXX = g++
OBJDIR = $(GARFIELD_HOME)/Object
SRCDIR = $(GARFIELD_HOME)/Source
INCDIR = $(GARFIELD_HOME)/Include
HEEDDIR = $(GARFIELD_HOME)/Heed
LIBDIR = $(GARFIELD_HOME)/Library

# Compiler flags
CFLAGS = `root-config --cflags` -I$(INCDIR) -I$(HEEDDIR) -c

# Debug flags
# CFLAGS += -g

LDFLAGS = -L$(LIBDIR) -lGarfield 
LDFLAGS += -L/usr/local/lib -lgfortran
LDFLAGS += `root-config --glibs` -lGeom

TARGET = main_example

all: $(TARGET).cpp 
	$(CXX) $(CFLAGS) $(TARGET).cpp
	$(CXX) $(TARGET).o $(LDFLAGS) -o $(TARGET)
	rm $(TARGET).o


