# Makefile for Sound fun!
PROG = playa
CC = g++
OBJS = player.o
CPPFLAGS = -Wall -std=c++11
LDFLAGS = -lsndfile -lportaudio
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(LDFLAGS) 
player.o : player.cpp
	$(CC) $(CPPFLAGS) -c player.cpp
clean:
	$(RM) $(PROG) $(OBJS)
