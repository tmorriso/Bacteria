# Makefiles! Build an executable for the Student Example
# Author: Tom Morrison

#all: Student.cpp StudentDriver.cpp
#	g++ -std=c++11 -o studs Student.cpp StudentDriver.cpp 

OBJS = Student.o StudentDriver.o
CPPFLAGS = -Wall -std=c++11
PROG = studs
CC = g++

studs: $(OBJS)
	$(CC) -o $(PROG) $(OBJS) 
	
Student.o: Student.h Student.cpp
	$(CC) $(CPPFLAGS) -c Student.cpp
	
StudentDriver.o: StudentDriver.cpp
	$(CC) $(CPPFLAGS) -c StudentDriver.cpp
	
clean:
	$(RM) $(PROG) $(OBJS)
	
	
