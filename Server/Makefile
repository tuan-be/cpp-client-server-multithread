CFLAGS=-Wall -g 
LDFLAGS=-Wall -g -lpthread

COMPILE=g++ $(CFLAGS) -c
LINK=g++ $(LDFLAGS) -o

SRCDIR=./src
OBJDIR=./obj
#OBJ=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(wildcard $(SRCDIR)/*.cpp))
OBJ=$(OBJDIR)/main.o $(OBJDIR)/mythread.o $(OBJDIR)/server.o $(OBJDIR)/client.o
BINDIR=./bin
BIN=$(BINDIR)/chat


all: $(BIN) 
	# echo "Load all files: $(BIN)"

$(BIN): $(OBJ)
	echo "Link source: $(OBJ)"
	$(LINK) $(BIN) $(OBJ)
# Compile all files .cpp to .o and save at ./obj/
$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp
	# echo "Running comlipe..."
	$(COMPILE) $< -o $@

clean:
	rm -f $(OBJ) $(BIN)


