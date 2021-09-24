CC = clang
CFLAGS = # -O2
OPTIMIZEDFLAGS = -O2
RM = rm -rf

# Dirs for better organization

SRCDIR = src
BUILDDIR = build
OBJDIR = obj

BINNAME = tictactoe
DEPS = tictacfunc.h
LIBS = -lncurses
# 
MKDIR_P = mkdir -p

all : dirs $(BINNAME)

dirs : 
	$(MKDIR_P) $(OBJDIR) $(BUILDDIR)

$(BINNAME) : $(OBJDIR)/main.o $(OBJDIR)/tictacfunc.o
	$(CC) $(LIBS) -o $(BUILDDIR)/$@ $^ $(CFLAGS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(SRCDIR)/$(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

optimized : $(OBJDIR)/main.o $(OBJDIR)/tictacfunc.o
	$(CC) $(LIBS) -o $(BUILDDIR)/$(BINNAME)-optimized $^ $(OPTIMIZEDFLAGS)


clean : 
	$(RM) *.o $(BUILDDIR) $(OBJDIR)
