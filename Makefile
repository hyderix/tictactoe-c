CC = clang
CFLAGS = -O2
RM = rm -rf

# Dirs for better organization

SRCDIR = src
BUILDDIR = build
OBJDIR = obj

BINNAME = tictactoe
DEPS = tictacfunc.h
# 
MKDIR_P = mkdir -p

all : dirs $(BINNAME)

dirs : 
	$(MKDIR_P) $(OBJDIR) $(BUILDDIR)

$(BINNAME) : $(OBJDIR)/main.o $(OBJDIR)/tictacfunc.o
	$(CC) -o $(BUILDDIR)/$@ $^ $(CFLAGS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(SRCDIR)/$(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean : 
	$(RM) *.o $(BUILDDIR) $(OBJDIR)
