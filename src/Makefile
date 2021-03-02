

CC = g++
CFLAGS = -Wall -g
TARGET = tictactoe

main: main.o tictacfunc.o
	$(CC) $(CFLAGS) -o ../build/$(TARGET) main.o tictacfunc.o
	make clean
main.o: main.cpp tictacfunc.h
	$(CC) $(CFLAGS) -c main.cpp

tictacfunc.o: tictacfunc.h

clean:
	$(RM) *.o $(TARGET)
