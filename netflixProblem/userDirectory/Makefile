# Makefile for User Class and test Driver
# Author: Tom Morrison

OBJS = User2.o UserTestDriver.o
CPPFLAGS = -Wall -std=c++11
PROG = user2
CC = g++

user: $(OBJS)
	$(CC) -o $(PROG) $(OBJS) 
	
User.o: User.h User2.cpp
	$(CC) $(CPPFLAGS) -c User2.cpp
	
UserTestDriver.o: UserTestDriver.cpp
	$(CC) $(CPPFLAGS) -c UserTestDriver.cpp
	
clean:
	$(RM) $(PROG) $(OBJS)
