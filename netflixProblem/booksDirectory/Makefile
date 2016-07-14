# Makefiles! Make file for book class and test driver
# Author: Tom Morrison

OBJS = Book.o BookTestDriver.o
CPPFLAGS = -Wall -std=c++11
PROG = books
CC = g++

books: $(OBJS)
	$(CC) -o $(PROG) $(OBJS) 
	
Book.o: Book.h Book.cpp
	$(CC) $(CPPFLAGS) -c Book.cpp
	
BookTestDriver.o: BookTestDriver.cpp
	$(CC) $(CPPFLAGS) -c BookTestDriver.cpp
	
clean:
	$(RM) $(PROG) $(OBJS)
