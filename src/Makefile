CC = clang
CFLAGS = -Wall -g -O2
TARGET = tictactoe

all : mainobj tictacfunc
	mkdir ../build/
	$(CC) $(CFLAGS) -o ../build/$(TARGET) main.o tictacfunc.o
	make clean
mainobj : main.c
	$(CC) $(CFLAGS) -c main.c

tictacfunc:
	$(CC) $(CFLAGS) -c tictacfunc.c

clean:
	$(RM) *.o $(TARGET)
