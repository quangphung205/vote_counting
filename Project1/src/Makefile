CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
OBJS = main.o

all: $(OBJS)
	$(CC) $(LFLAGS) -o sys $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm *.o sys
