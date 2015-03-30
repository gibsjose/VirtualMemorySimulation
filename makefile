IDIR =

ifndef CXX
	CXX = g++
endif

CFLAGS = -I$(IDIR) -Wall -g -O0 -std=c++11

ODIR = obj
LDIR = ../lib
LIBS =

BIN = VirtualMemorySimulation

_DEPS =
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Simulation.o Memory.o Process.o PCB.o PageTable.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: setup $(BIN)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

$(BIN): $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean setup

setup:
	@mkdir -p $(ODIR)

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(BIN)
