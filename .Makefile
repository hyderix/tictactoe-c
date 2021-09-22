CC = clang
CFLAGS = -O2
RM = rm -rf

# Dirs for better organization

SRCDIR = src
BUILDDIR = build
OBJDIR = obj
BINNAME = tictactoe

MKDIR_P = mkdir -p

all : dir $(OBJDIR)/main.o tictacfunc
	$(CC) $(CFLAGS) -o $(BUILDDIR)/$(BINNAME) main.o tictacfunc.o

$(OBJDIR)/main.o : 
	$(CC) $(CFLAGS) -c $(SRCDIR)/main.c -o $@  # $(OBJDIR)/main.o

$(OBJDIR)/tictacfunc.o :
	$(CC) $(CFLAGS) -c $(SRCDIR)/tictacfunc.c -o $@  # $(OBJDIR)/tictacfunc.o

dir : 
	$(MKDIR_P) $(BUILDDIR) $(OBJDIR)

clean :
	$(RM) *.o
