CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
OBJS = main.o election.o ballot.o candidate.o

all: $(OBJS)
	$(CC) $(LFLAGS) -o execu $(OBJS)

%.o: %.cc
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm *.o execu
